#ifndef QDYNAMICBOXTOUPLOADED_H
#define QDYNAMICBOXTOUPLOADED_H

#include <QGroupBox>
#include <QPushButton>

#include "qdynamicbutton.h"
#include "qdynamicbox.h"



class QDynamicBoxToUploaded : public QGroupBox
{
    Q_OBJECT
public:
    explicit QDynamicBoxToUploaded(QWidget *parent = 0);
    ~QDynamicBoxToUploaded();
    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();  // Функция для возврата локального номера Box

    int like_status = NOTHING;
    int numberLike = 0;
    int numberDisLike = 0;
    QString memID;

public slots:

private:
    int boxID = 0;

};

#endif // QDYNAMICBOX_H

