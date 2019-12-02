using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Sniffer
{
    class Explain
    {
    }
}

/*
// Queue Operation end
byte[] lenx = new byte[10];
byte[] databuff0 = new byte[10];
byte[] databuff1 = new byte[10];
byte[] testdata0 = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
byte[] testdata1 = { 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18 };
Sniffer.MyQueue.QueueIn(testdata0, 8);
Sniffer.MyQueue.QueueOut(databuff0, lenx);
*/

/*
int index = this.dataGridView1.Rows.Add();
AddOneDataToDispBuff(index, Sniffer.MyQueue.testdata0);

index = this.dataGridView1.Rows.Add();
AddOneDataToDispBuff(index, Sniffer.MyQueue.testdata1);

index = this.dataGridView1.Rows.Add();
AddOneDataToDispBuff(index, Sniffer.MyQueue.testdata2);

index = this.dataGridView1.Rows.Add();
AddOneDataToDispBuff(index, Sniffer.MyQueue.testdata3);

 //this.dataGridView1.Rows[index4].Cells[0].Value = "4";
int index5 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index5].Cells[0].Value = "5";
int index6 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index6].Cells[0].Value = "6";
int index7 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index7].Cells[0].Value = "7";
int index8 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index8].Cells[0].Value = "8";
int index9 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index9].Cells[0].Value = "9";
int index10 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index10].Cells[0].Value = "10";
int index11 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index11].Cells[0].Value = "11";
int index12 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index12].Cells[0].Value = "12";
int index13 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index13].Cells[0].Value = "13";
int index14 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index14].Cells[0].Value = "14";
int index15 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index15].Cells[0].Value = "15";
int index16 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index16].Cells[0].Value = "16";
int index17 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index17].Cells[0].Value = "17";
int index18 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index18].Cells[0].Value = "18";
int index19 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index19].Cells[0].Value = "19";
int index20 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index20].Cells[0].Value = "20";
int index21 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index21].Cells[0].Value = "21";
int index22 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index22].Cells[0].Value = "22";
int index23 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index23].Cells[0].Value = "23";
int index24 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index24].Cells[0].Value = "24";
int index25 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index25].Cells[0].Value = "25";
int index26 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index26].Cells[0].Value = "26";
int index27 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index27].Cells[0].Value = "27";
int index28 = this.dataGridView1.Rows.Add();
this.dataGridView1.Rows[index28].Cells[0].Value = "28";
*/


/*
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata0, (byte)Sniffer.MyQueue.testdata0.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata1, (byte)Sniffer.MyQueue.testdata1.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length); 
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata2, (byte)Sniffer.MyQueue.testdata2.Length);
Sniffer.MyQueue.QueueIn(Sniffer.MyQueue.testdata3, (byte)Sniffer.MyQueue.testdata3.Length);
*/
