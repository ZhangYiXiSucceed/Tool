/********************************************************************************
** Form generated from reading UI file 'FrequencyDomain.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FREQUENCYDOMAIN_H
#define UI_FREQUENCYDOMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FrequencyDomain
{
public:
    QGroupBox *groupBox;
    QCustomPlot *MyCustomPlot;
    QGroupBox *groupBox_2;
    QCustomPlot *MyCustomPlotNext;
    QToolButton *tbnDatabase;
    QToolButton *tbnTimeDomain;
    QToolButton *tbnChangeWaveStyle;
    QLineEdit *leFundamentalWave;
    QLabel *label_16;
    QLabel *label_17;
    QLineEdit *leSecondWave;
    QLabel *label_18;
    QLineEdit *leNolinearPara;
    QToolButton *tbnReadAndCalculate;
    QLineEdit *leMaterialNumber;
    QLabel *label_19;
    QLineEdit *leMaterialType;
    QLabel *label_20;
    QLineEdit *leHarmType;
    QLabel *le_2;
    QLineEdit *leTestCondition;
    QLabel *le;
    QToolButton *tbnInquiry;
    QToolButton *tbnConfirmHarm;
    QToolButton *tbnSaveData;
    QToolButton *tbnStartDraw;
    QToolButton *tbnClearWaves;
    QToolButton *tbnLoadTimeData;
    QToolButton *tbnSaveFreData;

    void setupUi(QWidget *FrequencyDomain)
    {
        if (FrequencyDomain->objectName().isEmpty())
            FrequencyDomain->setObjectName(QStringLiteral("FrequencyDomain"));
        FrequencyDomain->resize(1143, 745);
        groupBox = new QGroupBox(FrequencyDomain);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 1001, 431));
        MyCustomPlot = new QCustomPlot(groupBox);
        MyCustomPlot->setObjectName(QStringLiteral("MyCustomPlot"));
        MyCustomPlot->setGeometry(QRect(10, 20, 981, 351));
        groupBox_2 = new QGroupBox(FrequencyDomain);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 450, 871, 281));
        MyCustomPlotNext = new QCustomPlot(groupBox_2);
        MyCustomPlotNext->setObjectName(QStringLiteral("MyCustomPlotNext"));
        MyCustomPlotNext->setGeometry(QRect(10, 20, 851, 241));
        tbnDatabase = new QToolButton(FrequencyDomain);
        tbnDatabase->setObjectName(QStringLiteral("tbnDatabase"));
        tbnDatabase->setGeometry(QRect(1020, 680, 111, 41));
        tbnTimeDomain = new QToolButton(FrequencyDomain);
        tbnTimeDomain->setObjectName(QStringLiteral("tbnTimeDomain"));
        tbnTimeDomain->setGeometry(QRect(1020, 320, 111, 41));
        tbnChangeWaveStyle = new QToolButton(FrequencyDomain);
        tbnChangeWaveStyle->setObjectName(QStringLiteral("tbnChangeWaveStyle"));
        tbnChangeWaveStyle->setGeometry(QRect(1020, 220, 111, 41));
        leFundamentalWave = new QLineEdit(FrequencyDomain);
        leFundamentalWave->setObjectName(QStringLiteral("leFundamentalWave"));
        leFundamentalWave->setGeometry(QRect(110, 390, 113, 31));
        label_16 = new QLabel(FrequencyDomain);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(0, 390, 101, 31));
        label_16->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_17 = new QLabel(FrequencyDomain);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(240, 390, 111, 31));
        leSecondWave = new QLineEdit(FrequencyDomain);
        leSecondWave->setObjectName(QStringLiteral("leSecondWave"));
        leSecondWave->setGeometry(QRect(350, 390, 113, 31));
        label_18 = new QLabel(FrequencyDomain);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(480, 390, 111, 31));
        leNolinearPara = new QLineEdit(FrequencyDomain);
        leNolinearPara->setObjectName(QStringLiteral("leNolinearPara"));
        leNolinearPara->setGeometry(QRect(590, 390, 113, 31));
        tbnReadAndCalculate = new QToolButton(FrequencyDomain);
        tbnReadAndCalculate->setObjectName(QStringLiteral("tbnReadAndCalculate"));
        tbnReadAndCalculate->setGeometry(QRect(1020, 170, 111, 41));
        leMaterialNumber = new QLineEdit(FrequencyDomain);
        leMaterialNumber->setObjectName(QStringLiteral("leMaterialNumber"));
        leMaterialNumber->setGeometry(QRect(1000, 460, 131, 31));
        label_19 = new QLabel(FrequencyDomain);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(910, 460, 91, 31));
        leMaterialType = new QLineEdit(FrequencyDomain);
        leMaterialType->setObjectName(QStringLiteral("leMaterialType"));
        leMaterialType->setGeometry(QRect(1000, 500, 131, 31));
        label_20 = new QLabel(FrequencyDomain);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(910, 500, 91, 31));
        leHarmType = new QLineEdit(FrequencyDomain);
        leHarmType->setObjectName(QStringLiteral("leHarmType"));
        leHarmType->setGeometry(QRect(1000, 540, 131, 31));
        le_2 = new QLabel(FrequencyDomain);
        le_2->setObjectName(QStringLiteral("le_2"));
        le_2->setGeometry(QRect(910, 540, 91, 31));
        leTestCondition = new QLineEdit(FrequencyDomain);
        leTestCondition->setObjectName(QStringLiteral("leTestCondition"));
        leTestCondition->setGeometry(QRect(1000, 580, 131, 31));
        le = new QLabel(FrequencyDomain);
        le->setObjectName(QStringLiteral("le"));
        le->setGeometry(QRect(910, 580, 91, 31));
        tbnInquiry = new QToolButton(FrequencyDomain);
        tbnInquiry->setObjectName(QStringLiteral("tbnInquiry"));
        tbnInquiry->setGeometry(QRect(890, 620, 111, 41));
        tbnConfirmHarm = new QToolButton(FrequencyDomain);
        tbnConfirmHarm->setObjectName(QStringLiteral("tbnConfirmHarm"));
        tbnConfirmHarm->setGeometry(QRect(1020, 620, 111, 41));
        tbnSaveData = new QToolButton(FrequencyDomain);
        tbnSaveData->setObjectName(QStringLiteral("tbnSaveData"));
        tbnSaveData->setGeometry(QRect(890, 680, 111, 41));
        tbnStartDraw = new QToolButton(FrequencyDomain);
        tbnStartDraw->setObjectName(QStringLiteral("tbnStartDraw"));
        tbnStartDraw->setGeometry(QRect(1020, 20, 111, 41));
        tbnClearWaves = new QToolButton(FrequencyDomain);
        tbnClearWaves->setObjectName(QStringLiteral("tbnClearWaves"));
        tbnClearWaves->setGeometry(QRect(1020, 270, 111, 41));
        tbnLoadTimeData = new QToolButton(FrequencyDomain);
        tbnLoadTimeData->setObjectName(QStringLiteral("tbnLoadTimeData"));
        tbnLoadTimeData->setGeometry(QRect(1020, 70, 111, 41));
        tbnSaveFreData = new QToolButton(FrequencyDomain);
        tbnSaveFreData->setObjectName(QStringLiteral("tbnSaveFreData"));
        tbnSaveFreData->setGeometry(QRect(1020, 120, 111, 41));

        retranslateUi(FrequencyDomain);

        QMetaObject::connectSlotsByName(FrequencyDomain);
    } // setupUi

    void retranslateUi(QWidget *FrequencyDomain)
    {
        FrequencyDomain->setWindowTitle(QApplication::translate("FrequencyDomain", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("FrequencyDomain", "\351\242\221\345\237\237\346\263\242\345\275\242\345\261\225\347\244\272", nullptr));
        groupBox_2->setTitle(QApplication::translate("FrequencyDomain", "\346\235\220\346\226\231\345\257\277\345\221\275\351\242\204\344\274\260", nullptr));
        tbnDatabase->setText(QApplication::translate("FrequencyDomain", "\346\225\260\346\215\256\345\272\223", nullptr));
        tbnTimeDomain->setText(QApplication::translate("FrequencyDomain", "\346\227\266\345\237\237", nullptr));
        tbnChangeWaveStyle->setText(QApplication::translate("FrequencyDomain", "\345\210\207\346\215\242", nullptr));
        leFundamentalWave->setText(QString());
        label_16->setText(QApplication::translate("FrequencyDomain", "2M\345\237\272\346\263\242A1=", nullptr));
        label_17->setText(QApplication::translate("FrequencyDomain", "4M\344\272\214\346\254\241\350\260\220\346\263\242A2=", nullptr));
        leSecondWave->setText(QString());
        label_18->setText(QApplication::translate("FrequencyDomain", "\351\235\236\347\272\277\346\200\247\345\217\202\351\207\217\316\262=", nullptr));
        leNolinearPara->setText(QString());
        tbnReadAndCalculate->setText(QApplication::translate("FrequencyDomain", "\350\256\241\347\256\227", nullptr));
        leMaterialNumber->setText(QString());
        label_19->setText(QApplication::translate("FrequencyDomain", "\346\235\220\346\226\231\347\274\226\345\217\267\357\274\232", nullptr));
        leMaterialType->setText(QString());
        label_20->setText(QApplication::translate("FrequencyDomain", "\346\235\220\346\226\231\347\261\273\345\236\213\357\274\232", nullptr));
        leHarmType->setText(QString());
        le_2->setText(QApplication::translate("FrequencyDomain", "\346\215\237\344\274\244\347\261\273\345\236\213\357\274\232", nullptr));
        leTestCondition->setText(QString());
        le->setText(QApplication::translate("FrequencyDomain", "\350\257\225\351\252\214\346\235\241\344\273\266\357\274\232", nullptr));
        tbnInquiry->setText(QApplication::translate("FrequencyDomain", "\346\237\245\350\257\242", nullptr));
        tbnConfirmHarm->setText(QApplication::translate("FrequencyDomain", "\345\256\232\346\240\207", nullptr));
        tbnSaveData->setText(QApplication::translate("FrequencyDomain", "\344\277\235\345\255\230", nullptr));
        tbnStartDraw->setText(QApplication::translate("FrequencyDomain", "\345\274\200\345\247\213", nullptr));
        tbnClearWaves->setText(QApplication::translate("FrequencyDomain", "\346\270\205\347\251\272", nullptr));
        tbnLoadTimeData->setText(QApplication::translate("FrequencyDomain", "\345\257\274\345\205\245", nullptr));
        tbnSaveFreData->setText(QApplication::translate("FrequencyDomain", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrequencyDomain: public Ui_FrequencyDomain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FREQUENCYDOMAIN_H
