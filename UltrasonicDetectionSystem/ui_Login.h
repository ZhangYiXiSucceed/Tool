/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *label;
    QGroupBox *groupBox;
    QToolButton *tbnGuidedWaves;
    QToolButton *tbnLongitudinalWave;
    QLabel *label_2;
    QLabel *LabelPicture;
    QLabel *LabelColor;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(764, 471);
        label = new QLabel(Login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 50, 521, 71));
        groupBox = new QGroupBox(Login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(159, 150, 591, 201));
        groupBox->setStyleSheet(QLatin1String("border-color: rgb(85, 170, 255);\n"
"gridline-color: rgb(85, 170, 255);\n"
""));
        tbnGuidedWaves = new QToolButton(groupBox);
        tbnGuidedWaves->setObjectName(QStringLiteral("tbnGuidedWaves"));
        tbnGuidedWaves->setGeometry(QRect(80, 70, 161, 71));
        tbnGuidedWaves->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        tbnLongitudinalWave = new QToolButton(groupBox);
        tbnLongitudinalWave->setObjectName(QStringLiteral("tbnLongitudinalWave"));
        tbnLongitudinalWave->setGeometry(QRect(350, 70, 161, 71));
        tbnLongitudinalWave->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(310, 380, 291, 81));
        LabelPicture = new QLabel(Login);
        LabelPicture->setObjectName(QStringLiteral("LabelPicture"));
        LabelPicture->setGeometry(QRect(0, 0, 161, 151));
        LabelColor = new QLabel(Login);
        LabelColor->setObjectName(QStringLiteral("LabelColor"));
        LabelColor->setGeometry(QRect(0, 150, 161, 381));
        LabelColor->setStyleSheet(QLatin1String("color: rgb(85, 170, 255);\n"
"background-color: rgb(85, 170, 255);"));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", nullptr));
        label->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; color:#0000ff;\">\351\235\236\347\272\277\346\200\247\350\266\205\345\243\260\346\263\242\346\227\240\346\215\237\346\243\200\346\265\213\347\263\273\347\273\237</span></p></body></html>", nullptr));
        groupBox->setTitle(QString());
        tbnGuidedWaves->setText(QApplication::translate("Login", "\345\257\274\346\263\242\346\265\213\351\207\217", nullptr));
        tbnLongitudinalWave->setText(QApplication::translate("Login", "\347\272\265\346\263\242\346\265\213\351\207\217", nullptr));
        label_2->setText(QApplication::translate("Login", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:600; color:#55aaff;\">\344\277\241\346\201\257\347\247\221\345\255\246\344\270\216\345\267\245\347\250\213\345\255\246\351\231\242</span></p></body></html>", nullptr));
        LabelPicture->setText(QString());
        LabelColor->setText(QApplication::translate("Login", "2400", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
