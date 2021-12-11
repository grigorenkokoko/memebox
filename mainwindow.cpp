#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client_memebox.h"

#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QJsonObject>
#include <QJsonDocument>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QPixmap pix(":/resource/img/memebox.png");  // создаем обьект с картинкой
    // int w = ui->image->width();  // высота картинки
    // int h = ui->image->height();  // ширина картинки
    int w = 275;
    int h = 257;

    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));  // поместили в image наше изображение, указали размеы и чтоб растягиавлось под окно

//    connect(regWin, &registrationWin::signalReg, this, &MainWindow::slotReg);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_exit_clicked()
{
//    QMessageBox::about(this, "Сообщения", "Нет сообщений");  // новое окно
//    QMessageBox::aboutQt(this, "Сообщения");  // инфа о Qt
//    QMessageBox::critical(this, "Сообщения", "Нет сообщений");  // соощение об ошибке
//    QMessageBox::information(this, "Сообщения", "Нет сообщений");  // информационное
//    QMessageBox::warning(this, "Сообщения", "Нет сообщений");  // предупреждение
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Хотите выйти?",
                                                              QMessageBox::Yes | QMessageBox::No);  // вопрос пользователю
    if (reply == QMessageBox::Yes) {
        QApplication::quit();  // выйти из проги
    } else {
        qDebug() << "Нажата кнопка Нет";  // вывод в консоль
    }
}


void MainWindow::on_pushButton_registration_clicked()
{
    hide();  // скрыть исходное окно
    regWin = new registrationWin(this);
    regWin->show();

    connect(regWin, &registrationWin::signalReg, this, &MainWindow::slotReg);  //  связь между сигналом окна regWin и слотом окна Main, для того чтобы можно было вернуться в окно Main
}


void MainWindow::on_pushButton_authorization_clicked()
{
    QString login = ui->login->text();
    QString password = ui->pass->text();

    QJsonObject obj;
    obj["login"] = login;
    obj["password"] = password;

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));


    Request request;
    request_info request_struct = { };
    request_struct.type_request = POST;
    request_struct.target_request = SIGN_IN;
    std::string json_string = strJson.toStdString();

    std::cerr << json_string << std::endl;
    request.do_request(request_struct, json_string);
    http::request<http::string_body> to_client = request.get_request();

    std::cerr << "Запрос: \n" << to_client;

    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();

    if (login == "Dre" && password == "123") {  // Проверка логина и пароля
//        QMessageBox::information(this, "Авторизация", "Успешно\nПривет!");  // информационное окно
        ui->statusbar->showMessage("Успешно. ");
        hide();  // скрыть исходное окно
        window = new SecondWindow(this);
        window->show();
        if (ui->checkBox->isChecked()) {  // галочка для запоминания логина и пароля
            ui->statusbar->showMessage("Пока нет возможности запомнить. ");
        }
    } else {
//        QMessageBox::warning(this, "Авторизация", "Неверный логин или пароль");  // окно предупреждения
        ui->statusbar->showMessage("Неверный логин или пароль");
    }
}


void MainWindow::on_action_add_triggered()
{
    ui->statusbar->showMessage("Не создано");
}


void MainWindow::on_action_open_triggered()
{
    ui->statusbar->showMessage("Не открыт");
}


void MainWindow::on_action_exit_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Выход", "Хотите выйти?",
                                                              QMessageBox::Yes | QMessageBox::No);  // вопрос пользователю
    if (reply == QMessageBox::Yes) {
        QApplication::quit();  // выйти из проги
    } else {
        qDebug() << "Нажата кнопка Нет";  // вывод в консоль
    }
}

void MainWindow::slotReg()  // выполняется при сигнале от окна regWin
{
    show();
}
