#include "UltrasonicDetectionSystem.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login dlglogin;
    dlglogin.setWindowFlags(Qt::WindowMaximizeButtonHint | Qt::MSWindowsFixedSizeDialogHint);
    int result = dlglogin.exec();
    if(result==QDialog::Accepted)
    {
        UltrasonicDetectionSystem w;
        w.setWindowFlags((w.windowFlags()|Qt::WindowMinimizeButtonHint) & ~Qt::WindowMaximizeButtonHint);
        w.show();
        return a.exec();
    }

}
