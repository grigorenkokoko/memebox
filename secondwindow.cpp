#include <QPixmap>
#include <QScrollArea>  // полосы прокрутки
#include <QLabel>

#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    on_pushButton_addBox_clicked();
    on_pushButton_addBox_clicked();
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

//void SecondWindow::on_pushButton_next_clicked()
//{
//    if (this->n < 2) {
//        this->n ++;
//    }
//    QPixmap pix1(":/resource/mem/mem0.jpg");  // создаем обьект с картинкой
//    QPixmap pix2(":/resource/mem/mem1.jpg");
//    QPixmap pix3(":/resource/mem/mem2.jpg");
//    int w = 275;
//    int h = 257;
//    switch (this->n){
//    case 0:
//        ui->label->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
//        break;
//    case 1:
//        ui->label->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
//        break;
//    case 2:
//        ui->label->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
//        break;
//    }
//}


//void SecondWindow::on_pushButton_back_clicked()
//{
//    if (this->n > 0) {
//        this->n --;
//    }
//    QPixmap pix1(":/resource/mem/mem0.jpg");  // создаем обьект с картинкой
//    QPixmap pix2(":/resource/mem/mem1.jpg");
//    QPixmap pix3(":/resource/mem/mem2.jpgg");
//    int w = 275;
//    int h = 257;
//    switch (this->n){
//    case 0:
//        ui->label->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
//        break;
//    case 1:
//        ui->label->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
//        break;
//    case 2:
//        ui->label->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
//        break;
//    }
//}


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

    HLayout->addStretch(0); // Добавляет растягиваемое пространство (QSpacerItem) с нулевым минимальным размером

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

    switch (Box->like_status)
    {
    case LIKE:
        Box->like_status = NOTHING;
        buttonLike->setIcon(QIcon(":/resource/img/like.png"));
        break;
    case DISLIKE:
        Box->like_status = LIKE;
        buttonLike->setIcon(QIcon(":/resource/img/like_click.png"));
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike.png"));
        break;
    case NOTHING:
        Box->like_status = LIKE;
        buttonLike->setIcon(QIcon(":/resource/img/like_click.png"));
        break;
    }
}

void SecondWindow::slot_on_pushButton_dislike_clicked()
{
    QDynamicButton *buttonDisLike = (QDynamicButton*) sender();
    QDynamicBox *Box = this->findChild<QDynamicBox *>("groupBox_" + QString::number(buttonDisLike->BoxNumber));
    QDynamicButton *buttonLike = this->findChild<QDynamicButton *>("buttonLike_" + QString::number(buttonDisLike->BoxNumber));

    switch (Box->like_status)
    {
    case DISLIKE:
        Box->like_status = NOTHING;
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike.png"));
        break;
    case LIKE:
        Box->like_status = DISLIKE;
        buttonLike->setIcon(QIcon(":/resource/img/like.png"));
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike_click.png"));
        break;
    case NOTHING:
        Box->like_status = DISLIKE;
        buttonDisLike->setIcon(QIcon(":/resource/img/dislike_click.png"));
        break;
    }
}

void SecondWindow::on_pushButton_clicked()
{
    hide();  // скрыть исходное окно
    userProf = new userProfileWin(this);
    userProf->show();
    connect(userProf, &userProfileWin::signalExitProf, this, &SecondWindow::slotExitProf);
}

void SecondWindow::slotExitProf()
{
    show();
}

