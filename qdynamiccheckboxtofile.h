#ifndef QDYNAMICCHECKBOXTOFILE_H
#define QDYNAMICCHECKBOXTOFILE_H

#include <QCheckBox>

class QDynamicCheckBoxToFile : public QCheckBox
{
public:
    QDynamicCheckBoxToFile();

    static int ResID;  // Статическая переменная, счетчик номеров Box
    int getID();

//    QString categorieName;
    QString categID;

private:
    int boxID = 0;
};


#endif // QDYNAMICCHECKBOXTOFILE_H
