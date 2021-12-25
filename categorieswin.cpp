#include "categorieswin.h"
#include "ui_categorieswin.h"
#include "qdynamiccheckbox.h"

#include <QCheckBox>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

categoriesWin::categoriesWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::categoriesWin)
{
    ui->setupUi(this);

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

categoriesWin::~categoriesWin()
{
    delete ui;
}


void categoriesWin::on_pushButton_exitCateg_clicked()
{
    emit signalSecWin();  // сигнал окну Main
    hide();
    QDynamicCheckBox::ResID = 0;


    // Формируем json
    QJsonObject obj;
    QJsonArray JsonArray;
    for(int i = 0; i < ui->verticalLayout_2->count(); i++)
    {
        QDynamicCheckBox *CheckBox = this->findChild<QDynamicCheckBox *>("CheckBox_" + QString::number(i + 1));
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

