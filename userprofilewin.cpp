#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QScrollBar>

#include "userprofilewin.h"
#include "ui_userprofilewin.h"
#include "qdynamiccheckbox.h"
#include "qdynamiccheckboxtopost.h"
#include "qdynamicbox.h"


userProfileWin::userProfileWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userProfileWin)
{
    ui->setupUi(this);

    ui->lineEdit_login->setText("Dre");
    ui->lineEdit_name->setText("Андрей");
    ui->lineEdit_surname->setText("Мас");

    add_to_liked();
    add_to_liked();
    add_to_liked();
    QScrollBar *scrollBarToLiked = ui->scrollArea->verticalScrollBar();
    connect(scrollBarToLiked, SIGNAL(valueChanged(int)), this, SLOT(slotAreaMaxValueToLiked(int)));

    add_to_uploaded();
    add_to_uploaded();
    add_to_uploaded();
    QScrollBar *scrollBarToUploaded = ui->scrollArea_2->verticalScrollBar();
    connect(scrollBarToUploaded, SIGNAL(valueChanged(int)), this, SLOT(slotAreaMaxValueToUploaded(int)));
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

void userProfileWin::add_to_liked()
{
    /*
     *  Нужен стоп от сервера
     */

    QDynamicBox *Box = new QDynamicBox(this);  // создаем новый GroupBox
    Box->setObjectName("groupBox_" + QString::number(Box->getID()));
    //qDebug() << Box->getID();
    ui->verticalLayout_toLiked->addWidget(Box, 1);  // Помещвем новый Box в слой verticalLayout_2
    QVBoxLayout *VLayout = new QVBoxLayout(Box);  // Создаем новый слой verticalLayout
    Box->setLayout(VLayout);  // применяет макет layout к виджету Box
    QLabel *newLabel = new QLabel(this);  // создаем новый Label для картинки
    VLayout->addWidget(newLabel);  // добавляем newLabel в layout
    QHBoxLayout *HLayout = new QHBoxLayout(Box);
    VLayout->addLayout(HLayout);
    QLabel *categLabel = new QLabel(this);
    VLayout->addWidget(categLabel);
    categLabel->setObjectName("categLabel_" + QString::number(Box->getID()));
    //categLabel->setGeometry(0, 0, 100, 100);
    categLabel->hide();

    Box->like_status = LIKE;

    QLabel *labelLike = new QLabel();
    HLayout->addWidget(labelLike);
    labelLike->setObjectName("labelLike_" + QString::number(Box->getID()));
    labelLike->setText(QString::number(Box->numberLike));

    QDynamicButton *buttonLike = new QDynamicButton();
    HLayout->addWidget(buttonLike);
    buttonLike->setObjectName("buttonLike_" + QString::number(Box->getID()));
    buttonLike->BoxNumber = Box->getID();
    buttonLike->setIcon(QIcon(":/resource/img/like_click.png"));  // добавление иконки на кнопку
    buttonLike->setIconSize(QSize(20, 20));  // размер кнопки
    connect(buttonLike, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_like_clicked()));  // связываем сигнал нажатия кнопки и слот нажатия кнопки

    QDynamicButton *buttonDislike = new QDynamicButton();
    HLayout->addWidget(buttonDislike);
    buttonDislike->setObjectName("buttonDisLike_" + QString::number(Box->getID()));
    buttonDislike->BoxNumber = Box->getID();
    buttonDislike->setIcon(QIcon(":/resource/img/dislike.png"));
    buttonDislike->setIconSize(QSize(20, 20));
    connect(buttonDislike, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_dislike_clicked()));

    QLabel *labelDisLike = new QLabel();
    HLayout->addWidget(labelDisLike);
    labelDisLike->setObjectName("labelDisLike_" + QString::number(Box->getID()));
    labelDisLike->setText(QString::number(Box->numberDisLike));

    HLayout->addStretch(0); // Добавляет растягиваемое пространство (QSpacerItem) с нулевым минимальным размером

    QDynamicButton *buttonPlus = new QDynamicButton();
    HLayout->addWidget(buttonPlus);
    buttonPlus->setObjectName("buttonPlus_" + QString::number(Box->getID()));
    buttonPlus->BoxNumber = Box->getID();
    buttonPlus->setIcon(QIcon(":/resource/img/plus.png"));
    buttonPlus->setIconSize(QSize(20, 20));
    connect(buttonPlus, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_plus_clicked()));

    QDynamicButton *buttonDownload = new QDynamicButton();
    HLayout->addWidget(buttonDownload);
    buttonDownload->setObjectName("buttonDownload_" + QString::number(Box->getID()));
    buttonDownload->BoxNumber = Box->getID();
    buttonDownload->setIcon(QIcon(":/resource/img/download.png"));
    buttonDownload->setIconSize(QSize(20, 20));
    connect(buttonDownload, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_download_clicked()));

    QPixmap pix1(":/resource/mem/mem0.jpg");
    int w = 275;
    int h = 257;
    newLabel->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));  // вставляем картинку в layout

}


