using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading.Tasks;
using System.Management;
using System.Runtime.InteropServices;
using System.Threading;
using System.Timers;



namespace Sniffer
{
    public partial class Form1 : Form
    {
        public static byte[] Dataout      = new byte[128];
        public static byte[] Dataoutlen   = new byte[1];
        public static byte   StartCatchPagFlag = 0;          // 按钮控制开始将串口接收到的数据发送到DataGridView
        public static Int32  ReqIndex, LastIndex;            // 显示表索引号
        public static UInt32 TotalPagNumber = 0;             // 界面接收总包数

        public static bool  FilterState = false ;                 // 界面接收总包数
        public static UInt32 LastDestID = 0;                 // 界面接收总包数
        public static Byte  LastCMD = 0;                     // 界面接收总包数
        public UInt16 SendCount = 0;

        public static byte WirelessChannel = 0;             // 无线网络通道

        public System.Timers.Timer Timer1;
        private delegate void FlushClient(); 
        
        Thread thread = null;
        SerialComm SerialCommx;

        bool DeviceTimer3Flag = false;
        bool ShowTimer3Flag = false;
        string CurrentCOM = "";

        public unsafe Form1()
        {
            InitializeComponent();
        }


        delegate void SetTextCallback(string text);
        private void SetText(string text)
        {
            // InvokeRequired required compares the thread ID of the
            // calling thread to the thread ID of the creating thread.
            // If these threads are different, it returns true.
            if (MsgRec.InvokeRequired)
            {
                SetTextCallback d = new SetTextCallback(SetText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                MsgRec.Text = text;
            }
        }

        public enum HardwareEnum
        {
            // 硬件
            Win32_Processor, // CPU 处理器
            Win32_PhysicalMemory, // 物理内存条
            Win32_Keyboard, // 键盘
            Win32_PointingDevice, // 点输入设备，包括鼠标。
            Win32_FloppyDrive, // 软盘驱动器
            Win32_DiskDrive, // 硬盘驱动器
            Win32_CDROMDrive, // 光盘驱动器
            Win32_BaseBoard, // 主板
            Win32_BIOS, // BIOS 芯片
            Win32_ParallelPort, // 并口
            Win32_SerialPort, // 串口
            Win32_SerialPortConfiguration, // 串口配置
            Win32_SoundDevice, // 多媒体设置，一般指声卡。
            Win32_SystemSlot, // 主板插槽 (ISA & PCI & AGP)
            Win32_USBController, // USB 控制器
            Win32_NetworkAdapter, // 网络适配器
            Win32_NetworkAdapterConfiguration, // 网络适配器设置
            Win32_Printer, // 打印机
            Win32_PrinterConfiguration, // 打印机设置
            Win32_PrintJob, // 打印机任务
            Win32_TCPIPPrinterPort, // 打印机端口
            Win32_POTSModem, // MODEM
            Win32_POTSModemToSerialPort, // MODEM 端口
            Win32_DesktopMonitor, // 显示器
            Win32_DisplayConfiguration, // 显卡
            Win32_DisplayControllerConfiguration, // 显卡设置
            Win32_VideoController, // 显卡细节。
            Win32_VideoSettings, // 显卡支持的显示模式。

            // 操作系统
            Win32_TimeZone, // 时区
            Win32_SystemDriver, // 驱动程序
            Win32_DiskPartition, // 磁盘分区
            Win32_LogicalDisk, // 逻辑磁盘
            Win32_LogicalDiskToPartition, // 逻辑磁盘所在分区及始末位置。
            Win32_LogicalMemoryConfiguration, // 逻辑内存配置
            Win32_PageFile, // 系统页文件信息
            Win32_PageFileSetting, // 页文件设置
            Win32_BootConfiguration, // 系统启动配置
            Win32_ComputerSystem, // 计算机信息简要
            Win32_OperatingSystem, // 操作系统信息
            Win32_StartupCommand, // 系统自动启动程序
            Win32_Service, // 系统安装的服务
            Win32_Group, // 系统管理组
            Win32_GroupUser, // 系统组帐号
            Win32_UserAccount, // 用户帐号
            Win32_Process, // 系统进程
            Win32_Thread, // 系统线程
            Win32_Share, // 共享
            Win32_NetworkClient, // 已安装的网络客户端
            Win32_NetworkProtocol, // 已安装的网络协议
            Win32_PnPEntity,//all device
        }
        /// <summary>
        /// WMI取硬件信息
        /// </summary>
        /// <param name="hardType"></param>
        /// <param name="propKey"></param>
        /// <returns></returns>
        private static string[] GetHarewareInfo(HardwareEnum hardType, string propKey)
        {

            List<string> strs = new List<string>();
            try
            {
                using (ManagementObjectSearcher searcher = new ManagementObjectSearcher("select * from " + hardType))
                {
                    var hardInfos = searcher.Get();
                    foreach (var hardInfo in hardInfos)
                    {
                        if (hardInfo.Properties[propKey].Value != null)
                        {
                            String str = hardInfo.Properties[propKey].Value.ToString();
                            if (str.Contains("COM"))
                            {
                                strs.Add(str);
                            }
                        }
                    }
                }
                return strs.ToArray();
            }
            catch
            {
                MessageBox.Show("硬件端口查找错误", "程序猿的提示", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return null;
            }
            finally
            {
                strs = null;
            }
        }//end of func GetHarewareInfo().
        //通过WMI获取COM端口
        protected override void WndProc(ref Message m)
        {
            const int WM_DEVICECHANGE = 0x219;
            if (m.Msg == WM_DEVICECHANGE)
            {
                timer3.Interval = 100;
                timer3.Enabled = true;
                DeviceTimer3Flag = true;

            }
            base.WndProc(ref m); //将系统消息传递自父类的WndProc
        }
        
        unsafe private void Form1_Load(object sender, EventArgs e)
        {
            //Sniffer.MyQueue.QueueInit();
            //Thread.Sleep(100);
            SerialCommx = new SerialComm(this.serialPort1,MsgRec);

            //MsgRec = new TextBox()
            //SerialCommx.SeriaInit();
            
            // 增加线程用于将FIFO数据压出并显示在datagridview中
            //thread = new Thread(UpdataDataGridViewValue);
            //thread.IsBackground = true;
            //thread.Start();

            // 测试定时器，让定时器定时刷新界面中的一个文本框显示时间周期增加
            // Timer1 = new System.Timers.Timer(200);
            // Timer1.Elapsed  += new System.Timers.ElapsedEventHandler(Timer1Out);   // 到达时间的时候执行事件； 
            // Timer1.AutoReset = true;                                               // 设置是执行一次（false）还是一直执行(true)； 
            // Timer1.Enabled   = true;                                               // 是否执行System.Timers.Timer.Elapsed事件

            DeviceAddress.Text = "21000001";
            NetworkAddress.Text = "1000";
            RFChannel.Text = "10";
            TXPower.Text = "5";
            BandWidth.Text = "9";
            SpreadFactor.Text = "7";

            RefreshComList();
            
            //comboBox1.SelectedIndex = 1;
            toolStripStatusLabel2.Text = "发送的数据帧数：" + Convert.ToString(SendCount);
            ShowMessage("界面初始化成功",3000);
            button2.Enabled = false;
            this.MinimumSize = new Size(781, 530);　　
            //this.Close();
            //toolStripStatusLabel2.RightToLeft = RightToLeft.Yes;
        }
        protected void RefreshComList()
        {
            string[] str = GetHarewareInfo(HardwareEnum.Win32_PnPEntity, "Name");//获取全部驱动名称
            //foreach (string vPortName in SerialPort.GetPortNames())
            try
            {
                comboBox1.Items.Clear();
                for (byte i = 0; i < str.Length; i++)
                {
                    //this.comboBox1.Text =  vPortName ;
                    comboBox1.Items.Add(str[i]);
                }
            }
            catch (Exception)
            {
                ShowMessage("没有可用端口", 1000);
            }
            this.Refresh();
        }
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(button2.Text == "停止发送")
            {
                button2.Text = "配置发送";
                timer2.Enabled = false;
            }
            


            string comPortName;
            string TempByte;
            string ConstByte = "-";
            int startIndex = comboBox1.SelectedItem.ToString().LastIndexOf("(");
            int endIndex = comboBox1.SelectedItem.ToString().LastIndexOf(")");
            if ((endIndex-startIndex)>5)
            {
                TempByte = comboBox1.SelectedItem.ToString().Substring(startIndex + 6, 1);
                  if (TempByte == ConstByte)
                {
                   comPortName  = comboBox1.SelectedItem.ToString().Substring(startIndex + 1, 5);
                }
                else
                {
                    comPortName = comboBox1.SelectedItem.ToString().Substring(startIndex + 1, 4);
                }
            }
            else
            {
               comPortName  = comboBox1.SelectedItem.ToString().Substring(startIndex + 1, 4);
            }
            if (SerialCommx.SeriaInit(comPortName))
            {
                ShowMessage(SerialCommx.GetPortName() + "已打开", 1000);
                button2.Enabled = true;
            }
            else
            {
                ShowMessage(SerialCommx.GetPortName() + "未打开",1000);
                button2.Enabled = false;
            }
            CurrentCOM = comboBox1.SelectedItem.ToString();
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (thread != null)
                thread.Abort();
        }
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            this.Text = "1111";
        }
        private void button2_Click(object sender, EventArgs e)
        {
            if(button2.Text == "配置发送")
            {
                timer2.Interval = 500;
                timer2.Enabled = true;
                button2.Text = "停止发送";
            }
            else
            {
                button2.Text = "配置发送";
                timer2.Enabled = false;
            }
        }
        private void MsgRec_TextChanged(object sender, EventArgs e)
        {
            //MsgRec.Focus();//获取焦点
            ///MsgRec.Select(0, 0);//光标定位到文本最后
            //MsgRec.ScrollToCaret();
            ShowMessage("接受到数据", 1000);
        }

