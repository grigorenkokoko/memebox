#pragma once

#include <QPushButton>

class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    QDynamicButton();
    ~QDynamicButton();
    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();

    int BoxNumber;

private:
    int boxID = 0;
};
