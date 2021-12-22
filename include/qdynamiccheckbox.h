#pragma once

#include <QCheckBox>

class QDynamicCheckBox : public QCheckBox
{
public:
    QDynamicCheckBox();

    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();

    QString categorieName;

private:
    int boxID = 0;
};
