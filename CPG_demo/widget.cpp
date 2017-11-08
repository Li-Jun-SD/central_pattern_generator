#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLineSeries *line1 = new QLineSeries();
    for (double x= 0; x < 10; x += 0.1) {
        line1->append(x, sin(x));
    }
    QChart *c = new QChart();
    c->addSeries(line1);
    ui->chart->setChart(c);
}

Widget::~Widget()
{
    delete ui;
}
