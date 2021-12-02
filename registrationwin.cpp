#include "registrationwin.h"
#include "ui_registrationwin.h"

#include "secondwindow.h"
#include "mainwindow.h"

registrationWin::registrationWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationWin)
{
    ui->setupUi(this);


}

registrationWin::~registrationWin()
{
    delete ui;
}

void registrationWin::on_pushButton_clicked()
{
    emit signalReg();  // сигнал окну Main
    this->close();
}
