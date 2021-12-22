#pragma once
#include <QGroupBox>
#include <QPushButton>

#include "qdynamicbutton.h"

int const LIKE = 1;
int const DISLIKE = -1;
int const NOTHING = 0;

class QDynamicBox : public QGroupBox
{
    Q_OBJECT
public:
    explicit QDynamicBox(std::string &mem_id, QWidget *parent = 0, int likes = 0, int dislikes = 0);
    ~QDynamicBox();
    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID(); // Функция для возврата локального номера Box

    int like_status = NOTHING;
    int numberLike = 0;
    int numberDisLike = 0;
    std::string memID;

public slots:

private:
    int boxID = 0;

};

