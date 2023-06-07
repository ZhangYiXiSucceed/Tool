#include "FrequencyDomain.h"
#include "ui_FrequencyDomain.h"

FrequencyDomain::FrequencyDomain(QWidget *parent) :
    QWidget(parent),
    MyTimer(new QTimer(this)),
    ui(new Ui::FrequencyDomain)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

FrequencyDomain::~FrequencyDomain()
{
    delete ui;
}
void FrequencyDomain::InitUI()
{
    ui->MyCustomPlot->xAxis->grid()->setSubGridVisible(true);
    ui->MyCustomPlot->xAxis->setLabel("频率    /MHZ");
    ui->MyCustomPlot->yAxis->setLabel("幅值    /mv");
    ui->MyCustomPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);

    QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
    ui->MyCustomPlot->yAxis->setTicker(logTicker);
    ui->MyCustomPlot->yAxis->setNumberFormat("f"); // e = exponential, b = beautiful decimal powers
    ui->MyCustomPlot->yAxis->setNumberPrecision(0); // makes sure "1*10^4" is displayed only as "10^4"
    ui->MyCustomPlot->yAxis->setRange(-1000, 1000);

    ui->MyCustomPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
    ui->MyCustomPlot->axisRect()->setupFullAxesBox();
    QFont Ft("Microsoft YaHei");
    Ft.setPointSize(12);

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

    ui->tbnClearWaves->setAutoRaise(true);
    ui->tbnClearWaves->setIcon(ImageFileClearWaves);
    ui->tbnClearWaves->setIconSize(ImageFileClearWaves.size());
    ui->tbnClearWaves->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnClearWaves->setFont(Ft);

    ui->tbnReadAndCalculate->setAutoRaise(true);
    ui->tbnReadAndCalculate->setIcon(ImageFileReadCalcuate);
    ui->tbnReadAndCalculate->setIconSize(ImageFileReadCalcuate.size());
    ui->tbnReadAndCalculate->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnReadAndCalculate->setFont(Ft);

    ui->tbnLoadTimeData->setAutoRaise(true);
    ui->tbnLoadTimeData->setIcon(ImageFileLoadData);
    ui->tbnLoadTimeData->setIconSize(ImageFileReadCalcuate.size());
    ui->tbnLoadTimeData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnLoadTimeData->setFont(Ft);

    ui->tbnTimeDomain->setAutoRaise(true);
    ui->tbnTimeDomain->setIcon(ImageFileTimeDomain);
    ui->tbnTimeDomain->setIconSize(ImageFileTimeDomain.size());
    ui->tbnTimeDomain->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnTimeDomain->setFont(Ft);

    ui->leFundamentalWave->setFont(Ft);
    ui->leSecondWave->setFont(Ft);
    ui->leNolinearPara->setFont(Ft);

    ui->tbnInquiry->setAutoRaise(true);
    ui->tbnInquiry->setIcon(ImageFileInquiry);
    ui->tbnInquiry->setIconSize(ImageFileInquiry.size());
    ui->tbnInquiry->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnInquiry->setFont(Ft);

    ui->tbnConfirmHarm->setAutoRaise(true);
    ui->tbnConfirmHarm->setIcon(ImageFileConfirmHarm);
    ui->tbnConfirmHarm->setIconSize(ImageFileConfirmHarm.size());
    ui->tbnConfirmHarm->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnConfirmHarm->setFont(Ft);

    ui->tbnSaveData->setAutoRaise(true);
    ui->tbnSaveData->setIcon(ImageFileSaveData);
    ui->tbnSaveData->setIconSize(ImageFileSaveData.size());
    ui->tbnSaveData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnSaveData->setFont(Ft);

    ui->tbnDatabase->setAutoRaise(true);
    ui->tbnDatabase->setIcon(ImageFileDatabase);
    ui->tbnDatabase->setIconSize(ImageFileDatabase.size());
    ui->tbnDatabase->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnDatabase->setFont(Ft);

    ui->tbnSaveFreData->setAutoRaise(true);
    ui->tbnSaveFreData->setIcon(ImageFileSaveData);
    ui->tbnSaveFreData->setIconSize(ImageFileSaveData.size());
    ui->tbnSaveFreData->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->tbnSaveFreData->setFont(Ft);

    ui->leMaterialNumber->setFont(Ft);
    ui->leMaterialType->setFont(Ft);
    ui->leHarmType->setFont(Ft);
    ui->leTestCondition->setFont(Ft);

    for(quint16 i=0;i<3000;i++)
        SampleData[i]=0;
    ChangeFlag=false;
    ConfirmFlag=false;
    DrawFreFlag=false;
    SearchFlag=false;
    FindFlag=false;
    FFTWFlag=false;
    FFTLength=0;
}
void FrequencyDomain::InitConnect()
{
    connect(ui->tbnTimeDomain,SIGNAL(clicked(bool)),this,SLOT(DisplayTimeDomain()));
    connect(ui->tbnDatabase,SIGNAL(clicked(bool)),this,SLOT(DisplayDatabase()));
    connect(MyTimer,SIGNAL(timeout()),this,SLOT(TimeUpDate()));
    connect(ui->tbnStartDraw,SIGNAL(clicked(bool)),this,SLOT(Draw_FrequencyDomain_Wave()));
    connect(ui->tbnClearWaves,SIGNAL(clicked(bool)),this,SLOT(ClearWaves()));
    connect(ui->tbnChangeWaveStyle,SIGNAL(clicked(bool)),this,SLOT(ChangeWaveStyle()));
    connect(ui->tbnLoadTimeData,SIGNAL(clicked(bool)),this,SLOT(LoadTimeData()));
    connect(ui->tbnReadAndCalculate,SIGNAL(clicked(bool)),this,SLOT(ReadAndCalculate()));

    connect(ui->tbnInquiry,SIGNAL(clicked(bool)),this,SLOT(InquiryMaterial()));
    connect(ui->tbnConfirmHarm,SIGNAL(clicked(bool)),this,SLOT(ConfirmHarm()));
    connect(this,SIGNAL(StartConfirm()),this,SLOT(FindHarm()));
    connect(ui->tbnSaveFreData,SIGNAL(clicked(bool)),this,SLOT(SaveFrequencyData()));

}
 void FrequencyDomain::DisplayTimeDomain()
 {
     emit Display(0);
 }
 void FrequencyDomain::DisplayDatabase()
 {
     emit Display(2);
 }
 void FrequencyDomain::Draw_FrequencyDomain_Wave()
 {
     ui->tbnStartDraw->setIcon(ImageFileStop);

     ui->MyCustomPlot->addGraph();
     ui->MyCustomPlot->graph(0)->setName(tr("Waves"));
     ui->MyCustomPlot->graph(0)->setPen(QPen(Qt::red,3));


     fftw_complex *in, *out;
     fftw_plan p;
     struct _complex z;
     //add code;
     in = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * FFTLength);
     out = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * FFTLength);

     for (int i = 0; i < FFTLength; i++)
     {
         in[i][0] = SampleData[i];//real
         in[i][1] = 0;//image
     }

     p = fftw_plan_dft_1d(FFTLength, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
     fftw_execute(p);


     for(quint16 i=0;i<FFTLength;i++)
     {
         X4Ais[i]=((double)65/FFTLength)*i;
         z.x=out[i][0];
         z.y=out[i][1];
         Y4Plot[i]=_cabs(z)/FFTLength*2;
         //X4Ais[i]=i;
         //Y4Plot[i]=in[i][0];
     }
     fftw_destroy_plan(p);
     fftw_free(in);
     fftw_free(out);
     MyTimer->start(10);
     FFTWFlag=true;
 }
 void FrequencyDomain::TimeUpDate()
 {
     if(FFTWFlag)
     {
      static quint16 IndexNum=0;
      double TempData =0;
      if(IndexNum<FFTLength/10)
      {
          TempData=Y4Plot[IndexNum];
//          if(ChangeFlag)
//          {
//              TempData=log10(TempData);
//          }
          if(TempData>BaseWave_2M_Value)
              BaseWave_2M_Value=TempData;
          if((X4Ais[IndexNum]>3.5)&&(X4Ais[IndexNum]<4.2))
          {
              if(TempData>SecondHaemonic_4M_Value)
                  SecondHaemonic_4M_Value=TempData;
          }
          ui->MyCustomPlot->graph(0)->addData(X4Ais[IndexNum],TempData);
          ui->MyCustomPlot->replot();
          ui->MyCustomPlot->rescaleAxes(true);
          IndexNum+=1;
      }
      else
      {
          MyTimer->stop();
          IndexNum=0;
          FFTWFlag=0;
          ui->tbnStartDraw->setIcon(ImageFileStart);
          ui->leFundamentalWave->setText(QString::number(BaseWave_2M_Value));
          ui->leSecondWave->setText(QString::number(SecondHaemonic_4M_Value));
          BaseWave_2M_Value=0;
          SecondHaemonic_4M_Value=0;
      }
     }
     if(DrawFreFlag)
     {
         static uint16_t i=0;
         double TempData =0;
         if(i<(80))
         {
             TempData = WaveY[i];
             if(ChangeFlag)
                 TempData=log10(TempData);
             ui->MyCustomPlot->graph(0)->addData(WaveX[i],TempData);
             ui->MyCustomPlot->replot();
             ui->MyCustomPlot->rescaleAxes(true);
             i++;
         }
         else
         {
             i=0;
             MyTimer->stop();
             ui->tbnStartDraw->setIcon(ImageFileStart);
             DrawFreFlag=false;
         }
     }
     if(ConfirmFlag)
     {
         static uint16_t j=0;
         if(j<100)
         {
             ui->MyCustomPlotNext->graph(0)->addData(XAis[j],YPlot[j]);
             ui->MyCustomPlotNext->replot();
             ui->MyCustomPlotNext->rescaleAxes(true);
             j++;
         }
         else
         {
             MyTimer->stop();
             ConfirmFlag=false;
             j=0;
         }
     }
     if(SearchFlag)
     {
         static uint16_t k=0;
         if(k<100)
         {
             ui->MyCustomPlotNext->graph(1)->addData(X2Ais[k],Y2Plot[k]);
             ui->MyCustomPlotNext->replot();
             ui->MyCustomPlotNext->rescaleAxes(true);
             k++;
         }
         else
         {
             MyTimer->stop();
             SearchFlag=false;
             k=0;
             emit StartConfirm();
         }
     }
     if(FindFlag)
     {
         static uint16_t l=0;
         if(l<20)
         {
             ui->MyCustomPlotNext->graph(2)->addData(X3Ais[l],Y3Plot[l]);
             ui->MyCustomPlotNext->replot();
             ui->MyCustomPlotNext->rescaleAxes(true);
             l++;
         }
         else
         {
             MyTimer->stop();
             FindFlag=false;
             l=0;
         }
     }
 }