        private void ClearRX_Click(object sender, EventArgs e)
        {
            MsgRec.Text = "";
            SendCount = 0;
            toolStripStatusLabel2.Text = "发送的数据帧数：" + Convert.ToString(SendCount);
        }
        Byte[] CRC8Table =
        {  
            0, 94, 188, 226, 97, 63, 221, 131, 194, 156, 126, 32, 163, 253, 31, 65,  
            157, 195, 33, 127, 252, 162, 64, 30, 95, 1, 227, 189, 62, 96, 130, 220,  
            35, 125, 159, 193, 66, 28, 254, 160, 225, 191, 93, 3, 128, 222, 60, 98,  
            190, 224, 2, 92, 223, 129, 99, 61, 124, 34, 192, 158, 29, 67, 161, 255,  
            70, 24, 250, 164, 39, 121, 155, 197, 132, 218, 56, 102, 229, 187, 89, 7,  
            219, 133, 103, 57, 186, 228, 6, 88, 25, 71, 165, 251, 120, 38, 196, 154,  
            101, 59, 217, 135, 4, 90, 184, 230, 167, 249, 27, 69, 198, 152, 122, 36,  
            248, 166, 68, 26, 153, 199, 37, 123, 58, 100, 134, 216, 91, 5, 231, 185,  
            140, 210, 48, 110, 237, 179, 81, 15, 78, 16, 242, 172, 47, 113, 147, 205,  
            17, 79, 173, 243, 112, 46, 204, 146, 211, 141, 111, 49, 178, 236, 14, 80,  
            175, 241, 19, 77, 206, 144, 114, 44, 109, 51, 209, 143, 12, 82, 176, 238,  
            50, 108, 142, 208, 83, 13, 239, 177, 240, 174, 76, 18, 145, 207, 45, 115,  
            202, 148, 118, 40, 171, 245, 23, 73, 8, 86, 180, 234, 105, 55, 213, 139,  
            87, 9, 235, 181, 54, 104, 138, 212, 149, 203, 41, 119, 244, 170, 72, 22,  
            233, 183, 85, 11, 136, 214, 52, 106, 43, 117, 151, 201, 74, 20, 246, 168,  
            116, 42, 200, 150, 21, 75, 169, 247, 182, 232, 10, 84, 215, 137, 107, 53  
        };  

