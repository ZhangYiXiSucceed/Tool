#ifndef FREQUENCYDOMAIN_H
#define FREQUENCYDOMAIN_H

#include <QWidget>
#include <qcustomplot.h>
#include <QTimer>
#include <math.h>
#include <QPen>
#include "fftw/fftw3.h"
#include <QPixmap>
#include <QIcon>

#include<QDate>
#include<QTextStream>
#include<QFile>
#include<QDateTime>
#include<QFileDialog>

#define PI 3.1415
#define N 512
namespace Ui {
class FrequencyDomain;
}

class FrequencyDomain : public QWidget
{
    Q_OBJECT

public:
    explicit FrequencyDomain(QWidget *parent = 0);
    ~FrequencyDomain();
    void InitConnect();
    void InitUI();

signals:
    void Display(int);
    void ShowMessage(QString,uint16_t);
    void StartConfirm();
private slots:
    void DisplayTimeDomain();
    void DisplayDatabase();
    void Draw_FrequencyDomain_Wave();
    void TimeUpDate();
    void ClearWaves();
    void ChangeWaveStyle();
    void LoadTimeData();
    void ReadAndCalculate();
    void InquiryMaterial();
    void ConfirmHarm();
    void FindHarm();
    void RecSampleData(quint16,QVector<double>);
    void SaveFrequencyData();
private:
    Ui::FrequencyDomain *ui;
    QTimer   *MyTimer   = nullptr;

    QPixmap ImageFileStart=tr(":/Image/Start.png");
    QPixmap ImageFileStop=tr(":/Image/Stop.png");
    QPixmap ImageFileChange=tr(":/Image/Change.png");
    QPixmap ImageFileClearWaves=tr(":/Image/ClearWaves.png");
    QPixmap ImageFileReadCalcuate=tr(":/Image/ReadCalcuate.png");
    QPixmap ImageFileLoadData=tr(":/Image/LoadData.png");
    QPixmap ImageFileTimeDomain=tr(":/Image/FrequencyDomain.png");

    QPixmap ImageFileInquiry=tr(":/Image/Inquiry.png");
    QPixmap ImageFileConfirmHarm=tr(":/Image/ConfirmHarm.png");
    QPixmap ImageFileDatabase=tr(":/Image/Database.png");
    QPixmap ImageFileSaveData=tr(":/Image/SaveData.png");

    int  WaveX[2000];
    double WaveY[2000];
    bool DrawFreFlag;
    uint16_t WaveNum;
    bool ChangeFlag=false;

    bool ConfirmFlag;
    double YPlot[1100];
    double XAis[1100];

    double Y2Plot[1100];
    double X2Ais[1100];
    bool SearchFlag;

    double Y3Plot[1100];
    double X3Ais[1100];
    bool FindFlag;

    double Y4Plot[5000];
    double X4Ais[5000];
    bool FFTWFlag;

    double SampleData[5000];
    quint16 FFTLength;

    double BaseWave_2M_Value;
    double SecondHaemonic_4M_Value;


};

#endif // FREQUENCYDOMAIN_H
