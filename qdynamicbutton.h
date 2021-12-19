#ifndef QDYNAMICBUTTON_H
#define QDYNAMICBUTTON_H

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

#endif // QDYNAMICBUTTON_H
