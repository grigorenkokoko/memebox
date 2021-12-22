#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <iostream>
#include <fstream>

#include "userprofilewin.h"
#include "ui_userprofilewin.h"
#include "base64.h"
#include "nlohmann/json.hpp"
#include "client_memebox.h"

userProfileWin::userProfileWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userProfileWin)
{
    ui->setupUi(this);
}

userProfileWin::~userProfileWin()
{
    delete ui;
}

void userProfileWin::on_pushButton_5_clicked()
{
    emit signalExitProf();
    this->close();
}


void userProfileWin::on_pushButton_3_clicked()
{
    QString filter = "(*.jpg)";
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File", QDir::homePath(), filter);
    ui->lineEdit_file->setText(m_fileName);
}


void userProfileWin::on_pushButton_4_clicked()
{
    // Создаём объект файла при запуске загрузки
    /*m_file = new QFile(ui->lineEdit_file->text());
    if (!m_file->open(QIODevice::ReadOnly)) return;
    QByteArray byteArr = m_file->readAll();
    m_file->close();

    QString str = QString(byteArr);

    QJsonObject obj;
    obj["name"] = ui->lineEdit_file->text();
    std::string str_string = str.toStdString();
    obj["byte"] = base64_encode(str_string, str_string.size());

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    std::string strr = strJson.toStdString();
    }*/
    auto filename = ui->lineEdit_file->text().toStdString();
    std::ifstream input(filename, std::ios::binary);

    std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(input), {});

    auto meme_byte = base64_encode(buffer, buffer.size());

    nlohmann::json body_request = {{"name", ui->lineEdit_file->text().toStdString()}, {"byte", meme_byte}};

    Request request;
    request_info request_struct = { };
    request_struct.type_request = POST;
    request_struct.target_request = SET_MEME;

    std::string str_body = body_request.dump();
    request.do_request(request_struct, str_body);
    http::request<http::string_body> to_client = request.get_request();

    std::cerr << "Запрос: \n" << to_client;

    net::io_context ioc;
    std::shared_ptr<Client> client(new Client(ioc, to_client));

    client->run();

    ioc.run();

    std::cerr << client->get_response() << std::endl;

    //TODO: преобразуем QByteArray в QString, чтобы положить в json, но не можем получить файл обратно из QString
    //QFile *newFile = new QFile("D:\\123.jpg");
    //if (!newFile->open(QIODevice::ReadWrite)) return;
    //newFile->write(str.toLocal8Bit());
    //newFile->close();


}

