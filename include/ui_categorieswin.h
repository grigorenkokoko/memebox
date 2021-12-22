/********************************************************************************
** Form generated from reading UI file 'categorieswin.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#pragma once

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_categoriesWin
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *categoriesWin)
    {
        if (categoriesWin->objectName().isEmpty())
            categoriesWin->setObjectName(QString::fromUtf8("categoriesWin"));
        categoriesWin->resize(293, 371);
        verticalLayout = new QVBoxLayout(categoriesWin);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(categoriesWin);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 269, 315));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_2->addWidget(checkBox);


        verticalLayout_3->addLayout(verticalLayout_2);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        pushButton = new QPushButton(categoriesWin);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);


        retranslateUi(categoriesWin);

        QMetaObject::connectSlotsByName(categoriesWin);
    } // setupUi

    void retranslateUi(QDialog *categoriesWin)
    {
        categoriesWin->setWindowTitle(QCoreApplication::translate("categoriesWin", "Dialog", nullptr));
        checkBox->setText(QCoreApplication::translate("categoriesWin", "CheckBox", nullptr));
        pushButton_2->setText(QCoreApplication::translate("categoriesWin", "add", nullptr));
        pushButton->setText(QCoreApplication::translate("categoriesWin", "\320\237\320\276\320\264\321\202\320\262\320\265\321\200\320\264\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class categoriesWin: public Ui_categoriesWin {};
} // namespace Ui

QT_END_NAMESPACE

