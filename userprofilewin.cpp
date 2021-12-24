#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

#include "userprofilewin.h"
#include "ui_userprofilewin.h"
#include "qdynamiccheckbox.h"
#include "qdynamiccheckboxtopost.h"

userProfileWin::userProfileWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userProfileWin)
{
    ui->setupUi(this);

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


void userProfileWin::on_pushButton_downloadToFile_clicked()
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
            qDebug() << CheckBox->categID;
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


void userProfileWin::on_pushButton_newName_clicked()
{
    QString newName = ui->lineEdit_name->text();
    qDebug() << newName;
}


void userProfileWin::on_pushButton_newSurname_clicked()
{
    QString newSurname = ui->lineEdit_surname->text();
    qDebug() << newSurname;
}


void userProfileWin::on_pushButton_newPass_clicked()
{
    QString nowPass = ui->lineEdit_nowPass->text();
    qDebug() << nowPass;

    // проверка текущего пороля

    QString newPass = ui->lineEdit_newPass->text();
    QString newPassAgain = ui->lineEdit_newPassAgain->text();
    if (newPass == newPassAgain)
    {
        qDebug() << newPass;
    } else {
        QMessageBox::warning(this, "Сообщения", "Введены разные пароли");
    }
}


void userProfileWin::on_pushButton_addCateg_clicked()
{
    if (ui->lineEdit_categ->text() == "")
    {
        QMessageBox::warning(this, "Сообщения", "Категория не введена");
        return;
    }

    for (int i = 0; i < ui->verticalLayout_7->count(); i++)
    {
        QDynamicCheckBoxToFile *CheckBox = this->findChild<QDynamicCheckBoxToFile *>("CheckBoxtoFile_" + QString::number(i + 1));
        if (CheckBox->categID.toUpper() == ui->lineEdit_categ->text().toUpper())
        {
            QMessageBox::warning(this, "Сообщения", "Категория уже добавлена");
            return;
        }
    }

    QDynamicCheckBoxToFile *CheckBox = new QDynamicCheckBoxToFile();
    CheckBox->setObjectName("CheckBoxtoFile_" + QString::number(CheckBox->getID()));
    //qDebug() << CheckBox->getID();
    CheckBox->setText(ui->lineEdit_categ->text());  // имя категории
    CheckBox->categID = ui->lineEdit_categ->text().toLower();
    CheckBox->setChecked(true);
    ui->verticalLayout_7->addWidget(CheckBox, 1);  // Помещвем новый Widget в слой verticalLayout_7

    ui->lineEdit_categ->setText("");
}


void userProfileWin::on_pushButton_addCategToPost_clicked()
{
    if (ui->lineEdit_categToPost->text() == "")
    {
        QMessageBox::warning(this, "Сообщения", "Категория не введена");
        return;
    }

    for (int i = 0; i < ui->verticalLayout_9->count(); i++)
    {
        QDynamicCheckBoxToPost *CheckBox = this->findChild<QDynamicCheckBoxToPost *>("CheckBoxtoPost_" + QString::number(i + 1));
        if (CheckBox->categID.toUpper() == ui->lineEdit_categToPost->text().toUpper())
        {
            QMessageBox::warning(this, "Сообщения", "Категория уже добавлена");
            return;
        }
    }

    QDynamicCheckBoxToPost *CheckBox = new QDynamicCheckBoxToPost();
    CheckBox->setObjectName("CheckBoxtoPost_" + QString::number(CheckBox->getID()));
    //qDebug() << CheckBox->getID();
    CheckBox->setText(ui->lineEdit_categToPost->text());  // имя категории
    CheckBox->categID = ui->lineEdit_categToPost->text().toLower();
    CheckBox->setChecked(true);
    ui->verticalLayout_9->addWidget(CheckBox, 1);  // Помещвем новый Widget в слой verticalLayout_7

    ui->lineEdit_categToPost->setText("");
}


void userProfileWin::on_pushButton_downloadToPost_clicked()
{
    QString post = ui->lineEdit_post->text();
    qDebug() << post;

    // Формируем json
    QJsonObject obj;
    obj["name"] = ui->lineEdit_post->text();
    //obj["byte"] = str;

    // Собераем выделеные категории
    QJsonArray JsonArray;
    for(int i = 0; i < ui->verticalLayout_9->count(); i++)
    {
        QDynamicCheckBoxToPost *CheckBox = this->findChild<QDynamicCheckBoxToPost *>("CheckBoxtoPost_" + QString::number(i + 1));
        if (CheckBox->isChecked()) {
            JsonArray.append(CheckBox->categID); // добавление категории в lson
            //qDebug() << CheckBox->categID;
        }
    }
    obj["categories"] = JsonArray;

    QJsonDocument doc(obj);
    QString strJson(doc.toJson(QJsonDocument::Compact));
    std::string stdStrJson = strJson.toStdString();  // json в виде строки
    qDebug() << strJson;
}

