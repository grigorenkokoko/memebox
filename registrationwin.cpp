#include <QJsonObject>
#include <QJsonDocument>

#include "registrationwin.h"
#include "ui_registrationwin.h"

#include "secondwindow.h"
#include "mainwindow.h"

registrationWin::registrationWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationWin)
{
    ui->setupUi(this);

    //QStatusBar *bar = new QStatusBar(this);
    //ui->verticalLayout->addWidget(bar);
}

registrationWin::~registrationWin()
{
    delete ui;
}

void registrationWin::on_pushButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString login = ui->lineEdit_login->text();
    QString pass = ui->lineEdit_pass->text();
    QString pass2 = ui->lineEdit_pass2->text();

    if (!(ui->lineEdit_name->displayText().isEmpty()) &&
        !(ui->lineEdit_surname->displayText().isEmpty()) &&
        !(ui->lineEdit_login->displayText().isEmpty()) &&
        !(ui->lineEdit_pass->displayText().isEmpty()) &&
        !(ui->lineEdit_pass2->displayText().isEmpty()))
    {
        if (pass == pass2) {
            QJsonObject obj;
            obj["name"] = name;
            obj["surname"] = surname;
            obj["login"] = login;
            obj["password"] = pass;

            QJsonDocument doc(obj);
            QString strJson(doc.toJson(QJsonDocument::Compact));
            std::string str = strJson.toStdString();
            qDebug() << str.data();

            emit signalSecWin();  // сигнал окну Main
            hide();
            //this->close();
        } else {
            // qDebug() << "Введены разные пароли";
            ui->label_message->setText("Введены разные пароли");
        }
    } else {
        // qDebug() << "Не все поля заполнены";
        ui->label_message->setText("Не все поля заполнены");
    }
}
