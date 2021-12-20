#ifndef QDYNAMICCHECKBOX_H
#define QDYNAMICCHECKBOX_H

#include <QCheckBox>

class QDynamicCheckBox : public QCheckBox
{
public:
    QDynamicCheckBox();

    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();

//    QString categorieName;
    QString categID;

private:
    int boxID = 0;
};

#endif // QDYNAMICCHECKBOX_H
