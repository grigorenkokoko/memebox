#include "qdynamicbox.h"

QDynamicBox::QDynamicBox(QWidget *parent) :
    QGroupBox(parent)
{
    ResID++;
    boxID = ResID;
}

QDynamicBox::~QDynamicBox() {}

int QDynamicBox::getID()
{
    return boxID;
}

int QDynamicBox::ResID = 0;  // значение статической переменной
