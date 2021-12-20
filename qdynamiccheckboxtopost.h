#ifndef QDYNAMICCHECKBOXTOPOST_H
#define QDYNAMICCHECKBOXTOPOST_H

#include <QCheckBox>

class QDynamicCheckBoxToPost : public QCheckBox
{
public:
    QDynamicCheckBoxToPost();

    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();

//    QString categorieName;
    QString categID;

private:
    int boxID = 0;
};

#endif // QDYNAMICCHECKBOXTOPOST_H
