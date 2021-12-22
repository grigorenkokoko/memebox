#pragma once

#include <QDialog>
#include <QStatusBar>

#include "secondwindow.h"

namespace Ui {
class registrationWin;
}

class registrationWin : public QDialog
{
    Q_OBJECT

public:
    explicit registrationWin(QWidget *parent = nullptr);
    ~registrationWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registrationWin *ui;
    SecondWindow *window;

signals:
    void signalReg();
};
