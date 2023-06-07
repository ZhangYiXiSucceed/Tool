using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;
using System.Timers;
using System.IO.Ports;


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

        public static byte WirelessChannel = 0;             // 无线网络通道

        public System.Timers.Timer Timer1;
        private delegate void FlushClient(); 
        
        Thread thread = null;
        SerialComm SerialCommx;
        
        public unsafe Form1()
        {
            InitializeComponent();
        }
        
        unsafe private void Form1_Load(object sender, EventArgs e)
        {
            Sniffer.MyQueue.QueueInit();
            Thread.Sleep(100);
            SerialCommx = new SerialComm(this.serialPort1);
            //SerialCommx.SeriaInit();
            
            // 增加线程用于将FIFO数据压出并显示在datagridview中
            thread = new Thread(UpdataDataGridViewValue);
            thread.IsBackground = true;
            thread.Start();

            // 增加线程用于将FIFO数据压出并显示在datagridview中
            // thread = new Thread(SerialCommx.UartThread);
            // thread.IsBackground = true;
            // thread.Start();

            // 测试定时器，让定时器定时刷新界面中的一个文本框显示时间周期增加
            // Timer1 = new System.Timers.Timer(200);
            // Timer1.Elapsed  += new System.Timers.ElapsedEventHandler(Timer1Out);   // 到达时间的时候执行事件； 
            // Timer1.AutoReset = true;                                               // 设置是执行一次（false）还是一直执行(true)； 
            // Timer1.Enabled   = true;                                               // 是否执行System.Timers.Timer.Elapsed事件

            foreach (string vPortName in SerialPort.GetPortNames())
            {
                //this.comboBox1.Text =  vPortName ;
                comboBox1.Items.Add(vPortName);
            }

        }

        public void UpdataDataGridViewValue()
        {
            while (1 == 1)
            {
                if (StartCatchPagFlag == 1)
                {
                    // 将sleep和无限循环放在等待同步的外面
                    if (MyQueue.QueueOut(Dataout, Dataoutlen) == MyQueue.QueueOperateOk)
                    {
                        UpdataValue();
                    }
                }
                Thread.Sleep(1);                                    // 线程休眠，让出CPU给主线程或者定时器使用
            }
        }

        public void UpdataValue()
        { 
            if (this.dataGridView1.InvokeRequired)                  // 等待异步
            {
                FlushClient fc = new FlushClient(UpdataValue);
                this.Invoke(fc);                                    // 通过代理调用刷新方法
            }
            else                                                    // 可操作
            {
                AddOneDataToDispBuff(Dataout);            // Sniffer.MyQueue.testdata0);
                TotalPagNumber = TotalPagNumber + 1;
            }
            
        }

        public void Timer1Out(object source, System.Timers.ElapsedEventArgs e)
        {
            try
            {
                this.Invoke(new EventHandler(delegate
                {
                    this.textBox1.Text = TotalPagNumber.ToString();
                    if ((ReqIndex != 0)&&(LastIndex != ReqIndex))  // 当前行索引不等于0并且当前索引与上次索引不同才更新到当前行
                    {
                        this.dataGridView1.FirstDisplayedScrollingRowIndex = ReqIndex ;         // ReqIndex只有在添加行以后有效
                        this.dataGridView1.Rows[ReqIndex].Selected = true;                      // 设置为选中
                        LastIndex = ReqIndex;
                    }
                }));
            }
            catch
            {

            }
        }

        //LastCMD LastDestID FilterState
        public unsafe void AddOneDataToDispBuff( byte[] indata)
        {
            int indexx;
            //indexx = this.dataGridView1.Rows.Add();
            Byte   Highbyteseq = 7;                      // 常量偏移地址，FCF高字节在数组中的位置
            Byte   fcfhighbyte = indata[Highbyteseq];
            switch (fcfhighbyte)
            {
                case 0x08:  // 无源地址，目标短地址
                    STR_MACFrameGG sMACFramesGG;
                    sMACFramesGG = (STR_MACFrameGG)Program.BytesToStruct(indata, typeof(STR_MACFrameGG));
                    if ( FilterState == true)
                    {
                        if (LastCMD != sMACFramesGG.cmd)
                        {
                            ReqIndex = this.dataGridView1.Rows.Add();
                            indexx = ReqIndex;
                            this.dataGridView1.Rows[indexx].Cells["Column1"].Value = sMACFramesGG.time.ToString("D8");
                            this.dataGridView1.Rows[indexx].Cells["Column2"].Value = "0x" + sMACFramesGG.fcf.ToString("X4");
                            this.dataGridView1.Rows[indexx].Cells["Column3"].Value = sMACFramesGG.seq.ToString("D3");
                            this.dataGridView1.Rows[indexx].Cells["Column4"].Value = sMACFramesGG.dstpan.ToString("D5");
                            this.dataGridView1.Rows[indexx].Cells["Column5"].Value = sMACFramesGG.dstadd.ToString("D5");
                            this.dataGridView1.Rows[indexx].Cells["Column7"].Value = sMACFramesGG.len.ToString("D2");
                            this.dataGridView1.Rows[indexx].Cells["Column8"].Value = sMACFramesGG.batt.ToString("D2");
                            this.dataGridView1.Rows[indexx].Cells["Column9"].Value = sMACFramesGG.pagnum.ToString("D4");
                            this.dataGridView1.Rows[indexx].Cells["Column10"].Value = sMACFramesGG.cmd.ToString("D2");
                            for (Byte ii = 0; ii < sMACFramesGG.len; ii++)
                                this.dataGridView1.Rows[indexx].Cells["Column11"].Value = this.dataGridView1.Rows[indexx].Cells["Column11"].Value + " " + sMACFramesGG.data[ii].ToString("X2");
                            this.dataGridView1.Rows[indexx].Cells["Column12"].Value = sMACFramesGG.lqi.ToString("D3");
                            if (sMACFramesGG.crcending == 1)
                                this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "ok";
                            else
                                this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "err";
                            LastCMD = sMACFramesGG.cmd;
                        }
                        LastDestID = 0;
                    }
                    else 
                    {
                        ReqIndex = this.dataGridView1.Rows.Add();
                        indexx = ReqIndex;
                        this.dataGridView1.Rows[indexx].Cells["Column1"].Value = sMACFramesGG.time.ToString("D8");
                        this.dataGridView1.Rows[indexx].Cells["Column2"].Value = "0x" + sMACFramesGG.fcf.ToString("X4");
                        this.dataGridView1.Rows[indexx].Cells["Column3"].Value = sMACFramesGG.seq.ToString("D3");
                        this.dataGridView1.Rows[indexx].Cells["Column4"].Value = sMACFramesGG.dstpan.ToString("D5");
                        this.dataGridView1.Rows[indexx].Cells["Column5"].Value = sMACFramesGG.dstadd.ToString("D5");
                        this.dataGridView1.Rows[indexx].Cells["Column7"].Value = sMACFramesGG.len.ToString("D2");
                        this.dataGridView1.Rows[indexx].Cells["Column8"].Value = sMACFramesGG.batt.ToString("D2");
                        this.dataGridView1.Rows[indexx].Cells["Column9"].Value = sMACFramesGG.pagnum.ToString("D4");
                        this.dataGridView1.Rows[indexx].Cells["Column10"].Value = sMACFramesGG.cmd.ToString("D2");
                        for (Byte ii = 0; ii < sMACFramesGG.len; ii++)
                            this.dataGridView1.Rows[indexx].Cells["Column11"].Value = this.dataGridView1.Rows[indexx].Cells["Column11"].Value + " " + sMACFramesGG.data[ii].ToString("X2");
                        this.dataGridView1.Rows[indexx].Cells["Column12"].Value = sMACFramesGG.lqi.ToString("D3");
                        if (sMACFramesGG.crcending == 1)
                            this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "ok";
                        else
                            this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "err";
                    }
                    
                    break;
                case 0xC8:  // 源长地址，目标短地址
                    STR_MACFrameSG sMACFramesSG;
                    sMACFramesSG = (STR_MACFrameSG)Program.BytesToStruct(indata, typeof(STR_MACFrameSG));
                    ReqIndex = this.dataGridView1.Rows.Add();
                    indexx = ReqIndex;
                    this.dataGridView1.Rows[indexx].Cells["Column1"].Value = sMACFramesSG.time.ToString("D8");
                    this.dataGridView1.Rows[indexx].Cells["Column2"].Value = "0x" + sMACFramesSG.fcf.ToString("X4");
                    this.dataGridView1.Rows[indexx].Cells["Column3"].Value = sMACFramesSG.seq.ToString("D3");
                    this.dataGridView1.Rows[indexx].Cells["Column4"].Value = sMACFramesSG.dstpan.ToString("D5");
                    this.dataGridView1.Rows[indexx].Cells["Column5"].Value = sMACFramesSG.dstadd.ToString("D5");
                    this.dataGridView1.Rows[indexx].Cells["Column6"].Value = (sMACFramesSG.srcadd % 1000000).ToString("D5");
                    this.dataGridView1.Rows[indexx].Cells["Column7"].Value = sMACFramesSG.len.ToString("D2");
                    this.dataGridView1.Rows[indexx].Cells["Column8"].Value = sMACFramesSG.batt.ToString("D2");
                    this.dataGridView1.Rows[indexx].Cells["Column9"].Value = sMACFramesSG.pagnum.ToString("D4");
                    this.dataGridView1.Rows[indexx].Cells["Column10"].Value = sMACFramesSG.cmd.ToString("D2");
                    for (Byte ii = 0; ii < sMACFramesSG.len; ii++)
                        this.dataGridView1.Rows[indexx].Cells["Column11"].Value = this.dataGridView1.Rows[indexx].Cells["Column11"].Value + " " + sMACFramesSG.data[ii].ToString("X2");
                    this.dataGridView1.Rows[indexx].Cells["Column12"].Value = sMACFramesSG.lqi.ToString("D3");
                    //this.dataGridView1.Rows[indexx].Cells["Column13"].Value = sMACFramesSG.crcending.ToString("D1");
                    if (sMACFramesSG.crcending == 1)
                        this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "ok";
                    else
                        this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "err";
                    break;
                case 0x8C:  // 源短地址，目标长地址
                    STR_MACFrameGS sMACFrameGS;
                    sMACFrameGS = (STR_MACFrameGS)Program.BytesToStruct(indata, typeof(STR_MACFrameGS));
                    if (FilterState == true)
                    {
                        if (LastDestID != (UInt32)(sMACFrameGS.dstadd))
                        {
                            ReqIndex = this.dataGridView1.Rows.Add();
                            indexx = ReqIndex;
                            this.dataGridView1.Rows[indexx].Cells["Column1"].Value = sMACFrameGS.time.ToString("D8");
                            this.dataGridView1.Rows[indexx].Cells["Column2"].Value = "0x" + sMACFrameGS.fcf.ToString("X4");
                            this.dataGridView1.Rows[indexx].Cells["Column3"].Value = sMACFrameGS.seq.ToString("D3");
                            this.dataGridView1.Rows[indexx].Cells["Column4"].Value = sMACFrameGS.dstpan.ToString("D5");
                            this.dataGridView1.Rows[indexx].Cells["Column5"].Value = (sMACFrameGS.dstadd % 1000000).ToString("D5");
                            this.dataGridView1.Rows[indexx].Cells["Column6"].Value = sMACFrameGS.srcadd.ToString("D5");
                            this.dataGridView1.Rows[indexx].Cells["Column7"].Value = sMACFrameGS.len.ToString("D2");
                            this.dataGridView1.Rows[indexx].Cells["Column8"].Value = sMACFrameGS.batt.ToString("D2");
                            this.dataGridView1.Rows[indexx].Cells["Column9"].Value = sMACFrameGS.pagnum.ToString("D4");
                            this.dataGridView1.Rows[indexx].Cells["Column10"].Value = sMACFrameGS.cmd.ToString("D2");
                            for (Byte ii = 0; ii < sMACFrameGS.len; ii++)
                                this.dataGridView1.Rows[indexx].Cells["Column11"].Value = this.dataGridView1.Rows[indexx].Cells["Column11"].Value + " " + sMACFrameGS.data[ii].ToString("X2");
                            this.dataGridView1.Rows[indexx].Cells["Column12"].Value = sMACFrameGS.lqi.ToString("D3");
                            // this.dataGridView1.Rows[indexx].Cells["Column13"].Value = sMACFrameGS.crcending.ToString("D1");
                            if (sMACFrameGS.crcending == 1)
                                this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "ok";
                            else
                                this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "err";
                            LastDestID = (UInt32)(sMACFrameGS.dstadd);
                        }
                        LastCMD = 0;
                    }
                    else 
                    {
                        ReqIndex = this.dataGridView1.Rows.Add();
                        indexx = ReqIndex;
                        this.dataGridView1.Rows[indexx].Cells["Column1"].Value = sMACFrameGS.time.ToString("D8");
                        this.dataGridView1.Rows[indexx].Cells["Column2"].Value = "0x" + sMACFrameGS.fcf.ToString("X4");
                        this.dataGridView1.Rows[indexx].Cells["Column3"].Value = sMACFrameGS.seq.ToString("D3");
                        this.dataGridView1.Rows[indexx].Cells["Column4"].Value = sMACFrameGS.dstpan.ToString("D5");
                        this.dataGridView1.Rows[indexx].Cells["Column5"].Value = (sMACFrameGS.dstadd % 1000000).ToString("D5");
                        this.dataGridView1.Rows[indexx].Cells["Column6"].Value = sMACFrameGS.srcadd.ToString("D5");
                        this.dataGridView1.Rows[indexx].Cells["Column7"].Value = sMACFrameGS.len.ToString("D2");
                        this.dataGridView1.Rows[indexx].Cells["Column8"].Value = sMACFrameGS.batt.ToString("D2");
                        this.dataGridView1.Rows[indexx].Cells["Column9"].Value = sMACFrameGS.pagnum.ToString("D4");
                        this.dataGridView1.Rows[indexx].Cells["Column10"].Value = sMACFrameGS.cmd.ToString("D2");
                        for (Byte ii = 0; ii < sMACFrameGS.len; ii++)
                            this.dataGridView1.Rows[indexx].Cells["Column11"].Value = this.dataGridView1.Rows[indexx].Cells["Column11"].Value + " " + sMACFrameGS.data[ii].ToString("X2");
                        this.dataGridView1.Rows[indexx].Cells["Column12"].Value = sMACFrameGS.lqi.ToString("D3");
                        // this.dataGridView1.Rows[indexx].Cells["Column13"].Value = sMACFrameGS.crcending.ToString("D1");
                        if (sMACFrameGS.crcending == 1)
                            this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "ok";
                        else
                            this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "err";
                    
                    }
                    break;
                case 0x00:                                       // 无源地址，无目标地址
                    Byte fcflowbyte = indata[Highbyteseq - 1];   // 取FCF低字节
                    if (fcflowbyte == 0x02)                      // 应答包
                    {
                        STR_MACFrameACK sMACFrameACK;
                        sMACFrameACK = (STR_MACFrameACK)Program.BytesToStruct(indata, typeof(STR_MACFrameACK));
                        ReqIndex = this.dataGridView1.Rows.Add();
                        indexx = ReqIndex;
                        this.dataGridView1.Rows[indexx].Cells["Column1"].Value  = sMACFrameACK.time.ToString("D8");
                        this.dataGridView1.Rows[indexx].Cells["Column2"].Value  = "0x" + sMACFrameACK.fcf.ToString("X4");
                        this.dataGridView1.Rows[indexx].Cells["Column3"].Value  = sMACFrameACK.seq.ToString("D3");
                        this.dataGridView1.Rows[indexx].Cells["Column12"].Value = sMACFrameACK.lqi.ToString("D3");
                        //this.dataGridView1.Rows[indexx].Cells["Column13"].Value = sMACFrameACK.crcending.ToString("D1");
                        if (sMACFrameACK.crcending == 1)
                            this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "ok";
                        else
                            this.dataGridView1.Rows[indexx].Cells["Column13"].Value = "err";
                        LastDestID = 0;
                    }

                    break;
                default:

                    break;
            }
        }

        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog fileDialog = new OpenFileDialog();
            fileDialog.InitialDirectory = Environment.SpecialFolder.Desktop.ToString(); // 默认路径为桌面， = @"d:\project\";
            fileDialog.Filter = "文本文件(*.bin)|*.bin";                                // 过滤文件类型

            //判断用户是否正确的选择了文件                 
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
            }
        }

        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 创建并保存文件， 获取新生成 文件路径 和 文件目录的路径
            SaveFileDialog fileDialog = new SaveFileDialog();
            fileDialog.InitialDirectory = Environment.SpecialFolder.Desktop.ToString(); // 默认路径为桌面
            fileDialog.Filter = "文本文件(*.bin)|*.bin";                                // 过滤文件类型
            //判断用户是否正确的选择了文件                 
            if (fileDialog.ShowDialog() == DialogResult.OK)
            {
            }
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Dispose();
        }

        private void 清除显示ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.dataGridView1.Rows.Clear();
            TotalPagNumber = 0;
            this.textBox1.Text = TotalPagNumber.ToString();
            ReqIndex = 0;
        }

        private void 开始抓包ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StartCatchPagFlag = 1;

            // 测试定时器，让定时器定时刷新界面中的一个文本框显示时间周期增加
            Timer1 = new System.Timers.Timer(200);
            Timer1.Elapsed += new System.Timers.ElapsedEventHandler(Timer1Out);   // 到达时间的时候执行事件； 
            Timer1.AutoReset = true;                                              // 设置是执行一次（false）还是一直执行(true)； 
            Timer1.Enabled = true;
            
        }

        private void 停止抓包ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            StartCatchPagFlag = 0;
            Timer1.AutoReset = false;                                             // 设置是执行一次（false）还是一直执行(true)； 
            Timer1.Enabled = false;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            byte[] sbuff = new byte[6];
            
            WirelessChannel =  Convert.ToByte(textBox3.Text);

            // 串口配置参数给无线模块
            sbuff[0] = (byte)'W';
            sbuff[1] = (byte)'C';
            sbuff[2] = WirelessChannel;
            sbuff[3] = 0;
            sbuff[4] = 0;
            sbuff[5] = 0;
            SerialCommx.SeriaWrite(sbuff, 6);
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            SerialCommx.SeriaInit(comboBox1.Text); ;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (thread != null)
                thread.Abort();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            FilterState = checkBox1.Checked;
        }
    }
}
