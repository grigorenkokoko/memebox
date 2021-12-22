#pragma once

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

