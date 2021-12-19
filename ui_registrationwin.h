/********************************************************************************
** Form generated from reading UI file 'registrationwin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWIN_H
#define UI_REGISTRATIONWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_registrationWin
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_surname;
    QLineEdit *lineEdit_login;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_pass2;
    QPushButton *pushButton;
    QLabel *label_message;

    void setupUi(QDialog *registrationWin)
    {
        if (registrationWin->objectName().isEmpty())
            registrationWin->setObjectName(QString::fromUtf8("registrationWin"));
        registrationWin->resize(297, 272);
        verticalLayout = new QVBoxLayout(registrationWin);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(registrationWin);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_name = new QLineEdit(groupBox);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_name);

        lineEdit_surname = new QLineEdit(groupBox);
        lineEdit_surname->setObjectName(QString::fromUtf8("lineEdit_surname"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_surname);

        lineEdit_login = new QLineEdit(groupBox);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_login);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_pass = new QLineEdit(groupBox);
        lineEdit_pass->setObjectName(QString::fromUtf8("lineEdit_pass"));
        lineEdit_pass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_pass);

        lineEdit_pass2 = new QLineEdit(groupBox);
        lineEdit_pass2->setObjectName(QString::fromUtf8("lineEdit_pass2"));
        lineEdit_pass2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_pass2);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(5, QFormLayout::SpanningRole, pushButton);


        verticalLayout->addWidget(groupBox);

        label_message = new QLabel(registrationWin);
        label_message->setObjectName(QString::fromUtf8("label_message"));

        verticalLayout->addWidget(label_message);


        retranslateUi(registrationWin);

        QMetaObject::connectSlotsByName(registrationWin);
    } // setupUi

    void retranslateUi(QDialog *registrationWin)
    {
        registrationWin->setWindowTitle(QCoreApplication::translate("registrationWin", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("registrationWin", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
        label->setText(QCoreApplication::translate("registrationWin", "\320\230\320\274\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("registrationWin", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QCoreApplication::translate("registrationWin", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_4->setText(QCoreApplication::translate("registrationWin", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        label_5->setText(QCoreApplication::translate("registrationWin", "\320\237\320\260\321\200\320\276\320\273\321\214 \320\265\321\211\321\221 \321\200\320\260\320\267", nullptr));
        pushButton->setText(QCoreApplication::translate("registrationWin", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
        label_message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class registrationWin: public Ui_registrationWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWIN_H
