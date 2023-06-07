using System;
using System.Collections.Generic;
using System.Linq;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;

namespace Sniffer
{
    //[StructLayout(LayoutKind.Sequential), Serializable]
    [StructLayoutAttribute(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    public struct STR_MACFrameGS    // broadcast pag
    {
        public Byte   lqi;
        public Byte   crcending;
        public UInt32 time;
        public UInt16 fcf;
        public Byte   seq;
        public UInt16 dstpan;
        public UInt64 dstadd;
        public UInt16 srcadd;
        public Byte   len;
        public Byte   batt;
        public UInt16 pagnum;
        public Byte   cmd;
        public unsafe fixed Byte data[100];
    };

    //[StructLayout(LayoutKind.Sequential), Serializable]
    [StructLayoutAttribute(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    struct STR_MACFrameGG    // broadcast pag
    {
        public Byte     lqi;
        public Byte     crcending;
        public UInt32   time;
        public UInt16   fcf;
        public Byte     seq;
        public UInt16   dstpan;
        public UInt16   dstadd;
        public Byte     len;
        public Byte     batt;
        public UInt16   pagnum;
        public Byte     cmd;
        public unsafe fixed Byte data[100];
    };

    //[StructLayout(LayoutKind.Sequential), Serializable]
    [StructLayoutAttribute(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    struct STR_MACFrameSG    // broadcast pag
    {
        public Byte     lqi;
        public Byte     crcending;
        public UInt32   time;
        public UInt16   fcf;
        public Byte     seq;
        public UInt16   dstpan;
        public UInt16   dstadd;
        public UInt64   srcadd;
        public Byte     len;
        public Byte     batt;
        public UInt16   pagnum;
        public Byte     cmd;
        public unsafe fixed Byte data[100];
    };

    [StructLayoutAttribute(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
    struct STR_MACFrameACK    // broadcast pag
    {
        public Byte lqi;
        public Byte crcending;
        public UInt32 time;
        public UInt16 fcf;
        public Byte   seq;
    }; 
    static class Program
    {
        /// <summary>
        //将Byte转换为结构体类型（序列化）
        public static byte[] StructToBytes(object structObj, int size)
        {
            byte[] bytes = new byte[size];
            IntPtr structPtr = Marshal.AllocHGlobal(size);
            Marshal.StructureToPtr(structObj, structPtr, false);  // 将结构体拷到分配好的内存空间
            Marshal.Copy(structPtr, bytes, 0, size);              // 从内存空间拷贝到byte 数组
            Marshal.FreeHGlobal(structPtr);                       // 释放内存空间
            return bytes;
        }

        //将Byte转换为结构体类型（反序列化），支持数组长度小于结构体长度的反序列化操作
        public static object BytesToStruct(byte[] bytes, Type type)
        {
            int size = Marshal.SizeOf(type);
            if (size > bytes.Length)
            {
                size = bytes.Length;                              // 更新结构体长度，使得数组与结构体长度拷贝到是一致的，结构体长度多出部分默认值不考虑。
            }
            IntPtr structPtr = Marshal.AllocHGlobal(size);         // 分配结构体内存空间
            Marshal.Copy(bytes, 0, structPtr, size);               // 将byte数组拷贝到分配好的内存空间
            object obj = Marshal.PtrToStructure(structPtr, type);  // 将内存空间转换为目标结构体
            Marshal.FreeHGlobal(structPtr);                        // 释放内存空间
            return obj;
        }
        /*
        //将Byte转换为结构体类型（反序列化）
        public static object BytesToStructBase(byte[] bytes, Type type)
        {
            int size = Marshal.SizeOf(type);
            if (size > bytes.Length)
            {
                return null;
            }
            IntPtr structPtr = Marshal.AllocHGlobal(size);         // 分配结构体内存空间
            Marshal.Copy(bytes, 0, structPtr, size);               // 将byte数组拷贝到分配好的内存空间
            object obj = Marshal.PtrToStructure(structPtr, type);  // 将内存空间转换为目标结构体
            Marshal.FreeHGlobal(structPtr);                        // 释放内存空间
            return obj;
        }
        */
        /// 应用程序的主入口点。
        /// </summary> 
        [STAThread]
        static void Main()
        {
            // lllg new changed for the button back color
            // Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());

            
        }

    }
}
