#include "Login.h"
#include "ui_Login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

Login::~Login()
{
    delete ui;
}
void Login::InitUI()
{
   QFont Ft("Microsoft YaHei");
   Ft.setPointSize(12);

   ImageSchoolBadge.scaled(ui->LabelPicture->size(),Qt::KeepAspectRatio);
   ui->LabelPicture->setScaledContents(true);
   ui->LabelPicture->setPixmap(ImageSchoolBadge);
   ui->LabelPicture->setAlignment(Qt::AlignCenter);
   ui->LabelPicture->show();

   ui->tbnGuidedWaves->setAutoRaise(true);
   ui->tbnGuidedWaves->setIcon(ImageGuidedWaves);
   ui->tbnGuidedWaves->setIconSize(ImageGuidedWaves.size());
   ui->tbnGuidedWaves->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
   ui->tbnGuidedWaves->setFont(Ft);

   ui->tbnLongitudinalWave->setAutoRaise(true);
   ui->tbnLongitudinalWave->setIcon(ImageLongitudinalWave);
   ui->tbnLongitudinalWave->setIconSize(ImageLongitudinalWave.size());
   ui->tbnLongitudinalWave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
   ui->tbnLongitudinalWave->setFont(Ft);

   this->setWindowTitle(tr("超声波检测系统"));
}
void Login::InitConnect()
{
    connect(ui->tbnGuidedWaves,SIGNAL(clicked(bool)),this,SLOT(GuidedWaves()));
    connect(ui->tbnLongitudinalWave,SIGNAL(clicked(bool)),this,SLOT(LongitudinalWave()));
}
int Login::exec()
{
    this->setWindowModality(Qt::ApplicationModal);
    show();
    m_eventLoop = new QEventLoop(this);
    m_eventLoop->exec();
    return m_ChooseResult;
}
void Login::GuidedWaves()
{
      m_ChooseResult = Accepted;
      this->close();
}
void Login::LongitudinalWave()
{
     m_ChooseResult = Rejected;
     this->close();
}
void Login::closeEvent(QCloseEvent *event)
{
    if(m_eventLoop!=NULL)
    {
        m_eventLoop->exit();
    }
    event->accept();
}
