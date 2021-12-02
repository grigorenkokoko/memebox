#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

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
    void on_pushButton_next_clicked();

    void on_pushButton_back_clicked();

private:
    Ui::SecondWindow *ui;
};

#endif // SECONDWINDOW_H
