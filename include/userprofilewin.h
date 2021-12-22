#pragma once

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

signals:
    void signalExitProf();

private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};

