#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "userprofilewin.h"
#include "ui_userprofilewin.h"
#include "qdynamiccheckbox.h"
#include "qdynamiccheckboxtopost.h"

userProfileWin::userProfileWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userProfileWin)
{
    ui->setupUi(this);

    on_pushButton__addCaegtoFile_clicked();
    on_pushButton_addCaegtoPost_clicked();

    ui->lineEdit_login->setText("Dre");
    ui->lineEdit_name->setText("Андрей");
    ui->lineEdit_surname->setText("Мас");
}

userProfileWin::~userProfileWin()
{
    delete ui;
}

void userProfileWin::on_pushButton_5_clicked()
{
    emit signalExitProf();
    this->close();
    QDynamicCheckBoxToFile::ResID = 0;
    QDynamicCheckBoxToPost::ResID = 0;
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

    // Формируем json
    QJsonObject obj;
    obj["name"] = ui->lineEdit_file->text();
    obj["byte"] = str;

    // Собераем выделеные категории
    QJsonArray JsonArray;
    for(int i = 0; i < ui->verticalLayout_7->count(); i++)
    {
        QDynamicCheckBoxToFile *CheckBox = this->findChild<QDynamicCheckBoxToFile *>("CheckBoxtoFile_" + QString::number(i + 1));
        if (CheckBox->isChecked()) {
            JsonArray.append(CheckBox->categID); // добавление категории в lson
            qDebug() << "CheckBox_" + QString::number(i + 1);
        }
    }
    obj["categories"] = JsonArray;

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    std::string stdStrJson = strJson.toStdString();  // json в виде строки

//    qDebug() << strJson;

    //TODO: преобразуем QByteArray в QString, чтобы положить в json, но не можем получить файл обратно из QString
    //QFile *newFile = new QFile("D:\\123.jpg");
    //if (!newFile->open(QIODevice::ReadWrite)) return;
    //newFile->write(str.toLocal8Bit());
    //newFile->close();


}

void userProfileWin::on_pushButton__addCaegtoFile_clicked()
{
    /*
     *  Запрос на получение категорий
     */

    for (int i = 0; i < 15; i++)
    {
        QDynamicCheckBoxToFile *CheckBox = new QDynamicCheckBoxToFile();
        CheckBox->setObjectName("CheckBoxtoFile_" + QString::number(CheckBox->getID()));
        //qDebug() << CheckBox->getID();
        CheckBox->setText("categorie_" + QString::number(CheckBox->getID()));  // имя категории
        CheckBox->categID = "categorie_" + QString::number(CheckBox->getID());
        //CheckBox->setChecked(true);
        ui->verticalLayout_7->addWidget(CheckBox, 1);  // Помещвем новый Widget в слой verticalLayout_7
    }

}


void userProfileWin::on_pushButton_addCaegtoPost_clicked()
{
    /*
     *  Запрос на получение категорий
     */

    for (int i = 0; i < 15; i++)
    {
        QDynamicCheckBoxToPost *CheckBox = new QDynamicCheckBoxToPost();
        CheckBox->setObjectName("CheckBoxtoPost_" + QString::number(CheckBox->getID()));
        //qDebug() << CheckBox->getID();
        CheckBox->setText("categorie_" + QString::number(CheckBox->getID()));  // имя категории
        CheckBox->categID = "categorie_" + QString::number(CheckBox->getID());
        //CheckBox->setChecked(true);
        ui->verticalLayout_9->addWidget(CheckBox, 1);  // Помещвем новый Widget в слой verticalLayout_7
    }
}

