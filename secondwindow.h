#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>

#include "qdynamicbox.h"
#include "qdynamicbutton.h"
#include "userprofilewin.h"



namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

    int n = 0;

private slots:
//    void on_pushButton_next_clicked();

//    void on_pushButton_back_clicked();

    void on_pushButton_exit_clicked();

    void on_pushButton_addBox_clicked();

    void slot_on_pushButton_like_clicked();
    void slot_on_pushButton_dislike_clicked();
    void slot_on_pushButton_download_clicked();


    void on_pushButton_clicked();

private:
    Ui::SecondWindow *ui;
    userProfileWin *userProf;

signals:
    void signalExit();
    void signalUserWin();

public slots:
    void slotExitProf();
    void slotAreaMaxValue();
//    void slotUserWin();
};

#endif // SECONDWINDOW_H
