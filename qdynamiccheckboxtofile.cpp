#include "qdynamiccheckboxtofile.h"

QDynamicCheckBoxToFile::QDynamicCheckBoxToFile()
{
    ResID++;
    boxID = ResID;
}


int QDynamicCheckBoxToFile::getID()
{
    return boxID;
}

int QDynamicCheckBoxToFile::ResID = 0;  // значение статической переменной
