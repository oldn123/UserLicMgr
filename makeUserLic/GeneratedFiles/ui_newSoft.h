/********************************************************************************
** Form generated from reading UI file 'newSoft.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWSOFT_H
#define UI_NEWSOFT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit_softName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *lineEdit_softId;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QLabel *label_2;
    QLineEdit *lineEdit_Key1;
    QLineEdit *lineEdit_Key2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(301, 126);
        verticalLayout_2 = new QVBoxLayout(Dialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette);

        horizontalLayout->addWidget(label_4);

        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        lineEdit_softName = new QLineEdit(Dialog);
        lineEdit_softName->setObjectName(QStringLiteral("lineEdit_softName"));

        horizontalLayout->addWidget(lineEdit_softName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_5->setPalette(palette1);

        horizontalLayout_3->addWidget(label_5);

        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_softId = new QLineEdit(Dialog);
        lineEdit_softId->setObjectName(QStringLiteral("lineEdit_softId"));

        horizontalLayout_3->addWidget(lineEdit_softId);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_6 = new QLabel(Dialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_6->setPalette(palette2);

        horizontalLayout_2->addWidget(label_6);

        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_Key1 = new QLineEdit(Dialog);
        lineEdit_Key1->setObjectName(QStringLiteral("lineEdit_Key1"));
        lineEdit_Key1->setMaxLength(8);

        horizontalLayout_2->addWidget(lineEdit_Key1);

        lineEdit_Key2 = new QLineEdit(Dialog);
        lineEdit_Key2->setObjectName(QStringLiteral("lineEdit_Key2"));
        lineEdit_Key2->setMaxLength(8);

        horizontalLayout_2->addWidget(lineEdit_Key2);


        verticalLayout->addLayout(horizontalLayout_2);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\346\226\260\345\273\272\344\272\247\345\223\201", 0));
        label_4->setText(QApplication::translate("Dialog", "*", 0));
        label->setText(QApplication::translate("Dialog", "\344\272\247 \345\223\201 \345\220\215:", 0));
        label_5->setText(QApplication::translate("Dialog", "*", 0));
        label_3->setText(QApplication::translate("Dialog", "\344\272\247 \345\223\201 \347\240\201:", 0));
        label_6->setText(QApplication::translate("Dialog", "*", 0));
        label_2->setText(QApplication::translate("Dialog", "\347\247\230    \351\222\245:", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWSOFT_H
