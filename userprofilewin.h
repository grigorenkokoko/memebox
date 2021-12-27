#ifndef USERPROFILEWIN_H
#define USERPROFILEWIN_H

#include "categorieswin.h"
#include "qdynamiccheckboxtofile.h"
#include "qdynamicbutton.h"

#include <QDialog>
#include <QFile>
#include <QString>

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


private slots:
    void on_pushButton_5_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_downloadToFile_clicked();

    void on_pushButton_newName_clicked();

    void on_pushButton_newSurname_clicked();

    void on_pushButton_newPass_clicked();

    void on_pushButton_addCateg_clicked();

    void on_pushButton_addCategToPost_clicked();

    void on_pushButton_downloadToPost_clicked();

    void add_to_liked();

    void add_to_uploaded(QString search);

    void slot_on_pushButton_like_clicked();
    void slot_on_pushButton_dislike_clicked();
    void slot_on_pushButton_download_clicked();
    void slot_on_pushButton_plus_clicked();

    void slot_on_pushButton_like_touploaded_clicked();
    void slot_on_pushButton_dislike_touploaded_clicked();
    void slot_on_pushButton_download_touploaded_clicked();
    void slot_on_pushButton_plus_touploaded_clicked();

    void on_pushButton_search_clicked();

public slots:
    void slotAreaMaxValueToLiked(int value);
    void slotAreaMaxValueToUploaded(int value);

signals:
    void signalExitProf();
//    void signalCatedWin();
};

#endif // USERPROFILEWIN_H
