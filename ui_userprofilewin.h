/********************************************************************************
** Form generated from reading UI file 'userprofilewin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERPROFILEWIN_H
#define UI_USERPROFILEWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userProfileWin
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label;
    QPushButton *pushButton_2;
    QLabel *label_6;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_newPass;
    QLineEdit *lineEdit_nowPass;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_surname;
    QLineEdit *lineEdit_name;
    QLabel *label_5;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_newPassAgain;
    QSpacerItem *verticalSpacer;
    QLabel *label_3;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_file;
    QLabel *label_7;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton__addCaegtoFile;
    QPushButton *pushButton_4;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLineEdit *lineEdit_7;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_6;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *verticalLayout_9;
    QPushButton *pushButton_addCaegtoPost;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;

    void setupUi(QDialog *userProfileWin)
    {
        if (userProfileWin->objectName().isEmpty())
            userProfileWin->setObjectName(QString::fromUtf8("userProfileWin"));
        userProfileWin->resize(386, 569);
        verticalLayout = new QVBoxLayout(userProfileWin);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(userProfileWin);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 3, 1, 1);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 3, 1, 1);

        lineEdit_newPass = new QLineEdit(tab);
        lineEdit_newPass->setObjectName(QString::fromUtf8("lineEdit_newPass"));
        lineEdit_newPass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_newPass, 4, 2, 1, 2);

        lineEdit_nowPass = new QLineEdit(tab);
        lineEdit_nowPass->setObjectName(QString::fromUtf8("lineEdit_nowPass"));
        lineEdit_nowPass->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_nowPass, 3, 2, 1, 2);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 6, 0, 1, 4);

        lineEdit_surname = new QLineEdit(tab);
        lineEdit_surname->setObjectName(QString::fromUtf8("lineEdit_surname"));

        gridLayout->addWidget(lineEdit_surname, 2, 1, 1, 2);

        lineEdit_name = new QLineEdit(tab);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        gridLayout->addWidget(lineEdit_name, 1, 1, 1, 2);

        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_login = new QLineEdit(tab);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));
        lineEdit_login->setReadOnly(true);

        gridLayout->addWidget(lineEdit_login, 0, 1, 1, 2);

        lineEdit_newPassAgain = new QLineEdit(tab);
        lineEdit_newPassAgain->setObjectName(QString::fromUtf8("lineEdit_newPassAgain"));
        lineEdit_newPassAgain->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(lineEdit_newPassAgain, 5, 2, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        scrollArea = new QScrollArea(tab_2);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 336, 458));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_3 = new QVBoxLayout(tab_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        scrollArea_2 = new QScrollArea(tab_3);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 336, 458));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_3->addWidget(scrollArea_2);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_6 = new QVBoxLayout(tab_4);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget_2 = new QTabWidget(tab_4);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_5 = new QVBoxLayout(tab_5);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 110));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMouseTracking(false);

        formLayout->setWidget(3, QFormLayout::SpanningRole, pushButton_3);

        lineEdit_file = new QLineEdit(groupBox_2);
        lineEdit_file->setObjectName(QString::fromUtf8("lineEdit_file"));
        lineEdit_file->setMouseTracking(true);
        lineEdit_file->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_file);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_7);


        verticalLayout_5->addWidget(groupBox_2);

        scrollArea_3 = new QScrollArea(tab_5);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 310, 254));
        verticalLayout_8 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));

        verticalLayout_8->addLayout(verticalLayout_7);

        pushButton__addCaegtoFile = new QPushButton(scrollAreaWidgetContents_4);
        pushButton__addCaegtoFile->setObjectName(QString::fromUtf8("pushButton__addCaegtoFile"));

        verticalLayout_8->addWidget(pushButton__addCaegtoFile);

        scrollArea_3->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_5->addWidget(scrollArea_3);

        pushButton_4 = new QPushButton(tab_5);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        verticalLayout_5->addWidget(pushButton_4);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        verticalLayout_4 = new QVBoxLayout(tab_6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(tab_6);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 100));
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_7);


        verticalLayout_4->addWidget(groupBox);

        scrollArea_4 = new QScrollArea(tab_6);
        scrollArea_4->setObjectName(QString::fromUtf8("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 310, 309));
        verticalLayout_10 = new QVBoxLayout(scrollAreaWidgetContents_6);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));

        verticalLayout_10->addLayout(verticalLayout_9);

        pushButton_addCaegtoPost = new QPushButton(scrollAreaWidgetContents_6);
        pushButton_addCaegtoPost->setObjectName(QString::fromUtf8("pushButton_addCaegtoPost"));

        verticalLayout_10->addWidget(pushButton_addCaegtoPost);

        scrollArea_4->setWidget(scrollAreaWidgetContents_6);

        verticalLayout_4->addWidget(scrollArea_4);

        pushButton_7 = new QPushButton(tab_6);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        verticalLayout_4->addWidget(pushButton_7);

        tabWidget_2->addTab(tab_6, QString());

        verticalLayout_6->addWidget(tabWidget_2);

        tabWidget->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget);

        pushButton_5 = new QPushButton(userProfileWin);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);


        retranslateUi(userProfileWin);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(userProfileWin);
    } // setupUi

    void retranslateUi(QDialog *userProfileWin)
    {
        userProfileWin->setWindowTitle(QCoreApplication::translate("userProfileWin", "Dialog", nullptr));
        label_4->setText(QCoreApplication::translate("userProfileWin", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QCoreApplication::translate("userProfileWin", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userProfileWin", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\204\320\260\320\274\320\270\320\273\320\270\321\216", nullptr));
        label_6->setText(QCoreApplication::translate("userProfileWin", "\320\237\320\276\320\262\321\202\320\276\321\200 \320\277\320\260\321\200\320\276\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("userProfileWin", "\320\230\320\274\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("userProfileWin", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\274\321\217", nullptr));
        pushButton_6->setText(QCoreApplication::translate("userProfileWin", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("userProfileWin", "\320\235\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("userProfileWin", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("userProfileWin", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("userProfileWin", "\320\237\320\276\320\275\321\200\320\260\320\262", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("userProfileWin", "\320\233\320\265\320\275\321\202\320\260", nullptr));
        groupBox_2->setTitle(QString());
        pushButton_3->setText(QCoreApplication::translate("userProfileWin", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label_7->setText(QCoreApplication::translate("userProfileWin", "\320\237\321\203\320\270\321\202\321\214", nullptr));
        pushButton__addCaegtoFile->setText(QCoreApplication::translate("userProfileWin", "add", nullptr));
        pushButton_4->setText(QCoreApplication::translate("userProfileWin", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QCoreApplication::translate("userProfileWin", "\320\244\320\260\320\271\320\273", nullptr));
        groupBox->setTitle(QString());
        label_8->setText(QCoreApplication::translate("userProfileWin", "\320\241\321\201\321\213\320\273\320\272\320\260 \320\275\320\260 \320\277\320\276\321\201\321\202", nullptr));
        pushButton_addCaegtoPost->setText(QCoreApplication::translate("userProfileWin", "add", nullptr));
        pushButton_7->setText(QCoreApplication::translate("userProfileWin", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QCoreApplication::translate("userProfileWin", "\320\237\320\276\321\201\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("userProfileWin", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        pushButton_5->setText(QCoreApplication::translate("userProfileWin", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userProfileWin: public Ui_userProfileWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERPROFILEWIN_H
