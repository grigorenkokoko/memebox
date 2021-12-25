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

    QString userID;

private slots:

    void on_pushButton_exitCateg_clicked();

private:
    Ui::categoriesWin *ui;

signals:
    void signalSecWin();
//    void signalUserWin();
};

#endif // CATEGORIESWIN_H
