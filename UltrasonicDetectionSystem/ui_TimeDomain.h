/********************************************************************************
** Form generated from reading UI file 'TimeDomain.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMEDOMAIN_H
#define UI_TIMEDOMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_TimeDomain
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lePulseFrequency;
    QLineEdit *lePulseNum;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lePulseInterval;
    QLabel *label_6;
    QLabel *label_13;
    QLineEdit *leAverageTimes;
    QLabel *label_14;
    QLineEdit *leSampleNum;
    QLabel *label_17;
    QSpinBox *spStartPosition;
    QSpinBox *spEndPosition;
    QLabel *label_4;
    QToolButton *tbnReadPulsePara;
    QToolButton *tbnWritePulsePara;
    QLabel *label_21;
    QSpinBox *spDelayTime;
    QGroupBox *groupBox_3;
    QToolButton *tbnFrequencyDomainNext;
    QToolButton *tbnSaveData;
    QToolButton *tbnStartDraw;
    QToolButton *tbnClearWaves;
    QToolButton *tbnChangeWaveStyle;
    QToolButton *tbnLoadData;
    QToolButton *tbnConnect;
    QToolButton *tbnReset;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *leTimeDomainMinValue;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *leTimeDomainMaxValue;
    QLineEdit *leTimeDomainMaxMinValue;
    QComboBox *comboBoxComPort;
    QLabel *leDotNum;
    QLabel *leDotText;
    QGroupBox *groupBox_2;
    QCustomPlot *MyCustomPlot;

    void setupUi(QWidget *TimeDomain)
    {
        if (TimeDomain->objectName().isEmpty())
            TimeDomain->setObjectName(QStringLiteral("TimeDomain"));
        TimeDomain->resize(1143, 755);
        groupBox = new QGroupBox(TimeDomain);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 771, 181));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 72, 31));
        lePulseFrequency = new QLineEdit(groupBox);
        lePulseFrequency->setObjectName(QStringLiteral("lePulseFrequency"));
        lePulseFrequency->setGeometry(QRect(80, 30, 113, 31));
        lePulseNum = new QLineEdit(groupBox);
        lePulseNum->setObjectName(QStringLiteral("lePulseNum"));
        lePulseNum->setGeometry(QRect(500, 30, 113, 31));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 30, 72, 31));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(200, 30, 31, 31));
        lePulseInterval = new QLineEdit(groupBox);
        lePulseInterval->setObjectName(QStringLiteral("lePulseInterval"));
        lePulseInterval->setGeometry(QRect(80, 130, 113, 31));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 72, 31));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(230, 80, 72, 31));
        leAverageTimes = new QLineEdit(groupBox);
        leAverageTimes->setObjectName(QStringLiteral("leAverageTimes"));
        leAverageTimes->setGeometry(QRect(300, 80, 113, 31));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(230, 30, 72, 31));
        leSampleNum = new QLineEdit(groupBox);
        leSampleNum->setObjectName(QStringLiteral("leSampleNum"));
        leSampleNum->setGeometry(QRect(300, 30, 113, 31));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(200, 130, 31, 31));
        spStartPosition = new QSpinBox(groupBox);
        spStartPosition->setObjectName(QStringLiteral("spStartPosition"));
        spStartPosition->setGeometry(QRect(300, 130, 111, 31));
        spEndPosition = new QSpinBox(groupBox);
        spEndPosition->setObjectName(QStringLiteral("spEndPosition"));
        spEndPosition->setGeometry(QRect(500, 130, 111, 31));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(200, 80, 31, 31));
        tbnReadPulsePara = new QToolButton(groupBox);
        tbnReadPulsePara->setObjectName(QStringLiteral("tbnReadPulsePara"));
        tbnReadPulsePara->setGeometry(QRect(640, 120, 121, 41));
        tbnWritePulsePara = new QToolButton(groupBox);
        tbnWritePulsePara->setObjectName(QStringLiteral("tbnWritePulsePara"));
        tbnWritePulsePara->setGeometry(QRect(640, 30, 121, 41));
        label_21 = new QLabel(groupBox);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(10, 80, 72, 31));
        spDelayTime = new QSpinBox(groupBox);
        spDelayTime->setObjectName(QStringLiteral("spDelayTime"));
        spDelayTime->setGeometry(QRect(80, 80, 111, 31));
        groupBox_3 = new QGroupBox(TimeDomain);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(800, 20, 331, 231));
        tbnFrequencyDomainNext = new QToolButton(groupBox_3);
        tbnFrequencyDomainNext->setObjectName(QStringLiteral("tbnFrequencyDomainNext"));
        tbnFrequencyDomainNext->setGeometry(QRect(200, 20, 121, 41));
        tbnSaveData = new QToolButton(groupBox_3);
        tbnSaveData->setObjectName(QStringLiteral("tbnSaveData"));
        tbnSaveData->setGeometry(QRect(30, 120, 121, 41));
        tbnStartDraw = new QToolButton(groupBox_3);
        tbnStartDraw->setObjectName(QStringLiteral("tbnStartDraw"));
        tbnStartDraw->setGeometry(QRect(30, 70, 121, 41));
        tbnClearWaves = new QToolButton(groupBox_3);
        tbnClearWaves->setObjectName(QStringLiteral("tbnClearWaves"));
        tbnClearWaves->setGeometry(QRect(30, 170, 121, 41));
        tbnChangeWaveStyle = new QToolButton(groupBox_3);
        tbnChangeWaveStyle->setObjectName(QStringLiteral("tbnChangeWaveStyle"));
        tbnChangeWaveStyle->setGeometry(QRect(200, 170, 121, 41));
        tbnLoadData = new QToolButton(groupBox_3);
        tbnLoadData->setObjectName(QStringLiteral("tbnLoadData"));
        tbnLoadData->setGeometry(QRect(200, 120, 121, 41));
        tbnConnect = new QToolButton(groupBox_3);
        tbnConnect->setObjectName(QStringLiteral("tbnConnect"));
        tbnConnect->setGeometry(QRect(30, 20, 121, 41));
        tbnReset = new QToolButton(groupBox_3);
        tbnReset->setObjectName(QStringLiteral("tbnReset"));
        tbnReset->setGeometry(QRect(200, 70, 121, 41));
        label_15 = new QLabel(TimeDomain);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(250, 150, 72, 31));
        label_16 = new QLabel(TimeDomain);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(450, 150, 72, 31));
        leTimeDomainMinValue = new QLineEdit(TimeDomain);
        leTimeDomainMinValue->setObjectName(QStringLiteral("leTimeDomainMinValue"));
        leTimeDomainMinValue->setGeometry(QRect(300, 220, 113, 31));
        label_18 = new QLabel(TimeDomain);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(30, 220, 61, 31));
        label_19 = new QLabel(TimeDomain);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(240, 220, 61, 31));
        label_20 = new QLabel(TimeDomain);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(450, 220, 61, 31));
        leTimeDomainMaxValue = new QLineEdit(TimeDomain);
        leTimeDomainMaxValue->setObjectName(QStringLiteral("leTimeDomainMaxValue"));
        leTimeDomainMaxValue->setGeometry(QRect(90, 220, 113, 31));
        leTimeDomainMaxMinValue = new QLineEdit(TimeDomain);
        leTimeDomainMaxMinValue->setObjectName(QStringLiteral("leTimeDomainMaxMinValue"));
        leTimeDomainMaxMinValue->setGeometry(QRect(510, 220, 113, 31));
        comboBoxComPort = new QComboBox(TimeDomain);
        comboBoxComPort->setObjectName(QStringLiteral("comboBoxComPort"));
        comboBoxComPort->setGeometry(QRect(650, 220, 141, 31));
        leDotNum = new QLabel(TimeDomain);
        leDotNum->setObjectName(QStringLiteral("leDotNum"));
        leDotNum->setGeometry(QRect(720, 220, 72, 31));
        leDotText = new QLabel(TimeDomain);
        leDotText->setObjectName(QStringLiteral("leDotText"));
        leDotText->setGeometry(QRect(640, 220, 81, 31));
        groupBox_2 = new QGroupBox(TimeDomain);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 260, 1121, 481));
        MyCustomPlot = new QCustomPlot(groupBox_2);
        MyCustomPlot->setObjectName(QStringLiteral("MyCustomPlot"));
        MyCustomPlot->setGeometry(QRect(10, 20, 1091, 441));

        retranslateUi(TimeDomain);

        QMetaObject::connectSlotsByName(TimeDomain);
    } // setupUi

    void retranslateUi(QWidget *TimeDomain)
    {
        TimeDomain->setWindowTitle(QApplication::translate("TimeDomain", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("TimeDomain", "\346\277\200\345\217\221\350\204\211\345\206\262\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("TimeDomain", "\350\204\211\345\206\262\351\242\221\347\216\207\357\274\232", nullptr));
        lePulseNum->setText(QString());
        label_2->setText(QApplication::translate("TimeDomain", "\350\204\211\345\206\262\344\270\252\346\225\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("TimeDomain", "HZ", nullptr));
        lePulseInterval->setText(QString());
        label_6->setText(QApplication::translate("TimeDomain", "\350\204\211\345\206\262\351\227\264\351\232\224\357\274\232", nullptr));
        label_13->setText(QApplication::translate("TimeDomain", "\345\271\263\345\235\207\346\254\241\346\225\260\357\274\232", nullptr));
        leAverageTimes->setText(QString());
        label_14->setText(QApplication::translate("TimeDomain", "\351\207\207\346\240\267\347\202\271\346\225\260\357\274\232", nullptr));
        leSampleNum->setText(QString());
        label_17->setText(QApplication::translate("TimeDomain", "HZ", nullptr));
        label_4->setText(QApplication::translate("TimeDomain", "us", nullptr));
        tbnReadPulsePara->setText(QApplication::translate("TimeDomain", "\350\257\273\345\217\226", nullptr));
        tbnWritePulsePara->setText(QApplication::translate("TimeDomain", "\345\206\231\345\205\245", nullptr));
        label_21->setText(QApplication::translate("TimeDomain", "\345\273\266\350\277\237\346\227\266\351\227\264\357\274\232", nullptr));
        groupBox_3->setTitle(QApplication::translate("TimeDomain", "\346\265\213\351\207\217\346\223\215\344\275\234", nullptr));
        tbnFrequencyDomainNext->setText(QApplication::translate("TimeDomain", "\351\242\221\345\237\237", nullptr));
        tbnSaveData->setText(QApplication::translate("TimeDomain", "\344\277\235\345\255\230", nullptr));
        tbnStartDraw->setText(QApplication::translate("TimeDomain", "\345\274\200\345\247\213", nullptr));
        tbnClearWaves->setText(QApplication::translate("TimeDomain", "\346\270\205\347\251\272", nullptr));
        tbnChangeWaveStyle->setText(QApplication::translate("TimeDomain", "\345\210\207\346\215\242", nullptr));
        tbnLoadData->setText(QApplication::translate("TimeDomain", "\345\257\274\345\205\245", nullptr));
        tbnConnect->setText(QApplication::translate("TimeDomain", "\350\277\236\346\216\245", nullptr));
        tbnReset->setText(QApplication::translate("TimeDomain", "\345\244\215\344\275\215", nullptr));
        label_15->setText(QApplication::translate("TimeDomain", "\350\265\267\345\247\213\344\275\215\347\275\256\357\274\232", nullptr));
        label_16->setText(QApplication::translate("TimeDomain", "\347\273\210\346\255\242\344\275\215\347\275\256\357\274\232", nullptr));
        leTimeDomainMinValue->setText(QString());
        label_18->setText(QApplication::translate("TimeDomain", "\346\234\200\345\244\247\345\200\274\357\274\232\357\274\232", nullptr));
        label_19->setText(QApplication::translate("TimeDomain", "\346\234\200\345\260\217\345\200\274\357\274\232", nullptr));
        label_20->setText(QApplication::translate("TimeDomain", "\345\263\260\345\263\260\345\200\274\357\274\232", nullptr));
        leTimeDomainMaxValue->setText(QString());
        leTimeDomainMaxMinValue->setText(QString());
        leDotNum->setText(QApplication::translate("TimeDomain", "0", nullptr));
        leDotText->setText(QApplication::translate("TimeDomain", "\347\224\273\347\202\271\344\270\252\346\225\260\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("TimeDomain", "\346\227\266\345\237\237\346\263\242\345\275\242\345\261\225\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeDomain: public Ui_TimeDomain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMEDOMAIN_H
