#include <QPixmap>
#include <QScrollArea>  // полосы прокрутки
#include <QLabel>
#include <QFileDialog>
#include <QScrollBar>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    on_pushButton_addBox_clicked();
    on_pushButton_addBox_clicked();
    on_pushButton_addBox_clicked();

    QScrollBar *scrollBar = ui->scrollArea->verticalScrollBar();
    connect(scrollBar, SIGNAL(valueChanged(int)), this, SLOT(slotAreaMaxValue(int)));


}

SecondWindow::~SecondWindow()
{
    delete ui;
}


void SecondWindow::on_pushButton_exit_clicked()
{
    emit signalExit();
    this->close();
}


void SecondWindow::on_pushButton_addBox_clicked()
{
    /*
     * запрос серверу на получение мема
     */

    QDynamicBox *Box = new QDynamicBox(this);  // создаем новый GroupBox
    Box->setObjectName("groupBox_" + QString::number(Box->getID()));
    //qDebug() << Box->getID();
    ui->verticalLayout_2->addWidget(Box, 1);  // Помещвем новый Box в слой verticalLayout_2
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
    //buttonLike->setIcon(QIcon(":/resource/img/like.png"));  // добавление иконки на кнопку
    buttonLike->setIconSize(QSize(20, 20));  // размер кнопки
    connect(buttonLike, SIGNAL(clicked()), this, SLOT(slot_on_pushButton_like_clicked()));  // связываем сигнал нажатия кнопки и слот нажатия кнопки

    QDynamicButton *buttonDislike = new QDynamicButton();
    HLayout->addWidget(buttonDislike);
    buttonDislike->setObjectName("buttonDisLike_" + QString::number(Box->getID()));
    buttonDislike->BoxNumber = Box->getID();
    //buttonDislike->setIcon(QIcon(":/resource/img/dislike.png"));
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

    // выставление иконки like/dislike по like_status
    Box->like_status = NOTHING;
    switch (Box->like_status)
    {
    case LIKE:
        buttonLike->setIcon(QIcon(":/resource/img/like_click.png"));
        buttonDislike->setIcon(QIcon(":/resource/img/dislike.png"));
        break;
    case DISLIKE:
        buttonLike->setIcon(QIcon(":/resource/img/like.png"));
        buttonDislike->setIcon(QIcon(":/resource/img/dislike_click.png"));
        break;
    case NOTHING:
        buttonLike->setIcon(QIcon(":/resource/img/like.png"));
        buttonDislike->setIcon(QIcon(":/resource/img/dislike.png"));
        break;
    }

    QPixmap pix1(":/resource/mem/mem0.jpg");
    int w = 275;
    int h = 257;
    newLabel->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));  // вставляем картинку в layout

}

void SecondWindow::slot_on_pushButton_like_clicked()
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

void SecondWindow::slot_on_pushButton_dislike_clicked()
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

void SecondWindow::slot_on_pushButton_download_clicked()
{
    QDynamicButton *buttonDownload = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonDownload->BoxNumber));
    QString fileDirectory = QFileDialog::getExistingDirectory(this);

    qDebug() << fileDirectory;

    /*
     *  Скачивание картинки на устройство
     */
}

void SecondWindow::slot_on_pushButton_plus_clicked()
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

void SecondWindow::on_pushButton_clicked()
{
    //hide();
    //emit signalUserWin();

    hide();  // скрыть исходное окно
    userProf = new userProfileWin(this);
    userProf->show();
    connect(userProf, &userProfileWin::signalExitProf, this, &SecondWindow::slotExitProf);
}

void SecondWindow::slotExitProf()
{
    show();
}

void SecondWindow::slotAreaMaxValue(int value)
{
    QScrollBar *scrollBar = (QScrollBar*) sender();
    if(value == scrollBar->maximum())
    {
        on_pushButton_addBox_clicked();
    }
}
//
//void SecondWindow::slotUserWin()
//{
//
//}

