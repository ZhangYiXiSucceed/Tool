#include "UltrasonicDetectionSystem.h"
#include "ui_UltrasonicDetectionSystem.h"

UltrasonicDetectionSystem::UltrasonicDetectionSystem(QWidget *parent) :
    QMainWindow(parent),
    MyTimeDomain(new TimeDomain(this)),
    MyFrequencyDomain(new FrequencyDomain(this)),
    MyDatabase(new Database(this)),
    MyStackedLayout(new QStackedLayout(this)),
    MyVBoxLayout(new QVBoxLayout(this)),
    ui(new Ui::UltrasonicDetectionSystem)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

UltrasonicDetectionSystem::~UltrasonicDetectionSystem()
{
    delete ui;
}
void UltrasonicDetectionSystem::InitUI()
{
    MyStackedLayout->addWidget(MyTimeDomain);
    MyStackedLayout->addWidget(MyFrequencyDomain);
    MyStackedLayout->addWidget(MyDatabase);

    MyStackedLayout->setCurrentWidget(MyTimeDomain);

    MyVBoxLayout->addLayout(MyStackedLayout);
    this->setLayout(MyVBoxLayout);

    this->setWindowTitle(tr("超声波检测系统"));

    QFont Ft("Microsoft YaHei");
    Ft.setPointSize(12);

    statusBar()->setFont(Ft);

    ComPort=new QLabel();
    ComPort->setText(tr("端口：无"));
    this->ui->statusBar->addPermanentWidget(ComPort);
    BradRate=new QLabel();
    BradRate->setText(tr("波特率：无"));
    this->ui->statusBar->addPermanentWidget(BradRate);

    TextMessage+=tr("提示消息：");
    TextMessage+=tr("界面创建成功!");
    statusBar()->showMessage(TextMessage,3000);
}
void UltrasonicDetectionSystem::InitConnect()
{
    connect(MyTimeDomain,SIGNAL(Display(int)),MyStackedLayout,SLOT(setCurrentIndex(int)));
    connect(MyFrequencyDomain,SIGNAL(Display(int)),MyStackedLayout,SLOT(setCurrentIndex(int)));
    connect(MyDatabase,SIGNAL(Display(int)),MyStackedLayout,SLOT(setCurrentIndex(int)));
    connect(MyTimeDomain,SIGNAL(ShowMessage(QString,uint16_t)),this,SLOT(ShowSystemMessage(QString,uint16_t)));
    connect(MyTimeDomain,SIGNAL(ShowParameter(QString,QString)),this,SLOT(ShowParameter(QString,QString)));

    connect(MyFrequencyDomain,SIGNAL(ShowMessage(QString,uint16_t)),this,SLOT(ShowSystemMessage(QString,uint16_t)));
    connect(MyTimeDomain,SIGNAL(SendSampleData(quint16,QVector<double>)),MyFrequencyDomain,SLOT(RecSampleData(quint16,QVector<double>)));
}
void UltrasonicDetectionSystem::ShowSystemMessage(QString Message,uint16_t ShowTime)
{
    statusBar()->showMessage(Message,ShowTime);
}
void UltrasonicDetectionSystem::ShowParameter(QString ComPortData,QString BradRateData)
{
   ComPort->setText(tr("端口：")+ComPortData);
   this->ui->statusBar->addPermanentWidget(ComPort);
   BradRate->setText(tr("波特率：")+BradRateData);
   this->ui->statusBar->addPermanentWidget(BradRate);
}
