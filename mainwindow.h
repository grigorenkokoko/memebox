#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "secondwindow.h"
#include "registrationwin.h"
#include "userprofilewin.h"
#include "categorieswin.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_registration_clicked();

    void on_pushButton_authorization_clicked();

    void on_action_add_triggered();

    void on_action_open_triggered();

    void on_action_exit_triggered();

private:
    Ui::MainWindow *ui;
    SecondWindow *secWin = NULL;
    registrationWin *regWin = NULL;
//    userProfileWin *userWin = NULL;
    categoriesWin *categWin = NULL;

public slots:
    void slotSecWin();
    void slotCategWin();
//    void slotUserWin();
//    void slotCategWin();
    void slotExit();
};
#endif // MAINWINDOW_H
