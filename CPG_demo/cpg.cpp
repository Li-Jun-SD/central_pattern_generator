#include "cpg.h"
#include <QDebug>

cpg::cpg()
{
    time   = 0.001;

    set(setStop);
}

void cpg::set(const double a[8][3])
{
    for (int i = 0; i < N; i++) {
        Omega[i]  = a[i][2];
        Offset[i] = a[i][1];
        Amp[i]    = a[i][0];
        // amplitude, offset, omega, time, gain.
        net[i].setRef(a[i][0], a[i][1], a[i][2], time, 20);
    }
}

void cpg::update(double &lHip, double &lKnee, double &rHip, double &rKnee)
{
    // calculate amplitude, offset, omega.
    for (int i = 0; i < N; i++) {
        net[i].cal(r[i], x[i], o[i]);
    }

    // calculate phi and output in this time.
    for (int i = 0; i < N; i++) {
        p[i][0] = p[i][0] + p[i][1] * time;
        y[i] = r[i] * sin (p[i][0]) + x[i];
//        y[i] = Amp[i] * sin (p[i][0]) + Offset[i];
        // Gui Kai don't really understand those parameters.
    }

    // calculate derivative of phi.
    for (int i = 0; i < N; i++) {
        p[i][1] = o[i];
//        p[i][1] = Omega[i];
        for (int j = 0; j < 2; j++) {
            if (i != j) {
                p[i][1] += weight[i][j] *
                           sin (p[j][0] - Omega[j] / Omega[i] * p[i][0] - phi_lag[i][j]);
            }
        }
    }

    rHip  = y[0] + y[1];
    rKnee = y[2] + y[3];
    lHip  = y[4] + y[5];
    lKnee = y[6] + y[7];

    qDebug() << rHip << ", " << rKnee << ", " << lHip << ", " << lKnee;
}

void cpg::stop()
{
    set(setStop);
}
