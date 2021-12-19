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

private:
    Ui::categoriesWin *ui;
};

#endif // CATEGORIESWIN_H
