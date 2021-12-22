#include "qdynamicbox.h"

QDynamicBox::QDynamicBox(std::string &mem_id, QWidget *parent, int likes, int dislikes) :
    QGroupBox(parent),
    memID(mem_id),
    numberLike(likes),
    numberDisLike(dislikes)
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
