#ifndef ULTRASONICDETECTIONSYSTEM_H
#define ULTRASONICDETECTIONSYSTEM_H

#include <QMainWindow>
#include <Login.h>
#include <TimeDomain.h>
#include <FrequencyDomain.h>
#include <Database.h>

#include <QStackedLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QWidget>
#include <QFont>
#include <QLabel>
namespace Ui {
class UltrasonicDetectionSystem;
}

class UltrasonicDetectionSystem : public QMainWindow
{
    Q_OBJECT

public:
    explicit UltrasonicDetectionSystem(QWidget *parent = 0);
    ~UltrasonicDetectionSystem();
   void InitUI();
   void InitConnect();
private slots:
    void ShowSystemMessage(QString,uint16_t);
    void ShowParameter(QString,QString);
private:
    Ui::UltrasonicDetectionSystem *ui;
    TimeDomain       *MyTimeDomain              =  nullptr;
    FrequencyDomain  *MyFrequencyDomain         =  nullptr;
    Database         *MyDatabase                =  nullptr;

    QStackedLayout   *MyStackedLayout           =  nullptr;
    QVBoxLayout      *MyVBoxLayout              =  nullptr;

    QLabel *BradRate;
    QLabel *ComPort;
    QString TextMessage;
};

#endif // ULTRASONICDETECTIONSYSTEM_H
