#include <QPixmap>

#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);

    QPixmap pix1(":/resource/mem/mem0.jpg");  // создаем обьект с картинкой
    int w = 275;
    int h = 257;
    //int w = ui->label->width();  // высота картинки
    //int h = ui->label->height();
    ui->label->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_next_clicked()
{
    if (this->n < 2) {
        this->n ++;
    }
    QPixmap pix1(":/resource/mem/mem0.jpg");  // создаем обьект с картинкой
    QPixmap pix2(":/resource/mem/mem1.jpg");
    QPixmap pix3(":/resource/mem/mem2.jpg");
    int w = 275;
    int h = 257;
    switch (this->n){
    case 0:
        ui->label->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
        break;
    case 1:
        ui->label->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
        break;
    case 2:
        ui->label->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
        break;
    }
}


void SecondWindow::on_pushButton_back_clicked()
{
    if (this->n > 0) {
        this->n --;
    }
    QPixmap pix1(":/resource/mem/mem0.jpg");  // создаем обьект с картинкой
    QPixmap pix2(":/resource/mem/mem1.jpg");
    QPixmap pix3(":/resource/mem/mem2.jpgg");
    int w = 275;
    int h = 257;
    switch (this->n){
    case 0:
        ui->label->setPixmap(pix1.scaled(w, h, Qt::KeepAspectRatio));
        break;
    case 1:
        ui->label->setPixmap(pix2.scaled(w, h, Qt::KeepAspectRatio));
        break;
    case 2:
        ui->label->setPixmap(pix3.scaled(w, h, Qt::KeepAspectRatio));
        break;
    }
}

