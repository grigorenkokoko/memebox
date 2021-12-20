#include "qdynamiccheckboxtopost.h"

QDynamicCheckBoxToPost::QDynamicCheckBoxToPost()
{
    ResID++;
    boxID = ResID;
}


int QDynamicCheckBoxToPost::getID()
{
    return boxID;
}

int QDynamicCheckBoxToPost::ResID = 0;  // значение статической переменной

