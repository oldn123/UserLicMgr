/********************************************************************************
** Form generated from reading UI file 'newLic.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWLIC_H
#define UI_NEWLIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_newLic
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_softName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_userName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QTextEdit *lineEdit_macCode;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QComboBox *comboBox_LicType;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_disc;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateTimeEdit *dateTimeEdit_from;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QDateTimeEdit *dateTimeEdit_to;
    QPushButton *pushButton_makeLic;
    QTextEdit *textEdit_licCode;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newLic)
    {
        if (newLic->objectName().isEmpty())
            newLic->setObjectName(QStringLiteral("newLic"));
        newLic->resize(391, 411);
        verticalLayout_2 = new QVBoxLayout(newLic);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(newLic);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_softName = new QComboBox(newLic);
        comboBox_softName->setObjectName(QStringLiteral("comboBox_softName"));

        horizontalLayout->addWidget(comboBox_softName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(newLic);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_userName = new QLineEdit(newLic);
        lineEdit_userName->setObjectName(QStringLiteral("lineEdit_userName"));

        horizontalLayout_2->addWidget(lineEdit_userName);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(newLic);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_macCode = new QTextEdit(newLic);
        lineEdit_macCode->setObjectName(QStringLiteral("lineEdit_macCode"));

        horizontalLayout_3->addWidget(lineEdit_macCode);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(newLic);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        comboBox_LicType = new QComboBox(newLic);
        comboBox_LicType->setObjectName(QStringLiteral("comboBox_LicType"));

        horizontalLayout_7->addWidget(comboBox_LicType);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(newLic);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_disc = new QLineEdit(newLic);
        lineEdit_disc->setObjectName(QStringLiteral("lineEdit_disc"));

        horizontalLayout_4->addWidget(lineEdit_disc);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(newLic);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_5->addWidget(label_4);

        dateTimeEdit_from = new QDateTimeEdit(newLic);
        dateTimeEdit_from->setObjectName(QStringLiteral("dateTimeEdit_from"));

        horizontalLayout_5->addWidget(dateTimeEdit_from);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_5 = new QLabel(newLic);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_6->addWidget(label_5);

        dateTimeEdit_to = new QDateTimeEdit(newLic);
        dateTimeEdit_to->setObjectName(QStringLiteral("dateTimeEdit_to"));

        horizontalLayout_6->addWidget(dateTimeEdit_to);


        verticalLayout->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_makeLic = new QPushButton(newLic);
        pushButton_makeLic->setObjectName(QStringLiteral("pushButton_makeLic"));

        verticalLayout_2->addWidget(pushButton_makeLic);

        textEdit_licCode = new QTextEdit(newLic);
        textEdit_licCode->setObjectName(QStringLiteral("textEdit_licCode"));

        verticalLayout_2->addWidget(textEdit_licCode);

        buttonBox = new QDialogButtonBox(newLic);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        retranslateUi(newLic);
        QObject::connect(buttonBox, SIGNAL(accepted()), newLic, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), newLic, SLOT(reject()));

        QMetaObject::connectSlotsByName(newLic);
    } // setupUi

    void retranslateUi(QDialog *newLic)
    {
        newLic->setWindowTitle(QApplication::translate("newLic", "\346\226\260\345\273\272\346\216\210\346\235\203", 0));
        label->setText(QApplication::translate("newLic", "\344\272\247    \345\223\201", 0));
        label_2->setText(QApplication::translate("newLic", "\347\224\250\346\210\267\345\220\215\347\247\260", 0));
        label_3->setText(QApplication::translate("newLic", "\346\234\272 \345\231\250 \347\240\201", 0));
        label_7->setText(QApplication::translate("newLic", "\347\261\273    \345\236\213", 0));
        comboBox_LicType->clear();
        comboBox_LicType->insertItems(0, QStringList()
         << QApplication::translate("newLic", "\350\257\225\347\224\250", 0)
         << QApplication::translate("newLic", "\346\255\243\345\274\217", 0)
        );
        label_6->setText(QApplication::translate("newLic", "\346\217\217    \350\277\260", 0));
        label_4->setText(QApplication::translate("newLic", "\350\265\267\345\247\213\346\227\266\351\227\264", 0));
        label_5->setText(QApplication::translate("newLic", "\347\273\210\346\255\242\346\227\266\351\227\264", 0));
        pushButton_makeLic->setText(QApplication::translate("newLic", "\347\224\237\346\210\220\346\216\210\346\235\203", 0));
    } // retranslateUi

};

namespace Ui {
    class newLic: public Ui_newLic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWLIC_H
