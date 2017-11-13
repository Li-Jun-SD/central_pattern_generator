#include "mainwindow.h"
#include <QApplication>
#include "cpg.h"
#include <math.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    cpg network;
    double omega[2] = {2 * M_PI, 4 * M_PI};
    network.setOmega(omega);
    double r[2] = {23.69, 18.54};
    network.setR(r);
    double x[2] = {11.35, 11.35};
    network.setX(x);
    network.setTime(1000.0);
    for (int i = 0; i < 7000; i++) {
        if (i == 2000) {
            double r[2] = {0, 0};
            network.setR(r);
            double x[2] = {0, 0};
            network.setX(x);
        }
        if (i == 3000) {
            double r[2] = {12.94, 4.78};
            network.setR(r);
            double x[2] = {3.76, 3.76};
            network.setX(x);
        }
        if (i == 4000) {
            double r[2] = {0, 0};
            network.setR(r);
            double x[2] = {0, 0};
            network.setX(x);
        }
        qDebug() << network.update();
    }

    return a.exec();
}
