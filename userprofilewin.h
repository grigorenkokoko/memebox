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
    categoriesWin *categWin;

    QString m_fileName;
    QFile *m_file;


private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton__addCaegtoFile_clicked();

    void on_pushButton_addCaegtoPost_clicked();

public slots:
    void slotExitCateg();

signals:
    void signalExitProf();
//    void signalCatedWin();
};

#endif // USERPROFILEWIN_H
