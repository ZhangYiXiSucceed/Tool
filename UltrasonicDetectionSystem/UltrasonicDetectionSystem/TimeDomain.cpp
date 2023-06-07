#include "TimeDomain.h"
#include "ui_TimeDomain.h"

TimeDomain::TimeDomain(QWidget *parent) :
    QWidget(parent),
    MyTimer(new QTimer(this)),
    MyTimer2(new QTimer(this)),
    MySerialPort(new QSerialPort),
    ui(new Ui::TimeDomain)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
    Refresh();
}

TimeDomain::~TimeDomain()
{
    delete ui;
}
void TimeDomain::InitUI()
{
    this->setWindowFlags((this->windowFlags()|Qt::WindowMinimizeButtonHint) & ~Qt::WindowMaximizeButtonHint);
    #if Developer
      ui->comboBoxComPort->setVisible(true);
      ui->tbnWritePulsePara->setVisible(true);
      ui->tbnReadPulsePara->setVisible(true);
    #else
      ui->comboBoxComPort->setVisible(false);
      ui->tbnWritePulsePara->setVisible(false);
      ui->tbnReadPulsePara->setVisible(false);
    #endif

    ui->MyCustomPlot->addGraph();
    ui->MyCustomPlot->graph(0)->setName(tr("Waves"));
      //ui->MyCustomPlot->graph(0)->addData(0,0);
    ui->MyCustomPlot->xAxis->setLabel("X");
    ui->MyCustomPlot->yAxis->setLabel("波形幅值   /mv");
      //ui->MyCustomPlot->xAxis->setRange(0,10);
      //ui->MyCustomPlot->yAxis->setRange(-1,1);
    ui->MyCustomPlot->rescaleAxes(true);
    ui->MyCustomPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);

    QPen MyPen1(Qt::green,3,Qt::CustomDashLine);
    ui->MyCustomPlot->addGraph();
    ui->MyCustomPlot->graph(1)->setPen(MyPen1);

    QPen MyPen2(Qt::red,3,Qt::CustomDashLine);
    ui->MyCustomPlot->addGraph();
    ui->MyCustomPlot->graph(2)->setPen(MyPen2);



    ui->tbnConnect->setAutoRaise(true);
    ui->tbnConnect->setIcon(ImageFileOpen);
    ui->tbnConnect->setIconSize(ImageFileOpen.size());
    ui->tbnConnect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);


    ui->spStartPosition->setRange(0,5000);
    ui->spEndPosition->setRange(0,5000);

    QFont Ft("Microsoft YaHei");
    Ft.setPointSize(12);
    ui->tbnConnect->setFont(Ft);

    ui->lePulseFrequency->setFont(Ft);
    ui->lePulseInterval->setFont(Ft);
    ui->lePulseNum->setFont(Ft);
    ui->leAverageTimes->setFont(Ft);
    ui->leSampleNum->setFont(Ft);
    ui->spStartPosition->setFont(Ft);
    ui->spEndPosition->setFont(Ft);
    ui->spDelayTime->setFont(Ft);

    ui->tbnStartDraw->setAutoRaise(true);
    ui->tbnStartDraw->setIcon(ImageFileStart);
    ui->tbnStartDraw->setIconSize(ImageFileStart.size());
    ui->tbnStartDraw->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnStartDraw->setFont(Ft);

    ui->tbnChangeWaveStyle->setAutoRaise(true);
    ui->tbnChangeWaveStyle->setIcon(ImageFileChange);
    ui->tbnChangeWaveStyle->setIconSize(ImageFileChange.size());
    ui->tbnChangeWaveStyle->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnChangeWaveStyle->setFont(Ft);

    ui->tbnFrequencyDomainNext->setAutoRaise(true);
    ui->tbnFrequencyDomainNext->setIcon(ImageFileFrequencyDomain);
    ui->tbnFrequencyDomainNext->setIconSize(ImageFileFrequencyDomain.size());
    ui->tbnFrequencyDomainNext->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnFrequencyDomainNext->setFont(Ft);

    ui->tbnSaveData->setAutoRaise(true);
    ui->tbnSaveData->setIcon(ImageFileSaveData);
    ui->tbnSaveData->setIconSize(ImageFileSaveData.size());
    ui->tbnSaveData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnSaveData->setFont(Ft);

    ui->tbnClearWaves->setAutoRaise(true);
    ui->tbnClearWaves->setIcon(ImageFileClearWaves);
    ui->tbnClearWaves->setIconSize(ImageFileClearWaves.size());
    ui->tbnClearWaves->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnClearWaves->setFont(Ft);

    ui->tbnReadPulsePara->setAutoRaise(true);
    ui->tbnReadPulsePara->setIcon(ImageFileReadPulsePara);
    ui->tbnReadPulsePara->setIconSize(ImageFileReadPulsePara.size());
    ui->tbnReadPulsePara->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnReadPulsePara->setFont(Ft);
    ui->tbnWritePulsePara->setAutoRaise(true);

    ui->tbnWritePulsePara->setIcon(ImageFileWritePulsePara);
    ui->tbnWritePulsePara->setIconSize(ImageFileWritePulsePara.size());
    ui->tbnWritePulsePara->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnWritePulsePara->setFont(Ft);

    ui->tbnLoadData->setAutoRaise(true);
    ui->tbnLoadData->setIcon(ImageFileLoadData);
    ui->tbnLoadData->setIconSize(ImageFileLoadData.size());
    ui->tbnLoadData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnLoadData->setFont(Ft);

    ui->tbnReset->setAutoRaise(true);
    ui->tbnReset->setIcon(ImageFileReset);
    ui->tbnReset->setIconSize(ImageFileReset.size());
    ui->tbnReset->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnReset->setFont(Ft);

    ui->leDotText->setFont(Ft);
    ui->leDotNum->setFont(Ft);

    ui->leTimeDomainMaxValue->setFont(Ft);
    ui->leTimeDomainMinValue->setFont(Ft);
    ui->leTimeDomainMaxMinValue->setFont(Ft);

    ui->lePulseFrequency->setText(tr("2000000"));
    ui->lePulseInterval->setText(tr("1"));
    ui->lePulseNum->setText(tr("8"));
    ui->leSampleNum->setText(tr("512"));
    ui->leAverageTimes->setText(tr("1"));
    ui->spDelayTime->setValue(0);
    ui->spStartPosition->setValue(0);
    ui->spEndPosition->setValue(512);

    SelectStartPosition(0);
    SelectEndPosition(512);

    DrawFlag=false;
    ConnectFlag=false;
    ConnectTimes=0;

    StartPositionFlag=false;
    EndPositionFlag=false;

    RespondFlag = true;
}
void TimeDomain::InitConnect()
{
    connect(ui->tbnFrequencyDomainNext,SIGNAL(clicked(bool)),this,SLOT(DisplayFrequencyDomainNext()));
    connect(ui->tbnStartDraw,SIGNAL(clicked(bool)),this,SLOT(Draw_TimeDomain_Wave()));

    connect(MySerialPort,SIGNAL(readyRead()),this,SLOT(ReadRecData()));
    connect(MyTimer2,SIGNAL(timeout()),this,SLOT(FrameRecDataProcess()));

    connect(MyTimer,SIGNAL(timeout()),this,SLOT(TimeUpDate()));


    connect(ui->tbnClearWaves,SIGNAL(clicked(bool)),this,SLOT(ClearWaves()));

    connect(ui->MyCustomPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->MyCustomPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->MyCustomPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->MyCustomPlot->yAxis2, SLOT(setRange(QCPRange)));
    connect(ui->tbnConnect,SIGNAL(clicked(bool)),this,SLOT(ConnectComPort()));

    connect(ui->tbnWritePulsePara,SIGNAL(clicked(bool)),this,SLOT(WritePulsePara()));
    connect(ui->tbnChangeWaveStyle,SIGNAL(clicked(bool)),this,SLOT(ChangeWaveStyle()));
    connect(ui->tbnReadPulsePara,SIGNAL(clicked(bool)),this,SLOT(ReadPulsePara()));
    connect(ui->tbnSaveData,SIGNAL(clicked(bool)),this,SLOT(SaveTimeDomainData()));
    connect(ui->tbnReset,SIGNAL(clicked(bool)),this,SLOT(SystemReset()));

    connect(this,SIGNAL(RecFinish()),this,SLOT(FindMaxMin()));
    connect(ui->spStartPosition,SIGNAL(valueChanged(int)),this,SLOT(SelectStartPosition(int)));
    connect(ui->spEndPosition,SIGNAL(valueChanged(int)),this,SLOT(SelectEndPosition(int)));
}
void TimeDomain::DisplayFrequencyDomainNext()
{
    QVector<double> SampleData;
    quint16 SampleLength=0;
    for(quint16 i=WaveStart;i<=WaveEnd;i++)
       SampleData.push_back(WaveX[i]);
    SampleLength=WaveEnd-WaveStart+1;
    emit Display(1);
    emit SendSampleData(SampleLength,SampleData);
}
void TimeDomain::Draw_TimeDomain_Wave()
{
//    static uint8_t DrawEnterTimes=0;
    QByteArray Command;
    Command.resize(13);

    Command[0]=0x68;
    Command[1]=0x02;
    Command[2]=0x01;
    Command[3]=0x09;

    Command[4]=ui->lePulseFrequency->text().toInt()/65536;
    Command[5]=ui->lePulseFrequency->text().toInt()%65536/256;
    Command[6]=ui->lePulseFrequency->text().toInt()%65536%256;

    Command[7]=ui->lePulseInterval->text().toInt();

    Command[8]=ui->lePulseNum->text().toInt();

    Command[9]=ui->leSampleNum->text().toInt()/256;
    Command[10]=ui->leSampleNum->text().toInt()%256;

    Command[11]=ui->leAverageTimes->text().toInt();

    Command[12]=ui->spDelayTime->text().toInt();

    Command[13]=0x00;

    for(quint8 i=0;i<13;i++)
        Command[13]=Command[13]+Command[i];
    Command[13]=Command[13]%256;

//    if(DrawEnterTimes==0)
//    {
////        ui->MyCustomPlot->addGraph();
////        ui->MyCustomPlot->graph(0)->setName(tr("Waves"));
////        //ui->MyCustomPlot->graph(0)->addData(0,0);
////        ui->MyCustomPlot->xAxis->setLabel("X");
////        ui->MyCustomPlot->yAxis->setLabel("波形幅值/mv");
////        //ui->MyCustomPlot->xAxis->setRange(0,10);
////        //ui->MyCustomPlot->yAxis->setRange(-1,1);
////        ui->MyCustomPlot->rescaleAxes(true);
////        ui->MyCustomPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
//        //MyTimer->start(1);
//        //DrawFlag=true;

//        ShowMessage(tr("8个脉冲参数写入失败，下位机未响应，请检验端口是否可以正常通信！"),1500);
//        this->WriteBytes(Command);

//        ui->tbnStartDraw->setIcon(ImageFileStop);
//        ui->tbnStartDraw->setText(tr("停止"));
////        WaveXNum=0;
//    }
//    else
//    {
       ShowMessage(tr("8个脉冲参数写入失败，下位机未响应，请检验端口是否可以正常通信！"),1500);
       WaveXNum=0;
       if( ui->tbnStartDraw->text()==tr("开始"))
       {
           DrawFlag=true;
           WriteBytes(Command);
           ui->tbnStartDraw->setIcon(ImageFileStop);
           ui->tbnStartDraw->setText(tr("停止"));
       }
       else
       {
           DrawFlag=false;
           ui->tbnStartDraw->setIcon(ImageFileStart);
           ui->tbnStartDraw->setText(tr("开始"));
       }
//    }
//    DrawEnterTimes++;
//    if(DrawEnterTimes==100)
//        DrawEnterTimes=0;
}
void TimeDomain::TimeUpDate()
{
//    static quint16 IndexNum=0;
//    if(DrawFlag)
//    {
//        if(IndexNum<WaveXNum)
//        {
//            ui->MyCustomPlot->graph(0)->addData(IndexNum,WaveX[IndexNum]);
//            ui->MyCustomPlot->replot();
//            ui->MyCustomPlot->rescaleAxes(true);
//            ui->leDotNum->setText(QString::number(IndexNum+1));
//            IndexNum+=1;
//            if(IndexNum==(WaveXNum-1))
//            {
//                emit RecFinish();
//            }
//        }
//        else
//        {
//            IndexNum=0;
//            MyTimer->stop();
//            DrawFlag=false;
//            ui->tbnStartDraw->setIcon(ImageFileStart);
//            ui->tbnStartDraw->setText(tr("开始"));
//        }
//    }
    quint8 TempCnt = FrameRecData[2];
    static quint8 RespondTimes =0;
    if(RespondFlag == false)
    {
         RespondTimes++;
        if(RespondTimes>3)
       {
           RespondTimes=0;
           ShowMessage("下位机无响应！",1000);
           MyTimer->stop();
       }
      else
      {
          RespondError(TempCnt);
      }
    }
    if(ConnectFlag)
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未响应!"),2000);
        MySerialPort->close();
        emit ui->tbnConnect->click();
    }
}
void TimeDomain::ClearWaves()
{
   if(ui->MyCustomPlot->graphCount()>0)
     ui->MyCustomPlot->graph(0)->data()->clear();
//   if(ui->MyCustomPlot->graphCount()>1)
//     ui->MyCustomPlot->graph(1)->data()->clear();
//   if(ui->MyCustomPlot->graphCount()>2)
//     ui->MyCustomPlot->graph(2)->data()->clear();
   ui->MyCustomPlot->replot();
   WaveXNum=0;
   ui->leTimeDomainMaxValue->setText(tr(""));
   ui->leTimeDomainMinValue->setText(tr(""));
   ui->leTimeDomainMaxMinValue->setText(tr(""));
   ui->leDotNum->setText(tr("0"));
}
void TimeDomain::Refresh()
{
    QList <QSerialPortInfo> InfoList = QSerialPortInfo::availablePorts();
    ui->comboBoxComPort->clear();
    if(InfoList.isEmpty())
        ShowMessage(tr("未找到可用的端口"),1500);
    else
    {
        foreach(QSerialPortInfo Info,InfoList)
            ui->comboBoxComPort->addItem(Info.portName() + ' ' + Info.description());
    }
}
void TimeDomain::ConnectComPort()
{
    QString PortName;
    static uint8_t PortCount=0;
    if(ConnectTimes<=5)
    {
        if(ui->tbnConnect->text()==tr("连接"))
        {
            if(PortCount>=ui->comboBoxComPort->count())
            {
                 PortCount=0;
                 ConnectTimes++;
                 Refresh();
            }
            ui->comboBoxComPort->setCurrentIndex(PortCount);
            PortName=ui->comboBoxComPort->currentText().split(' ').first();
            if(MySerialPort->isOpen())
            {
                MySerialPort->close();
                ShowMessage(MySerialPort->portName()+tr("端口已关闭"),1000);
                return;
            }
            else
            {
                MySerialPort->setPortName(PortName);
                PortCount++;
                if(MySerialPort->open(QIODevice::ReadWrite))
                {
                    // ShowMessage(PortName+tr("端口状态:")+QString::number(MySerialPort->isOpen())+tr(" ")+tr("SerialPort Open Successfully!"),3000);
                     MySerialPort->setBaudRate(115200);
                     MySerialPort->setDataBits(QSerialPort::Data8);
                     MySerialPort->setParity(QSerialPort::NoParity);
                     MySerialPort->setStopBits(QSerialPort::OneStop);
                     MySerialPort->setFlowControl(QSerialPort::NoFlowControl);
                     QByteArray Indentifier;
                     Indentifier.resize(5);
                     Indentifier[0]=0x68;
                     Indentifier[1]=0x01;
                     Indentifier[2]=0x01;
                     Indentifier[3]=0x00;
                     Indentifier[4]=0x6A;
                     WriteBytes(Indentifier);
                     MyTimer->start(1000);
                     ConnectFlag=true;
                }
                else
                {
                    //ShowMessage(PortName+tr("打开失败，端口可能被占用！")+tr("串口状态:")+QString::number(MySerialPort->isOpen()),2000);
                    return;
                }
             }
        }
        else
        {
            MySerialPort->close();
            ui->tbnConnect->setText(tr("连接"));
            ui->tbnConnect->setIcon(ImageFileOpen);
            PortCount=0;
            ShowMessage(MySerialPort->portName()+tr("已断开"),1000);
            ShowParameter(tr("无"),tr("无"));
        }
    }
    else
    {
        MyTimer->stop();
        ConnectTimes=0;
        PortCount=0;
        ConnectFlag=false;
        ShowMessage(tr("端口未找到，请检查设备是否连接PC!"),1000);
        Refresh();
    }
//    qDebug()<<PortCount<<"\n";
}
void TimeDomain::WriteBytes(QByteArray Data)
{
    if(MySerialPort->isOpen())
    {
        MySerialPort->write(Data);
    }
    else
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未打开，不能发送数据！"),1000);
    }
}
void TimeDomain::ReadRecData()
{
    MyTimer2->start(20);
    FrameRecData.append(MySerialPort->readAll());
}
void TimeDomain::FrameRecDataProcess()
{
   MyTimer2->stop();

   quint8 TempNum;
   quint16 DataIndex=0;               //数组移动索引
   bool IsCheckSumSucceed=false;
   while(1)
   {
       DataIndex=FindFrameHead(FrameRecData,DataIndex);  //寻找包头
       if(DataIndex==200)                                //200索引用来指示是否接收完成，
       {
           break;
       }
       else if(DataIndex<100)                            //100索引用来指示是否出错，正常不会到100索引。
       {
           #if Debug
             PrintFrameData(FrameRecData,DataIndex);       //打印接收指令
           #endif
           IsCheckSumSucceed=IsCheckSumRight(FrameRecData,DataIndex);    //校验是否正确
           if(IsCheckSumSucceed)
           {
               RunCommand(FrameRecData,DataIndex);      //运行相应指令
           }
           else
           {
               //qDebug()<<"校验不成功！";
               TempNum = FrameRecData[1];
               ShowMessage(tr("校验不成功！"),1000);
               ShowMessage(tr("校验错误!----%1").arg(TempNum),1000);
               if(TempNum == 0x03)
               {
                   TempNum=FrameRecData[2];
                   CheckoutError(TempNum);
                   MyTimer->start(500);
                   RespondFlag=false;
               }
               break;
           }
       }
       else
       {
           //qDebug()<<"数据错误，没有找到包头！";
           break;
       }
   }
   FrameRecData.clear();
  // qDebug()<<"当前数据处理完成！";

}
void TimeDomain::CheckoutError(quint8 TempNum)
{
    QByteArray Command;
    Command.resize(6);

    Command[0]=0x68;
    Command[1]=0x03;
    Command[2]=TempNum;
    Command[3]=0x01;
    Command[4]=0x04;
    Command[5]=0x00;
    for(quint8 i=0;i<5;i++)
        Command[5]=Command[5]+Command[i];
    this->WriteBytes(Command);
}
void TimeDomain::RespondError(quint8 TempNum)
{
    QByteArray Command;
    Command.resize(6);

    Command[0]=0x68;
    Command[1]=0x03;
    Command[2]=TempNum;
    Command[3]=0x01;
    Command[4]=0x06;
    Command[5]=0x00;
    for(quint8 i=0;i<5;i++)
        Command[5]=Command[5]+Command[i];
    this->WriteBytes(Command);
}
uint8_t TimeDomain::FindFrameHead(QByteArray RecData,uint16_t DataIndex)
{
    while(RecData[DataIndex]!=0x68)
    {
        if(RecData[DataIndex]==0x00)       //判断是否接收完成，即判断下面数组是否为0，如若为0，则接收完成。(默认数组初始化为0）
        {
            DataIndex=200;
            break;
        }
        else
        {
            DataIndex++;
            if(DataIndex>=100)
            {
                #if Debug
                  qDebug()<<"索引出错！";
                #endif
                break;
            }
        }
    }
    return DataIndex;
}
void TimeDomain::PrintFrameData(QByteArray RecData,uint16_t DataIndex)
{
  quint8 DataLength=RecData[DataIndex+3]+5;   //计算帧数据长度
  quint8 TempNum;
  for(int i=DataIndex;i<DataLength+DataIndex;i++)
  {
      TempNum=RecData[i];
      qDebug("%x",TempNum);
  }
}
bool TimeDomain::IsCheckSumRight(QByteArray RecData,uint16_t DataIndex)
{
    quint8 DataLength=RecData[DataIndex+3]+5;   //计算帧数据长度
    quint16 Sum=0;
    quint8 CheckNum=0;
    for(int i=DataIndex;i<(DataLength+DataIndex-1);i++)
    {
        Sum+=RecData[i];
    }
    Sum=Sum%256;
    //qDebug("%x",Sum);
    //qDebug("%x",DataIndex);
    CheckNum=RecData[DataLength+DataIndex-1];
    //qDebug("%x",CheckNum);
    //qDebug("%x",DataLength);
    if(Sum==CheckNum)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void TimeDomain::RunCommand(QByteArray RecData,uint16_t &DataIndex)
{
    uint16_t DataLength=RecData[DataIndex+3]+5;   //计算帧数据长度

    switch (RecData[DataIndex+1])
    {
    case 0x01:
    {
        #if Debug
          qDebug()<<"连接成功！";
        #endif
        MyTimer->stop();
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口打开成功！"),5000);
        ShowParameter(ui->comboBoxComPort->currentText().split(' ').first(),tr("115200"));
        ui->tbnConnect->setText(tr("断开"));
        ui->tbnConnect->setIcon(ImageFileClose);
        ConnectFlag=false;
        ConnectTimes=0;
        DataIndex+=DataLength;
    }
        break;
    case 0x02:
    {
        ShowMessage(tr("参数设置完成，并开始测量"),1000);
        DataIndex+=DataLength;
    }
        break;
    case 0x03:
    {
        RespondFlag=true;
        MyTimer->stop();

        quint8 CheckoutCode =  RecData[4];
        if((DataLength==6)&&(CheckoutCode==0x03))
        {
              ShowMessage(tr("上位机响应长度有错误！"),1000);
        }
        else
        {
            quint16 t=0;
            quint16 l=0;
            static QVector<double> TimeDomainData;
            static QVector<double> SampleCount;
            qint16 TempData=0;
            quint8 TempSaveData;
            quint16 SampleDataLength=ui->leSampleNum->text().toInt();
            quint8 PackCnt=RecData[2];
            int TempSize = SampleDataLength*2-64*PackCnt;
            if((PackCnt==(SampleDataLength*2/64))||(TempSize==64))
            {
                l=PackCnt*32;
                for(t=4;t<(DataLength-1);t+=2,l+=1)
                {
                    TempSaveData=RecData[t+1];
                    TempData=TempSaveData;
                    TempData=TempData<<8;
                    TempSaveData=RecData[t];
                    TempData+=TempSaveData;

                    TempData=TempData<<4;
                    TempData=TempData>>4;

                    WaveX[l]=(double)TempData*REFVol/2048;

                    TimeDomainData.push_back(WaveX[l]);
                    SampleCount.push_back((double)l);
                }

                RecSampleData(PackCnt);
                ShowMessage(tr("成测量完成！"),1000);
                DrawFlag=true;
                WaveXNum=l;
                //MyTimer->start(30);
                ui->leDotNum->setText(QString::number(l));
                l=0;

                ui->MyCustomPlot->graph(0)->setData(SampleCount,TimeDomainData);
                ui->MyCustomPlot->graph(0)->rescaleAxes(true);
                ui->MyCustomPlot->replot();

                DrawFlag=false;
                ui->tbnStartDraw->setIcon(ImageFileStart);
                ui->tbnStartDraw->setText(tr("开始"));

                SampleCount.clear();
                TimeDomainData.clear();

                emit RecFinish();
            }
            else
            {
                 l=PackCnt*32;
                for(t=4;t<(DataLength-1);t+=2,l+=1)
                {
                    TempSaveData=RecData[t+1];
                    TempData=TempSaveData;
                    TempData=TempData<<8;
                    TempSaveData=RecData[t];
                    TempData+=TempSaveData;

                    TempData=TempData<<4;
                    TempData=TempData>>4;

                    WaveX[l]=(double)TempData*REFVol/2048 ;

                    TimeDomainData.push_back(WaveX[l]);
                    SampleCount.push_back((double)l);
                }

                ShowMessage(tr("成功收到第%1组数据").arg(PackCnt),1000);
                RecSampleData(PackCnt);

                RespondFlag=false;
                MyTimer->start(500);
            }
        }
        DataIndex+=DataLength;
    }
        break;
    case 0x04:
    {
        ShowMessage(tr("复位成功"),1000);
        DataIndex+=DataLength;
    }
        break;
    case 0x05:
    {
        ShowMessage(tr("参数读取成功"),1000);
        quint8 MaxValue,MidleValue,MinValue;

        MaxValue=RecData[DataIndex+4];
        MidleValue=RecData[DataIndex+5];
        MinValue=RecData[DataIndex+6];

        ui->lePulseFrequency->setText(QString::number(MaxValue<<16|MidleValue<<8|MinValue));
        ui->lePulseInterval->setText(QString::number(RecData[DataIndex+7]));
        ui->lePulseNum->setText(QString::number(RecData[DataIndex+8]));

        MaxValue=RecData[DataIndex+9];
        MinValue=RecData[DataIndex+10];

        ui->leSampleNum->setText(QString::number(MaxValue<<8|MinValue));
        ui->leAverageTimes->setText(QString::number(RecData[DataIndex+11]));
        ui->spDelayTime->setValue(RecData[DataIndex+12]);

        DataIndex+=DataLength;
    }
        break;
    default:
        DataIndex+=DataLength;
        break;
    }
}
void TimeDomain::RecSampleData(quint8 Cnt)
{
    QByteArray Command;
    Command.resize(13);

    Command[0]=0x68;
    Command[1]=0x03;
    Command[2]=Cnt;
    Command[3]=0x01;
    Command[4]=0x00;
    Command[5]=0x00;
    for(quint8 i=0;i<5;i++)
        Command[5]=Command[5]+Command[i];
    this->WriteBytes(Command);
}
void TimeDomain::WritePulsePara()
{
    QByteArray MyPulsePara;
    MyPulsePara.resize(13);

    MyPulsePara[0]=0x68;
    MyPulsePara[1]=0x01;
    MyPulsePara[2]=0x00;
    MyPulsePara[3]=0x09;

    MyPulsePara[4]=ui->lePulseFrequency->text().toInt()/65536;
    MyPulsePara[5]=ui->lePulseFrequency->text().toInt()%65536/256;
    MyPulsePara[6]=ui->lePulseFrequency->text().toInt()%65536%256;

    MyPulsePara[7]=ui->lePulseInterval->text().toInt();

    MyPulsePara[8]=ui->lePulseNum->text().toInt();

    MyPulsePara[9]=ui->leSampleNum->text().toInt()/256;
    MyPulsePara[10]=ui->leSampleNum->text().toInt()%256;

    MyPulsePara[11]=ui->leAverageTimes->text().toInt();

    MyPulsePara[12]=ui->spDelayTime->text().toInt();

    MyPulsePara[13]=0x00;

    for(quint8 i=0;i<13;i++)
        MyPulsePara[13]=MyPulsePara[13]+MyPulsePara[i];
    MyPulsePara[13]=MyPulsePara[13]%256;

    ShowMessage(tr("8个脉冲参数写入失败，下位机未响应，请检验端口是否可以正常通信！"),3000);
    this->WriteBytes(MyPulsePara);
}
void TimeDomain::ChangeWaveStyle()
{
    static bool ChangeFlag=false;
    if(ChangeFlag)
    {
        QPen MyPen(Qt::blue,1,Qt::SolidLine);
        ui->MyCustomPlot->graph(0)->setPen(MyPen);
    }
    else
    {
        QPen MyPen(Qt::blue,1,Qt::DotLine);
        ui->MyCustomPlot->graph(0)->setPen(MyPen);
    }
     ChangeFlag=!ChangeFlag;
}
void TimeDomain::ReadPulsePara()
{
   QByteArray MyPulsePara;
   MyPulsePara.resize(5);

   MyPulsePara[0]=0x68;
   MyPulsePara[1]=0x02;
   MyPulsePara[2]=0x00;
   MyPulsePara[3]=0x00;
   MyPulsePara[4]=0x6A;

   this->WriteBytes(MyPulsePara);
}
void TimeDomain::SaveTimeDomainData()
{
//   QString MyTimeDomainCsvFileName = QApplication::applicationDirPath()+ \
//           QDateTime::currentDateTime().toString("yyyyMMdd")+ ".csv";
   QString MyTimeDomainCsvFileName=QFileDialog::getSaveFileName(this, tr("Excel file"),QApplication::applicationDirPath () + \
                                                       QDateTime::currentDateTime().toString("yyyyMMdd")+ ".csv",
                                                       tr("Files (*.csv);;AllFiles (*.*)"));
   if(MyTimeDomainCsvFileName.isEmpty())
   {
       ShowMessage(tr("未保存数据!"),1500);
   }
   else
   {
       QFile  MyFile(MyTimeDomainCsvFileName);
       if(!MyFile.exists())
       {
           MyFile.open(QIODevice::WriteOnly);
           QTextStream MytxtOutPut(&MyFile);
           MytxtOutPut << "UltrasonicDetectionSystem_TimeDoaminData\n";
           MytxtOutPut <<"Count,TimeDaomainData\n";
           MyFile.close();
       }
       MyFile.open(QIODevice::WriteOnly);
       QTextStream MytxtOutPut(&MyFile);
       QString MyData;
       for(uint16_t i=0;i<WaveXNum;i++)
       {
           MyData+=QString::number(i);
           MyData+=tr(",");
           MyData+=QString::number(WaveX[i]);
           MyData+=tr("\n");
       }
       MytxtOutPut << MyData;
       //MyFile.flush();
       MyFile.close();
       ShowMessage(tr("成功保存数据!"),1500);
   }
}
void TimeDomain::FindMaxMin()
{
   int MaxValue=0,MinValue=0;
   for(uint16_t i=4;i<WaveXNum;i++)
   {
       if(MaxValue<WaveX[i])
       {
           MaxValue=WaveX[i];
       }
       if(MinValue>WaveX[i])
       {
           MinValue=WaveX[i];
       }
   }
   ShowMessage(QString::number(WaveXNum),1500);
   ui->leTimeDomainMaxValue->setText(QString::number(MaxValue));
   ui->leTimeDomainMinValue->setText(QString::number(MinValue));
   ui->leTimeDomainMaxMinValue->setText(QString::number(MaxValue-MinValue));
}
void TimeDomain::SystemReset()
{
     QByteArray MyPulsePara;
     MyPulsePara.resize(5);

     MyPulsePara[0]=0x68;
     MyPulsePara[1]=0x04;
     MyPulsePara[2]=0x01;
     MyPulsePara[3]=0x00;
     MyPulsePara[4]=0x6D;

     this->WriteBytes(MyPulsePara);
 }
void TimeDomain::SelectStartPosition(int Value)
{
    QVector<double> VecXStart,VecYStart;
//    static uint8_t StartTimes=0;
//    if(StartTimes==0)
//    {
////        QPen MyPen(Qt::green,3,Qt::CustomDashLine);
////        ui->MyCustomPlot->addGraph();
////        ui->MyCustomPlot->graph(1)->setPen(MyPen);
//    }
//    else
    {
        ui->MyCustomPlot->graph(1)->data()->clear();
        WaveStart=Value;
        for(qint16 i=(WaveLine*-1);i<WaveLine;i++)
        {
            VecXStart.push_back(WaveStart);
            VecYStart.push_back(i);
        }
        ui->MyCustomPlot->graph(1)->setData(VecXStart,VecYStart);
        ui->MyCustomPlot->replot();
        StartPositionFlag=1;
    }
//    StartTimes++;
//    if(StartTimes==100)
//       StartTimes=0;
}
void TimeDomain::SelectEndPosition(int Value)
{
    QVector<double> VecXStart,VecYStart;
//    static uint8_t EndTimes=0;
//    if(EndTimes==0)
//    {
////        QPen MyPen(Qt::red,3,Qt::CustomDashLine);
////        ui->MyCustomPlot->addGraph();
////        ui->MyCustomPlot->graph(2)->setPen(MyPen);
//    }
//    else
    {

        ui->MyCustomPlot->graph(2)->data()->clear();
        WaveEnd=Value;
        for(qint16 i=(WaveLine*-1);i<WaveLine;i++)
        {
            VecXStart.push_back(WaveEnd);
            VecYStart.push_back(i);
        }
        ui->MyCustomPlot->graph(2)->setData(VecXStart,VecYStart);
        ui->MyCustomPlot->replot();
        EndPositionFlag=1;
    }
//    EndTimes++;
//    if(EndTimes==100)
//       EndTimes=0;
}
