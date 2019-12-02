using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Sniffer
{
    public class MyQueue
    {
        public static byte[] testdata0 = { 0xFF, 0x01, 0xE8, 0x03, 0x00, 0x00, 0x41, 0x08, 0x01, 0x65, 0x00, 0xff, 0xff, 0x06, 0x22, 0x01, 0x00, 0x02, 0x90, 0x01, 0xe8, 0x03, 0x00, 0x00 };
        public static byte[] testdata1 = { 0xFD, 0x01, 0xEB, 0x03, 0x00, 0x00, 0x41, 0xC8, 0x02, 0x65, 0x00, 0x00, 0x00, 0x45, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x23, 0x01, 0x00, 0x06, 0x20, 0x03, 0xe8, 0x03, 0x00, 0x00 };
        public static byte[] testdata2 = { 0xFE, 0x01, 0xEE, 0x03, 0x00, 0x00, 0x41, 0x8C, 0x03, 0x65, 0x00, 0x45, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x21, 0x01, 0x00, 0x08, 0xB0, 0x04, 0xe8, 0x03, 0x00, 0x00, 0x55, 0xAA };
        public static byte[] testdata3 = { 0xFA, 0x01, 0xF1, 0x03, 0x00, 0x00, 0x02, 0x00, 0x03 };

        // const
        public static UInt32 QueueSize = 1024;
        public static byte   QueueFull = 0;
        public static byte   QueueEmpty = 1;
        public static byte   QueueOperateOk = 2;

        // para
        public static UInt32 Front;     //前部
        public static UInt32 Rear;      //后部
         static UInt32 Count;     //个数
        public static byte[,] Buffer = new byte[QueueSize, 128];

        // Queue Operation start
        public static void QueueInit()   
        {   
            Front = 0;   
            Rear  = 0;
            Count = 0;
        }

        // Queue In   
        public static byte QueueIn(byte[] data, byte len)   
        {
            byte ii;
            if((Front == Rear) && (Count == QueueSize))   
            {  
                return QueueFull;   // full 
            }
            else
            {   
                // in  
                Buffer[Rear, 0] = len;
                // memcpy(&Queue->dat[Queue->front][1], sdat, len); 
                for (ii = 0; ii < len; ii++)
                {
                    Buffer[Rear, 1 + ii] = data[ii];
                }
                Rear  = (Rear + 1) & (QueueSize-1);             //加满缓冲区以后就清除0，queuesize必须为2的n次方
                Count = Count + 1;
                return QueueOperateOk;   
            }
        }

        // Queue Out   
        public unsafe static byte QueueOut(byte[] sdat, byte[] len )   
        {
            byte ii;
            if((Front == Rear) && (Count == 0))   
            {   
                return QueueEmpty; // empty    
            }
            else    
            {   
                // out
                len[0] = Buffer[Front, 0];
                // memcpy(sdat,&Queue->dat[Queue->front][1],Queue->dat[Queue->front][0]); 
                for (ii = 0; ii < len[0]; ii++)
                {
                    sdat[ii] = Buffer[Front, 1 + ii];
                }
                Front = (Front + 1) & (QueueSize-1);
                Count = Count - 1;
                return QueueOperateOk;
            } 
        }

    }
}
