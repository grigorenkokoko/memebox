#include "categorieswin.h"
#include "ui_categorieswin.h"
#include "qdynamiccheckbox.h"

#include <QCheckBox>

categoriesWin::categoriesWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesWin)
{
    ui->setupUi(this);

    QDynamicCheckBox *CheckBox = new QDynamicCheckBox();  // создаем новый GroupBox
    CheckBox->setObjectName("CheckBox_" + QString::number(CheckBox->getID()));
    //qDebug() << Box->getID();
    ui->verticalLayout_2->addWidget(CheckBox, 1);  // Помещвем новый Box в слой verticalLayout_2
}

categoriesWin::~categoriesWin()
{
    delete ui;
}
