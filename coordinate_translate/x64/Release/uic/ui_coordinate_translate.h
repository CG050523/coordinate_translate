/********************************************************************************
** Form generated from reading UI file 'coordinate_translate.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORDINATE_TRANSLATE_H
#define UI_COORDINATE_TRANSLATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_coordinate_translateClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *coordinate_translateClass)
    {
        if (coordinate_translateClass->objectName().isEmpty())
            coordinate_translateClass->setObjectName(QString::fromUtf8("coordinate_translateClass"));
        coordinate_translateClass->resize(600, 400);
        menuBar = new QMenuBar(coordinate_translateClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        coordinate_translateClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(coordinate_translateClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        coordinate_translateClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(coordinate_translateClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        coordinate_translateClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(coordinate_translateClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        coordinate_translateClass->setStatusBar(statusBar);

        retranslateUi(coordinate_translateClass);

        QMetaObject::connectSlotsByName(coordinate_translateClass);
    } // setupUi

    void retranslateUi(QMainWindow *coordinate_translateClass)
    {
        coordinate_translateClass->setWindowTitle(QCoreApplication::translate("coordinate_translateClass", "coordinate_translate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class coordinate_translateClass: public Ui_coordinate_translateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORDINATE_TRANSLATE_H
