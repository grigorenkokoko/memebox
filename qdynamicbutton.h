#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

#include <QPushButton>

int const NO_CLICKED  = 0;
int const CLICKED = 1;

class QDynamicButton : public QPushButton
{
    Q_OBJECT
public:
    QDynamicButton();
    ~QDynamicButton();
    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();

    int clickStatus = NO_CLICKED;
    int BoxNumber;

private:
    int boxID = 0;
};

#endif // QDYNAMICBUTTON_H
