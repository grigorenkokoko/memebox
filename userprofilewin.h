#ifndef USERPROFILEWIN_H
#define USERPROFILEWIN_H

#include "categorieswin.h"
#include "qdynamiccheckboxtofile.h"

#include <QDialog>
#include <QFile>

namespace Ui {
class userProfileWin;
}

class userProfileWin : public QDialog
{
    Q_OBJECT

public:
    explicit userProfileWin(QWidget *parent = nullptr);
    ~userProfileWin();

private:
    Ui::userProfileWin *ui;

    QString m_fileName;
    QFile *m_file;


private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_downloadToFile_clicked();

    void on_pushButton_newName_clicked();

    void on_pushButton_newSurname_clicked();

    void on_pushButton_newPass_clicked();

    void on_pushButton_addCateg_clicked();

    void on_pushButton_addCategToPost_clicked();

    void on_pushButton_downloadToPost_clicked();

public slots:

signals:
    void signalExitProf();
//    void signalCatedWin();
};

#endif // USERPROFILEWIN_H
