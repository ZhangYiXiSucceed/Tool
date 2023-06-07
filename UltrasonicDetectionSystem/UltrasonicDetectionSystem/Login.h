#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QEventLoop>
#include <QCloseEvent>
#include <QMessageBox>
#include <QPixmap>
#include <QIcon>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    void InitUI();
    void InitConnect();
    int exec();
    void closeEvent(QCloseEvent *);
private:
    int m_ChooseResult;
    QEventLoop *m_eventLoop;
private slots:
    void GuidedWaves();
    void LongitudinalWave();
private:
    Ui::Login *ui;
    QPixmap ImageSchoolBadge=tr(":/Image/SchoolBadge.jpg");
    QPixmap ImageGuidedWaves=tr(":/Image/GuidedWaves.png");
    QPixmap ImageLongitudinalWave=tr(":/Image/LongitudinalWave.png");
};

#endif // LOGIN_H
