/********************************************************************************
** Form generated from reading UI file 'makeuserlic.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEUSERLIC_H
#define UI_MAKEUSERLIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_makeUserLicClass
{
public:
    QAction *actionSoft;
    QAction *actionLic;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *makeUserLicClass)
    {
        if (makeUserLicClass->objectName().isEmpty())
            makeUserLicClass->setObjectName(QStringLiteral("makeUserLicClass"));
        makeUserLicClass->resize(584, 498);
        actionSoft = new QAction(makeUserLicClass);
        actionSoft->setObjectName(QStringLiteral("actionSoft"));
        actionLic = new QAction(makeUserLicClass);
        actionLic->setObjectName(QStringLiteral("actionLic"));
        widget = new QWidget(makeUserLicClass);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        makeUserLicClass->setCentralWidget(widget);
        menuBar = new QMenuBar(makeUserLicClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 584, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        makeUserLicClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(makeUserLicClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        makeUserLicClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(makeUserLicClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        makeUserLicClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionSoft);
        menu->addAction(actionLic);

        retranslateUi(makeUserLicClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(makeUserLicClass);
    } // setupUi

    void retranslateUi(QMainWindow *makeUserLicClass)
    {
        makeUserLicClass->setWindowTitle(QApplication::translate("makeUserLicClass", "\346\216\210\346\235\203\347\256\241\347\220\206\345\267\245\345\205\267", 0));
        actionSoft->setText(QApplication::translate("makeUserLicClass", "\344\272\247\345\223\201", 0));
        actionLic->setText(QApplication::translate("makeUserLicClass", "\346\216\210\346\235\203", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("makeUserLicClass", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("makeUserLicClass", "Tab 2", 0));
        menu->setTitle(QApplication::translate("makeUserLicClass", "\346\226\260\345\273\272", 0));
    } // retranslateUi

};

namespace Ui {
    class makeUserLicClass: public Ui_makeUserLicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEUSERLIC_H
