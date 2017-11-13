#include "cpg.h"
#include <math.h>
#include <QDebug>

//#include "chart.h"
//#include <QtCharts/QChartView>
//#include <QtWidgets/QApplication>
//#include <QtWidgets/QMainWindow>

//QT_CHARTS_USE_NAMESPACE

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    QMainWindow window;
//    Chart *chart = new Chart;
//    chart->setTitle("Dynamic spline chart");
//    chart->legend()->hide();
//    chart->setAnimationOptions(QChart::AllAnimations);
//    QChartView chartView(chart);
//    chartView.setRenderHint(QPainter::Antialiasing);
//    window.setCentralWidget(&chartView);
//    window.resize(400, 300);
//    window.show();
//    return a.exec();
//}

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QSplineSeries>

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    cpg network;

    QApplication a(argc, argv);

    //![1]
    QSplineSeries *seriesRHip = new QSplineSeries();
    seriesRHip->setName("rHip");
    QSplineSeries *seriesRKnee = new QSplineSeries();
    seriesRKnee->setName("rKnee");
    QSplineSeries *seriesLHip = new QSplineSeries();
    seriesLHip->setName("lHip");
    QSplineSeries *seriesLKnee = new QSplineSeries();
    seriesLKnee->setName("lKnee");
    //![1]

    //![2]
    int T = 10000;
    network.set(setWalk);
    for (int i = 0; i < T; i++) {
//        if (i == 2000)
//            network.set(setWalk);
        if (i == 7000)
            network.set(setStop);
        double lHipData, lKneeData, rHipData, rKneeData;
        network.update(lHipData, lKneeData, rHipData, rKneeData);
        seriesRHip->append(i, rHipData);
        seriesRKnee->append(i, rKneeData);
        seriesLHip->append(i, lHipData);
        seriesLKnee->append(i, lKneeData);
    }
    //![2]

    //![3]
    QChart *chart = new QChart();
    chart->legend()->show();
//    chart->addSeries(seriesRHip);
//    chart->addSeries(seriesRKnee);
    chart->addSeries(seriesLHip);
    chart->addSeries(seriesLKnee);
    chart->setTitle("Central Pattern Generator");
    chart->createDefaultAxes();
    chart->axisY()->setRange(-20, 70);
    //![3]

    //![4]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    //![4]

    //![5]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
    //![5]

    return a.exec();
}
