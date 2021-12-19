#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>

#include "userprofilewin.h"
#include "ui_userprofilewin.h"

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
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File");
    ui->lineEdit_file->setText(m_fileName);
}


void userProfileWin::on_pushButton_4_clicked()
{
    // Создаём объект файла при запуске загрузки
    m_file = new QFile(ui->lineEdit_file->text());
    if (!m_file->open(QIODevice::ReadOnly)) return;
    QByteArray byteArr = m_file->readAll();
    m_file->close();

    QString str = QString(byteArr);

    QJsonObject obj;
    obj["name"] = ui->lineEdit_file->text();
    obj["byte"] = str;

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    std::string strr = strJson.toStdString();

    //TODO: преобразуем QByteArray в QString, чтобы положить в json, но не можем получить файл обратно из QString
    //QFile *newFile = new QFile("D:\\123.jpg");
    //if (!newFile->open(QIODevice::ReadWrite)) return;
    //newFile->write(str.toLocal8Bit());
    //newFile->close();


}