          Byte CRC8(Byte[] p, Byte counter)  
        {
             Byte Ch = 0;  
             for(Byte i=0 ; counter > 0; counter--)
             {  
                Ch = CRC8Table[Ch^p[i]];  
                i++;  
             }  
             return(Ch);
        }

          public void timer2_Tick(object sender, EventArgs e)
          {
              
              byte[] sbuff = new byte[16];
              if (SerialCommx.SerialIsOpen())
              {
                  if ((DeviceAddress.Text != "") && (NetworkAddress.Text != "") && (RFChannel.Text != "") &&
                      (TXPower.Text != "") && (BandWidth.Text != "") && (SpreadFactor.Text != ""))
                  {
                      sbuff[0] = 0x43;
                      sbuff[1] = 0x46;

                      sbuff[2] = 0x01;
                      sbuff[3] = 0x0C;

                      sbuff[4] = (byte)(Convert.ToUInt32(DeviceAddress.Text) % 256);
                      sbuff[5] = (byte)(Convert.ToUInt32(DeviceAddress.Text) / 256 % 256);
                      sbuff[6] = (byte)(Convert.ToUInt32(DeviceAddress.Text) / 256 / 256 % 256);
                      sbuff[7] = (byte)(Convert.ToUInt32(DeviceAddress.Text) / 256 / 256 / 256 % 256);

                      sbuff[8] = (byte)(Convert.ToUInt16(NetworkAddress.Text) % 256);
                      sbuff[9] = (byte)(Convert.ToUInt16(NetworkAddress.Text) / 256 % 256);

                      sbuff[10] = (byte)(Convert.ToUInt16(RFChannel.Text));
                      sbuff[11] = (byte)(Convert.ToUInt16(TXPower.Text));
                      sbuff[12] = (byte)(Convert.ToUInt16(BandWidth.Text));
                      sbuff[13] = (byte)(Convert.ToUInt16(SpreadFactor.Text));
                      sbuff[14] = 0x00;
                      sbuff[15] = CRC8(sbuff, 15);

                      SerialCommx.SeriaWrite(sbuff, 16);
                      SendCount++;
                      toolStripStatusLabel2.Text = "发送的数据帧数：" + Convert.ToString(SendCount);
                  }
                  else
                  {
                      ShowMessage("数据未填写完整", 3000); 
                  }
              }
              else
              {
                  ShowMessage("端口未打开，请打开端口再发送",1000); 
              }
          }
          private void timer3_Tick(object sender, EventArgs e)
          {
              if (DeviceTimer3Flag)
              {
                  DeviceTimer3Flag = false;
                  RefreshComList();
                  timer3.Enabled = false;
                  this.comboBox1.SelectedIndex = -1;
                  
              }
              if(ShowTimer3Flag)
              {
                  ShowTimer3Flag = false;
                  timer3.Enabled = false;
                  toolStripStatusLabel4.Text = "";
              }
              
          }
          protected void ShowMessage(string Message, UInt16 TimeInterval)
          {
              toolStripStatusLabel4.Text = Message;
              timer3.Interval = TimeInterval;
              timer3.Enabled = true;
              ShowTimer3Flag = true;
          }

          private void Form1_Resize(object sender, EventArgs e)
          {
              this.MinimumSize = new Size(781,530);　　
          }
    }
}
