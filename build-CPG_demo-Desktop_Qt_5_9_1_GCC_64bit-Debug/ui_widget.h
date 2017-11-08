/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "QChartView"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QChartView *chart;
    QPushButton *pushButtonWalk;
    QPushButton *pushButtonStop;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(602, 381);
        chart = new QChartView(Widget);
        chart->setObjectName(QStringLiteral("chart"));
        chart->setGeometry(QRect(21, 21, 561, 301));
        pushButtonWalk = new QPushButton(Widget);
        pushButtonWalk->setObjectName(QStringLiteral("pushButtonWalk"));
        pushButtonWalk->setGeometry(QRect(496, 338, 80, 25));
        pushButtonStop = new QPushButton(Widget);
        pushButtonStop->setObjectName(QStringLiteral("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(364, 338, 80, 25));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        pushButtonWalk->setText(QApplication::translate("Widget", "stop", Q_NULLPTR));
        pushButtonStop->setText(QApplication::translate("Widget", "walk", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
