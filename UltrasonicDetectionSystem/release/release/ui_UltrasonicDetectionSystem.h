/********************************************************************************
** Form generated from reading UI file 'UltrasonicDetectionSystem.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ULTRASONICDETECTIONSYSTEM_H
#define UI_ULTRASONICDETECTIONSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UltrasonicDetectionSystem
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *UltrasonicDetectionSystem)
    {
        if (UltrasonicDetectionSystem->objectName().isEmpty())
            UltrasonicDetectionSystem->setObjectName(QStringLiteral("UltrasonicDetectionSystem"));
        UltrasonicDetectionSystem->resize(1153, 765);
        centralWidget = new QWidget(UltrasonicDetectionSystem);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        UltrasonicDetectionSystem->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(UltrasonicDetectionSystem);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1153, 26));
        UltrasonicDetectionSystem->setMenuBar(menuBar);
        statusBar = new QStatusBar(UltrasonicDetectionSystem);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        UltrasonicDetectionSystem->setStatusBar(statusBar);

        retranslateUi(UltrasonicDetectionSystem);

        QMetaObject::connectSlotsByName(UltrasonicDetectionSystem);
    } // setupUi

    void retranslateUi(QMainWindow *UltrasonicDetectionSystem)
    {
        UltrasonicDetectionSystem->setWindowTitle(QApplication::translate("UltrasonicDetectionSystem", "UltrasonicDetectionSystem", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UltrasonicDetectionSystem: public Ui_UltrasonicDetectionSystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ULTRASONICDETECTIONSYSTEM_H
