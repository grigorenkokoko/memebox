#ifndef REGISTRATIONWIN_H
#define REGISTRATIONWIN_H

#include <QDialog>
#include <QStatusBar>

namespace Ui {
class registrationWin;
}

class registrationWin : public QDialog
{
    Q_OBJECT

public:
    explicit registrationWin(QWidget *parent = nullptr);
    ~registrationWin();

private slots:
    void on_pushButton_clicked();

private:
    Ui::registrationWin *ui;
    // SecondWindow *window;

signals:
    void signalReg();
};

#endif // REGISTRATIONWIN_H
