#ifndef DATABASE_H
#define DATABASE_H

#include <QWidget>

namespace Ui {
class Database;
}

class Database : public QWidget
{
    Q_OBJECT

public:
    explicit Database(QWidget *parent = 0);
    ~Database();
    void InitConnect();
    void InitUI();
signals:
    void Display(int);
private slots:
    void DisplayFrequencyDomainLast();
private:
    Ui::Database *ui;
};

#endif // DATABASE_H
