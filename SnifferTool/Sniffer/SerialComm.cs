using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;
using System.Timers;
using System.IO.Ports;

namespace Sniffer
{
    class SerialComm
    {
        public static byte GetHeadFlag = 0;
        
        public static byte[] Framebuff = new byte[128];
        public static byte[] CommBuff  = new byte[4096];

        SerialPort SComm;                                // 使用构造函数取串口控件
        TextBox MsgRc;

        

        public SerialComm(SerialPort SerialPortx,TextBox TextMsg)
        {
            SComm = SerialPortx;
            MsgRc = TextMsg;
        }

        public bool SeriaInit(string comx)
        {
            try
            {
                if (SComm.IsOpen)
                    SComm.Close();
            }
            catch 
            {

            }
            SComm.PortName = comx;                        // 串口号
            SComm.BaudRate = 921600;                       // 波特率：1000000
            SComm.DataBits = 8;                             // 数据位数：8
            SComm.StopBits = System.IO.Ports.StopBits.One;  // 停止位
            SComm.Parity = System.IO.Ports.Parity.None;     // 奇偶校验无
            SComm.Encoding = Encoding.Default;
            SComm.DataReceived += new System.IO.Ports.SerialDataReceivedEventHandler(this.serialPort1_Rcv);
            try
            {
                SComm.Open();                                   // 打开串口
                return true;
            }
            catch 
            {
                MessageBox.Show(comx + "端口被占用","提示",MessageBoxButtons.OK,MessageBoxIcon.Error);
                return false;
            }
        }
        public void SeriaOpen()
        {
            SComm.Open();                                   // 打开串口
        }
        public bool SerialIsOpen()
        {
            //if (scomm.isopen)
            //{
            //    return 1;
            //}
            //else
            //{
            //    return 0;
            //}
            return SComm.IsOpen;
            
        }
        public void SeriaClose()
        {
            SComm.Close();                                  // 打开串口
        }
        public void SeriaWrite(byte [] data, byte len)
        {
            try
            {
                if (SComm.IsOpen)
                {
                    SComm.Write(data, 0, len);    
                }
            }
            catch { }
                                
        }
        public string GetPortName()
        {
            return SComm.PortName;
        }
        byte[]  GetCommBuff()
        {
            return CommBuff;
        }
        void serialPort1_Rcv(object sender, SerialDataReceivedEventArgs e)
        {
            UInt16 bufflen = (UInt16)SComm.BytesToRead;

            byte[] dat = new byte[bufflen];
            SComm.Read(dat, 0, bufflen);

            //string TempData = System.Text.Encoding.Default.GetString(dat);
            // 将textBox1的内容插入到第一行
            // 索引0是 richText1 第一行位置
            //MsgRc.AppendText(Environment.NewLine);
           // MsgRc.Text = MsgRc.Text.Insert(0, TempData);
            //MsgRc.Text = MsgRc.Text.Insert(0, System.Text.Encoding.Default.GetString(dat));
            MsgRc.AppendText(System.Text.Encoding.Default.GetString(dat));
            //MsgRc.Show();

            CommBuff = dat;
            GetHeadFlag = 0;
            //while (SComm.BytesToRead >= 90)
            //{
            //    if (GetHeadFlag == 4)
            //    {
            //        while (SComm.BytesToRead < 96) ;
            //        SComm.Read(Framebuff, 0, 96);
            //        MyQueue.QueueIn(Framebuff, 96);
            //        GetHeadFlag = 0;
            //    }
            //    else if (GetHeadFlag == 5)
            //    {
            //        GetHeadFlag = 0;
            //        if (SComm.BytesToRead < 96) SComm.Read(Framebuff, 0, SComm.BytesToRead);
            //        else                        SComm.Read(Framebuff, 0, 96);
            //        if ((Framebuff[0] == (byte)'W') && (Framebuff[1] == (byte)'C'))
            //        {

            //            byte channel = (byte)Framebuff[2];
            //            if (channel == Sniffer.Form1.WirelessChannel)
            //            {
            //                MessageBox.Show("射频通道配置成功!!!", "Msgbox");
            //            }
            //            else 
            //            {
            //                MessageBox.Show("射频信道配置失败!!!", "Msgbox");
            //            }
            //        }  
            //    }
            //    else 
            //    {
            //        SComm.Read(Framebuff, 0, 1);
            //        if (GetHeadFlag == 0)
            //        {
            //            if (Framebuff[0] == 'M')      GetHeadFlag = 1;         
            //            else                          GetHeadFlag = 0;
            //        }
            //        else if (GetHeadFlag == 1)
            //        {
            //            if (Framebuff[0] == 'O')      GetHeadFlag = 2;
            //            else if (Framebuff[0] == 'M') GetHeadFlag = 1;
            //            else                          GetHeadFlag = 0;
            //        }
            //        else if (GetHeadFlag == 2)
            //        {
            //            if (Framebuff[0] == 'O')      GetHeadFlag = 3;
            //            else if (Framebuff[0] == 'M') GetHeadFlag = 1;
            //            else GetHeadFlag = 0;
            //        }
            //        else if (GetHeadFlag == 3)
            //        {
            //            if (Framebuff[0] == 'N')      GetHeadFlag = 4;
            //            else if (Framebuff[0] == 'M') GetHeadFlag = 1;
            //            else if (Framebuff[0] == 'C') GetHeadFlag = 5;
            //            else                          GetHeadFlag = 0;
            //        }
            //    }
            //}
        }


    }
}

