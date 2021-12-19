#include "qdynamicbutton.h"

QDynamicButton::QDynamicButton()
{
    ResID++;
    boxID = ResID;
}

QDynamicButton::~QDynamicButton() {}

int QDynamicButton::getID()
{
    return boxID;
}

int QDynamicButton::ResID = 0;  // значение статической переменной
