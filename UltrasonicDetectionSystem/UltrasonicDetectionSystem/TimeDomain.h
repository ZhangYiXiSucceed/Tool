#ifndef TIMEDOMAIN_H
#define TIMEDOMAIN_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <qcustomplot.h>
#include <math.h>
#include <QTimer>
#include <QList>
#include <QVector>
#include <algorithm>

#include<QDate>
#include<QTextStream>
#include<QFile>
#include<QDateTime>

#define   PI 3.1415
#define   Developer    0
#define   WaveLine   1500
#define   Debug   0
#define   REFVol   250

namespace Ui {
class TimeDomain;
}

class TimeDomain : public QWidget
{
    Q_OBJECT

public:
    explicit TimeDomain(QWidget *parent = 0);
    ~TimeDomain();
    void InitConnect();
    void InitUI();
    void Refresh();
    void WriteBytes(QByteArray);
    void PrintFrameData(QByteArray ,uint16_t);
    uint8_t FindFrameHead(QByteArray ,uint16_t);
    bool IsCheckSumRight(QByteArray ,uint16_t);
    void RunCommand(QByteArray ,uint16_t &);
    void RecSampleData(quint8);
    void CheckoutError(quint8);
    void RespondError(quint8);
signals:
    void Display(int);
private slots:
    void DisplayFrequencyDomainNext();
    void Draw_TimeDomain_Wave();
    void TimeUpDate();
    void ClearWaves();
    void ConnectComPort();
    void ReadRecData();
    void WritePulsePara();
    void ChangeWaveStyle();
    void ReadPulsePara();
    void SaveTimeDomainData();
    void FindMaxMin();
    void SystemReset();
    void SelectEndPosition(int);
    void SelectStartPosition(int);
    void FrameRecDataProcess();
signals:
    void ShowMessage(QString,uint16_t);
    void ShowParameter(QString,QString);
    void RecFinish();
    void SendSampleData(quint16,QVector<double>);
private:
    Ui::TimeDomain *ui;
    QTimer   *MyTimer    =  nullptr;
    QTimer   *MyTimer2   =  nullptr;
    QSerialPort     *MySerialPort     = nullptr;
    QByteArray FrameRecData;

    double WaveX[5000];
    int WaveXNum;
    uint8_t ConnectTimes;
    bool DrawFlag;
    bool ConnectFlag;
    bool StartPositionFlag;
    bool EndPositionFlag;
    bool RespondFlag;


    int WaveStart;
    int WaveEnd;


    QPixmap ImageFileOpen=tr(":/Image/Close.png");
    QPixmap ImageFileClose=tr(":/Image/Open.png");
    QPixmap ImageFileStart=tr(":/Image/Start.png");
    QPixmap ImageFileStop=tr(":/Image/Stop.png");
    QPixmap ImageFileChange=tr(":/Image/Change.png");
    QPixmap ImageFileSaveData=tr(":/Image/SaveData.png");
    QPixmap ImageFileClearWaves=tr(":/Image/ClearWaves.png");
    QPixmap ImageFileFrequencyDomain=tr(":/Image/FrequencyDomain.png");
    QPixmap ImageFileReadPulsePara=tr(":/Image/ReadPara.png");
    QPixmap ImageFileWritePulsePara=tr(":/Image/WritePara.png");
    QPixmap ImageFileLoadData=tr(":/Image/LoadData.png");
    QPixmap ImageFileReset=tr(":/Image/Reset.png");
};

#endif // TIMEDOMAIN_H
