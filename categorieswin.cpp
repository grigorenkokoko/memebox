#include "categorieswin.h"
#include "ui_categorieswin.h"
#include "qdynamiccheckbox.h"

#include <QCheckBox>

categoriesWin::categoriesWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesWin)
{
    ui->setupUi(this);

    on_pushButton_2_clicked();
}

categoriesWin::~categoriesWin()
{
    delete ui;
}

void categoriesWin::on_pushButton_2_clicked()
{
    for (int i = 0; i < 15; i++)
    {
        QDynamicCheckBox *CheckBox = new QDynamicCheckBox();  // создаем новый GroupBox
        CheckBox->setObjectName("CheckBox_" + QString::number(CheckBox->getID()));
        CheckBox->setText("categorie_" + QString::number(CheckBox->getID()));
        CheckBox->categID = "categorie_" + QString::number(CheckBox->getID());
//        CheckBox->setChecked(true);
        ui->verticalLayout_2->addWidget(CheckBox, 1);  // Помещвем новый Box в слой verticalLayout_2
    }
}


void categoriesWin::on_pushButton_exitCateg_clicked()
{
    emit signalSecWin();  // сигнал окну Main
    hide();
    QDynamicCheckBox::ResID = 0;
}

