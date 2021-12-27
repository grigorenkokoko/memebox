#include "qdynamicboxtouploaded.h"

QDynamicBoxToUploaded::QDynamicBoxToUploaded(QWidget *parent) :
    QGroupBox(parent)
{
    ResID++;
    boxID = ResID;
}

QDynamicBoxToUploaded::~QDynamicBoxToUploaded() {}

int QDynamicBoxToUploaded::getID()
{
    return boxID;
}

int QDynamicBoxToUploaded::ResID = 0;  // значение статической переменной
