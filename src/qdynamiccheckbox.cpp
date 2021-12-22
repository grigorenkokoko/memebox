#include "qdynamiccheckbox.h"

QDynamicCheckBox::QDynamicCheckBox()
{
    ResID++;
    boxID = ResID;
}


int QDynamicCheckBox::getID()
{
    return boxID;
}

int QDynamicCheckBox::ResID = 0;  // значение статической переменной
