#include "cpg.h"
#include <QDebug>

cpg::cpg()
{
    time =  0.001;
    g    = 20;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j)
                weight[i][j] = 20;
        }
    }

    set(setStop);
}

void cpg::set(const double a[N][3])
{
    for (int i = 0; i < N; i++) {
        Omega[i]  = a[i][2];
        Offset[i] = a[i][1];
        Amp[i]    = a[i][0];
        // amplitude, offset, omega, time, gain.
        net[i].setRef(a[i][0], a[i][1], a[i][2], time, g);
    }
}

void cpg::update(double &lHip, double &lKnee, double &rHip, double &rKnee)
{
    for (int i = 0; i < N; i++) {
        qDebug() << p[i][0] << ", " << p[i][1];
    }
    qDebug() << "******************";

    // calculate amplitude, offset, omega.
    for (int i = 0; i < N; i++) {
        net[i].cal(r[i], x[i], o[i]);
    }

    // calculate phi and output in this time.
    for (int i = 0; i < N; i++) {
        p[i][0] = p[i][0] + p[i][1] * time;
        y[i] = r[i] * sin (p[i][0]) + x[i];
    }

    // calculate derivative of phi.
    for (int i = 0; i < N; i++) {
        p[i][1] = o[i];
        for (int j = 0; j < N; j++) {
            p[i][1] += weight[i][j]
                     * sin (p[j][0] - (Omega[j] / Omega[i]) * p[i][0] - phi_lag[i][j]);
        }
    }

    rHip  = y[0] + y[1];
    rKnee = y[2] + y[3];
    lHip  = y[4] + y[5];
    lKnee = y[6] + y[7];

    qDebug() << rHip << ", " << rKnee << ", " << lHip << ", " << lKnee;

//    qDebug() << y[0] << ", " << y[1];
//    qDebug() << y[2] << ", " << y[3];
//    qDebug() << y[4] << ", " << y[5];
//    qDebug() << y[6] << ", " << y[7];
//    qDebug() << "******************";
}