void userProfileWin::add_to_uploaded()
{
    /*
     *  Нужен стоп от сервера
     */

    QDynamicBox *Box = new QDynamicBox(this);  // создаем новый GroupBox
    Box->setObjectName("groupBox_" + QString::number(Box->getID()));
    //qDebug() << Box->getID();
    ui->verticalLayout_toUploaded->addWidget(Box, 1);  // Помещвем новый Box в слой verticalLayout_2
    QVBoxLayout *VLayout = new QVBoxLayout(Box);  // Создаем новый слой verticalLayout
    Box->setLayout(VLayout);  // применяет макет layout к виджету Box
    QLabel *newLabel = new QLabel(this);  // создаем новый Label для картинки
    VLayout->addWidget(newLabel);  // добавляем newLabel в layout
    QHBoxLayout *HLayout = new QHBoxLayout(Box);
    VLayout->addLayout(HLayout);
    QLabel *categLabel = new QLabel(this);
    VLayout->addWidget(categLabel);
    categLabel->setObjectName("categLabel_" + QString::number(Box->getID()));
    //categLabel->setGeometry(0, 0, 100, 100);
    categLabel->hide();

    QLabel *labelLike = new QLabel();
    HLayout->addWidget(labelLike);
    labelLike->setObjectName("labelLike_" + QString::number(Box->getID()));
    labelLike->setText(QString::number(Box->numberLike));

    QDynamicButton *buttonLike = new QDynamicButton();
    HLayout->addWidget(buttonLike);
    buttonLike->setObjectName("buttonLike_" + QString::number(Box->getID()));
    buttonLike->BoxNumber = Box->getID();
    buttonLike->setIcon(QIcon(":/resource/img/like.png"));  // добавление иконки на кнопку
    buttonLike->setIconSize(QSize(20, 20));  // размер кнопки
    connect(buttonLike, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_like_clicked()));  // связываем сигнал нажатия кнопки и слот нажатия кнопки

    QDynamicButton *buttonDislike = new QDynamicButton();
    HLayout->addWidget(buttonDislike);
    buttonDislike->setObjectName("buttonDisLike_" + QString::number(Box->getID()));
    buttonDislike->BoxNumber = Box->getID();
    buttonDislike->setIcon(QIcon(":/resource/img/dislike.png"));
    buttonDislike->setIconSize(QSize(20, 20));
    connect(buttonDislike, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_dislike_clicked()));

    QLabel *labelDisLike = new QLabel();
    HLayout->addWidget(labelDisLike);
    labelDisLike->setObjectName("labelDisLike_" + QString::number(Box->getID()));
    labelDisLike->setText(QString::number(Box->numberDisLike));

    HLayout->addStretch(0); // Добавляет растягиваемое пространство (QSpacerItem) с нулевым минимальным размером

    QDynamicButton *buttonPlus = new QDynamicButton();
    HLayout->addWidget(buttonPlus);
    buttonPlus->setObjectName("buttonPlus_" + QString::number(Box->getID()));
    buttonPlus->BoxNumber = Box->getID();
    buttonPlus->setIcon(QIcon(":/resource/img/plus.png"));
    buttonPlus->setIconSize(QSize(20, 20));
    connect(buttonPlus, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_plus_clicked()));

    QDynamicButton *buttonDownload = new QDynamicButton();
    HLayout->addWidget(buttonDownload);
    buttonDownload->setObjectName("buttonDownload_" + QString::number(Box->getID()));
    buttonDownload->BoxNumber = Box->getID();
    buttonDownload->setIcon(QIcon(":/resource/img/download.png"));
    buttonDownload->setIconSize(QSize(20, 20));
    connect(buttonDownload, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_download_clicked()));

    QPixmap pix1(":/resource/mem/mem0.jpg");
    int w = 275;
    int h = 257;
    newLabel->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));  // вставляем картинку в layout

}


