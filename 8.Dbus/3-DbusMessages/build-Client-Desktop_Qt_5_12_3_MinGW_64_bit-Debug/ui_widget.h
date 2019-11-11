/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QDoubleSpinBox *number1SpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *number2SpinBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *multiplyButton;
    QPushButton *divideButton;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *resultLineEdit;
    QPushButton *messageToServerButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 169);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        number1SpinBox = new QDoubleSpinBox(Widget);
        number1SpinBox->setObjectName(QString::fromUtf8("number1SpinBox"));

        horizontalLayout->addWidget(number1SpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        number2SpinBox = new QDoubleSpinBox(Widget);
        number2SpinBox->setObjectName(QString::fromUtf8("number2SpinBox"));

        horizontalLayout_2->addWidget(number2SpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        multiplyButton = new QPushButton(Widget);
        multiplyButton->setObjectName(QString::fromUtf8("multiplyButton"));

        horizontalLayout_3->addWidget(multiplyButton);

        divideButton = new QPushButton(Widget);
        divideButton->setObjectName(QString::fromUtf8("divideButton"));

        horizontalLayout_3->addWidget(divideButton);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        resultLineEdit = new QLineEdit(Widget);
        resultLineEdit->setObjectName(QString::fromUtf8("resultLineEdit"));

        horizontalLayout_4->addWidget(resultLineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        messageToServerButton = new QPushButton(Widget);
        messageToServerButton->setObjectName(QString::fromUtf8("messageToServerButton"));

        verticalLayout->addWidget(messageToServerButton);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        label->setText(QApplication::translate("Widget", "Client", nullptr));
        label_2->setText(QApplication::translate("Widget", "Number 1 : ", nullptr));
        label_3->setText(QApplication::translate("Widget", "Number 2 : ", nullptr));
        multiplyButton->setText(QApplication::translate("Widget", "Multiply", nullptr));
        divideButton->setText(QApplication::translate("Widget", "Divide", nullptr));
        label_4->setText(QApplication::translate("Widget", "Result : ", nullptr));
        messageToServerButton->setText(QApplication::translate("Widget", "Send Message to Server", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