void FrequencyDomain::ClearWaves()
{
    ui->MyCustomPlot->graph(0)->data()->clear();
    ui->MyCustomPlot->replot();
}
void FrequencyDomain::ChangeWaveStyle()
{
    ChangeFlag=!ChangeFlag;
    if(ChangeFlag)
    {
      ui->MyCustomPlot->yAxis->setScaleType(QCPAxis::stLinear);

      QSharedPointer<QCPAxisTickerFixed> FixedTicker(new QCPAxisTickerFixed);
      FixedTicker->setScaleStrategy(QCPAxisTickerFixed::ssMultiples);
      ui->MyCustomPlot->yAxis->setTicker(FixedTicker);

      ui->MyCustomPlot->yAxis->setNumberFormat("f");
      ui->MyCustomPlot->yAxis->setRange(-1000, 1000);
      ui->MyCustomPlot->yAxis->setLabel("幅值    /mv");

      emit ui->tbnStartDraw->click();
    }
    else
    {
        ui->MyCustomPlot->yAxis->setScaleType(QCPAxis::stLogarithmic);

        QSharedPointer<QCPAxisTickerLog> logTicker(new QCPAxisTickerLog);
        logTicker->setTickStepStrategy(QCPAxisTickerLog::tssMeetTickCount);
        ui->MyCustomPlot->yAxis->setTicker(logTicker);
        ui->MyCustomPlot->yAxis->setNumberFormat("f"); // e = exponential, b = beautiful decimal powers
        ui->MyCustomPlot->yAxis->setNumberPrecision(0); // makes sure "1*10^4" is displayed only as "10^4"
        ui->MyCustomPlot->yAxis->setRange(-1000, 1000);
        ui->MyCustomPlot->yAxis->setLabel("对数显示幅值   /mv");
        emit ui->tbnStartDraw->click();
    }
}
void FrequencyDomain::LoadTimeData()
{
    QString MyTimeDomainCsvFileName=QFileDialog::getOpenFileName(this, tr("Excel file"),QApplication::applicationDirPath () + \
                                                        QDateTime::currentDateTime().toString("yyyyMMdd")+ ".csv",
                                                        tr("Files (*.csv);;AllFiles (*.*)"));
    if(MyTimeDomainCsvFileName.isEmpty())
    {
        ShowMessage(tr("未打开任何数据文本!"),3000);
    }
    else
    {
        QFile  MyFile(MyTimeDomainCsvFileName);
        if(!MyFile.open(QIODevice::ReadOnly|QIODevice::Text))
        {
           ShowMessage(tr("该文件不存在！"),3000);
           return;
        }
        QTextStream MytxtOutPut(&MyFile);
        QString MyData;
        QString TempData;
        WaveNum=0;
        while(!MytxtOutPut.atEnd())
        {
            MyData=MytxtOutPut.readLine();

            TempData=MyData;
            TempData=TempData.split(tr(",")).last();
            WaveX[WaveNum]=TempData.toInt();

            TempData=MyData;
            TempData=TempData.split(tr(",")).first();
            WaveY[WaveNum]=TempData.toDouble();

            WaveNum++;
        }
        //MyFile.flush();
        MyFile.close();
        ShowMessage(tr("成功读取数据!"),3000);
    }
}
void FrequencyDomain::ReadAndCalculate()
{
    double NolinearPara = 0;
    double FundamentalWaveValue = pow(ui->leFundamentalWave->text().toDouble(),2);
    double SecondWaveValue = ui->leSecondWave->text().toDouble();

    NolinearPara = SecondWaveValue/FundamentalWaveValue;

    ui->leNolinearPara->setText(QString::number(NolinearPara));
}
void FrequencyDomain::InquiryMaterial()
{
    if(ui->leMaterialNumber->text()==tr("01"))
    {
        ui->leMaterialType->setText(tr("铝合金材料"));
        ui->leHarmType->setText(tr("压力拉伸"));
        ui->leTestCondition->setText(tr("室温环境"));

        ui->MyCustomPlotNext->xAxis->setLabel("损失程度/%");
        ui->MyCustomPlotNext->yAxis->setLabel("非线性参量值/β");
        ui->MyCustomPlotNext->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom);
        ui->MyCustomPlotNext->addGraph();
        ui->MyCustomPlotNext->graph(0)->setName(tr("Waves"));
        ui->MyCustomPlotNext->graph(0)->setPen(QPen(Qt::green,3));


        for(uint16_t i=0;i<100;i++)
        {
            XAis[i]=i;
            YPlot[i]=(pow(XAis[i],3))/1000000;
        }

        ConfirmFlag=true;
        MyTimer->start(20);

    }
    else if(ui->leMaterialNumber->text()==tr("02"))
    {
        ui->leMaterialType->setText(tr("铝合金材料"));
        ui->leHarmType->setText(tr("高温蠕变"));
        ui->leTestCondition->setText(tr("室温环境"));
    }
    else if(ui->leMaterialNumber->text()==tr("03"))
    {
        ui->leMaterialType->setText(tr("钢铁材料"));
        ui->leHarmType->setText(tr("高温蠕变"));
        ui->leTestCondition->setText(tr("室温环境"));
    }
}
void FrequencyDomain::ConfirmHarm()
{
    ui->MyCustomPlotNext->addGraph();
    ui->MyCustomPlotNext->graph(1)->setName(tr("Waves"));
    ui->MyCustomPlotNext->graph(1)->setPen(QPen(Qt::blue,3));


    for(uint16_t i=0;i<100;i++)
    {
        X2Ais[i]=i;
        Y2Plot[i]=ui->leNolinearPara->text().toDouble();
    }

    SearchFlag=true;
    MyTimer->start(20);
}
void FrequencyDomain::FindHarm()
{

    for(int i=0;i<100;i++)
    {
        if(fabs(YPlot[i]-ui->leNolinearPara->text().toDouble())<0.01)
        {
            X3Ais[0]=XAis[i];
            break;
        }
    }

    ui->MyCustomPlotNext->addGraph();
    ui->MyCustomPlotNext->graph(2)->setName(tr("Waves"));
    ui->MyCustomPlotNext->graph(2)->setPen(QPen(Qt::red,3));


    for(uint16_t i=0;i<20;i++)
    {
        X3Ais[i]=X3Ais[0];
        Y3Plot[i]=i/10;
    }

    FindFlag=true;
    MyTimer->start(20);
}
void FrequencyDomain::RecSampleData(quint16 SampleLength,QVector<double> TimeDomainData)
{
  for(quint16 i=0;i<SampleLength;i++)
  {
      SampleData[i]=TimeDomainData[i];
  }
  FFTLength=SampleLength;
}
void FrequencyDomain::SaveFrequencyData()
{
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
        for(uint16_t i=0;i<FFTLength;i++)
        {
            MyData+=QString::number(X4Ais[i]);
            MyData+=tr(",");
            MyData+=QString::number(Y4Plot[i]);
            MyData+=tr("\n");
        }
        MytxtOutPut << MyData;
        //MyFile.flush();
        MyFile.close();
        ShowMessage(tr("成功保存数据!"),1500);
    }
}
