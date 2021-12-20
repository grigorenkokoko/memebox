#ifndef CATEGORIESWIN_H
#define CATEGORIESWIN_H

#include <QDialog>

namespace Ui {
class categoriesWin;
}

class categoriesWin : public QDialog
{
    Q_OBJECT

public:
    explicit categoriesWin(QWidget *parent = nullptr);
    ~categoriesWin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_exitCateg_clicked();

private:
    Ui::categoriesWin *ui;

signals:
    void signalExitCateg();
//    void signalUserWin();
};

#endif // CATEGORIESWIN_H