void userProfileWin::slot_on_pushButton_like_clicked()
{
    QDynamicButton *buttonLike = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonLike->BoxNumber));
    QDynamicButton *buttonDisLike = this->findChild<QDynamicButton *>("buttonDisLike_" + QString::number(buttonLike->BoxNumber));
    QLabel *labelLike = this->findChild<QLabel *>("labelLike_" + QString::number(buttonLike->BoxNumber));
    QLabel *labelDisLike = this->findChild<QLabel *>("labelDisLike_" + QString::number(buttonLike->BoxNumber));


    switch (Box->like_status)
    {
    case LIKE:
        Box->like_status = NOTHING;
        buttonLike->setIcon(QIcon(":/resource/img/like.png"));
        Box->numberLike--;
        labelLike->setText(QString::number(Box->numberLike));
        break;
    case DISLIKE:
        Box->like_status = LIKE;
        buttonLike->setIcon(QIcon(":/resource/img/like_click.png"));
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike.png"));
        Box->numberDisLike--;
        Box->numberLike++;
        labelLike->setText(QString::number(Box->numberLike));
        labelDisLike->setText(QString::number(Box->numberDisLike));
        break;
    case NOTHING:
        Box->like_status = LIKE;
        buttonLike->setIcon(QIcon(":/resource/img/like_click.png"));
        Box->numberLike++;
        labelLike->setText(QString::number(Box->numberLike));
        break;
    }
}

void userProfileWin::slot_on_pushButton_dislike_clicked()
{
    QDynamicButton *buttonDisLike = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonDisLike->BoxNumber));
    QDynamicButton *buttonLike = this->findChild<QDynamicButton *>("buttonLike_" + QString::number(buttonDisLike->BoxNumber));
    QLabel *labelLike = this->findChild<QLabel *>("labelLike_" + QString::number(buttonLike->BoxNumber));
    QLabel *labelDisLike = this->findChild<QLabel *>("labelDisLike_" + QString::number(buttonLike->BoxNumber));

    switch (Box->like_status)
    {
    case DISLIKE:
        Box->like_status = NOTHING;
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike.png"));
        Box->numberDisLike--;
        labelDisLike->setText(QString::number(Box->numberDisLike));
        break;
    case LIKE:
        Box->like_status = DISLIKE;
        buttonLike->setIcon(QIcon(":/resource/img/like.png"));
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike_click.png"));
        Box->numberLike--;
        Box->numberDisLike++;
        labelLike->setText(QString::number(Box->numberLike));
        labelDisLike->setText(QString::number(Box->numberDisLike));
        break;
    case NOTHING:
        Box->like_status = DISLIKE;
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike_click.png"));
        Box->numberDisLike++;
        labelDisLike->setText(QString::number(Box->numberDisLike));
        break;
    }
}

void userProfileWin::slot_on_pushButton_download_clicked()
{
    QDynamicButton *buttonDownload = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonDownload->BoxNumber));
    QString fileDirectory = QFileDialog::getExistingDirectory(this);

    qDebug() << fileDirectory;

    /*
     *  Скачивание картинки на устройство
     */
}

void userProfileWin::slot_on_pushButton_plus_clicked()
{
    QDynamicButton *buttonPlus = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonPlus->BoxNumber));
    QLabel *categLabel = this->findChild<QLabel *>("categLabel_" + QString::number(Box->getID()));

    // Пример Json
    QString Json = "{\"categories\":[\"categories_1\",\"categories_2\",\"categories_3\",\"categories_4\",\"categories_5\"],\"name\":\"\"}";

    QJsonDocument jsonDoc = QJsonDocument::fromJson(Json.toUtf8());
    QJsonObject jsonObject = jsonDoc.object();
    QJsonArray jsonArray = jsonObject["categories"].toArray();



    int i = 1;
    switch (buttonPlus->clickStatus)
    {
    case NO_CLICKED:
        buttonPlus->clickStatus = CLICKED;
        categLabel->show();

        categLabel->setText(jsonArray.at(0).toString());
        while (jsonArray.at(i) != QJsonValue::Undefined)
        {
            categLabel->setText(categLabel->text() + ", \n" + jsonArray.at(i).toString());
            i++;
        }

        break;
    case CLICKED:
        buttonPlus->clickStatus = NO_CLICKED;
        categLabel->hide();
        break;
    }
}


void userProfileWin::slotAreaMaxValueToLiked(int value)
{
    QScrollBar *scrollBar = (QScrollBar*) sender();
    if(value == scrollBar->maximum())
    {
        add_to_liked();
    }
}

void userProfileWin::slotAreaMaxValueToUploaded(int value)
{
    QScrollBar *scrollBar = (QScrollBar*) sender();
    if(value == scrollBar->maximum())
    {
        add_to_uploaded();
    }
}
