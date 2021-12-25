/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_add;
    QAction *action_open;
    QAction *action_exit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *login;
    QLabel *label_3;
    QLineEdit *pass;
    QPushButton *pushButton_authorization;
    QCheckBox *checkBox;
    QPushButton *pushButton_registration;
    QLabel *image;
    QPushButton *pushButton_exit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(297, 487);
        action_add = new QAction(MainWindow);
        action_add->setObjectName(QString::fromUtf8("action_add"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resource/img/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_add->setIcon(icon);
        action_open = new QAction(MainWindow);
        action_open->setObjectName(QString::fromUtf8("action_open"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resource/img/free-icon-open-folder-outline-25402.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_open->setIcon(icon1);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resource/img/free-icon-exit-1286853.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_exit->setIcon(icon2);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        login = new QLineEdit(groupBox);
        login->setObjectName(QString::fromUtf8("login"));

        formLayout->setWidget(0, QFormLayout::FieldRole, login);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        pass = new QLineEdit(groupBox);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, pass);

        pushButton_authorization = new QPushButton(groupBox);
        pushButton_authorization->setObjectName(QString::fromUtf8("pushButton_authorization"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, pushButton_authorization);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, checkBox);

        pushButton_registration = new QPushButton(groupBox);
        pushButton_registration->setObjectName(QString::fromUtf8("pushButton_registration"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, pushButton_registration);


        verticalLayout->addWidget(groupBox);

        image = new QLabel(centralwidget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setPixmap(QPixmap(QString::fromUtf8("img/2021-11-19_15-45-31.png")));

        verticalLayout->addWidget(image);

        pushButton_exit = new QPushButton(centralwidget);
        pushButton_exit->setObjectName(QString::fromUtf8("pushButton_exit"));

        verticalLayout->addWidget(pushButton_exit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 297, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        action_add->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        action_open->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        action_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\260\321\206\320\270\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        pushButton_authorization->setText(QCoreApplication::translate("MainWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\321\214", nullptr));
        pushButton_registration->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        image->setText(QString());
        pushButton_exit->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
