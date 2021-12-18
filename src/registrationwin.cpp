#include <QJsonObject>
#include <QJsonDocument>
#include <QDialog>
#include <QStatusBar>
#include <iostream>

#include "registrationwin.h"
#include "ui_registrationwin.h"

#include "secondwindow.h"
#include "mainwindow.h"

#include "client_memebox.h"

registrationWin::registrationWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registrationWin)
{
    ui->setupUi(this);

    QStatusBar *bar = new QStatusBar(this);
    ui->verticalLayout->addWidget(bar);
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

            Request request;
            request_info request_struct = { };
            request_struct.type_request = POST;
            request_struct.target_request = REGISTRATION;
            std::string json_string = strJson.toStdString();

            std::cerr << json_string << std::endl;
            request.do_request(request_struct, json_string);
            http::request<http::string_body> to_client = request.get_request();

            std::cerr << "Запрос: \n" << to_client;

            net::io_context ioc;
            std::shared_ptr<Client> client(new Client(ioc, to_client));

            client->run();

            ioc.run();

            if (client->check_status() == SUCCESS) {
                emit signalReg();  // сигнал окну Main
                hide();
            } else {
                ui->label_message->setText("Пользователь с таким логином уже существует");
            }
        } else {
            ui->label_message->setText("Введены разные пароли");
        }
    } else {
        ui->label_message->setText("Не все поля заполнены");
    }
}
