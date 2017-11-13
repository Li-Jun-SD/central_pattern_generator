#include "cpg.h"
#include <iostream>
#include <math.h>

cpg::cpg()
{

}

cpg::~cpg()
{

}

void cpg::setOmega(double a[2])
{
    for (int i = 0; i < 2; i++) {
        net[i].omega_ref = a[i];
    }
}

void cpg::setR(double a[2])
{
    for (int i = 0; i < 2; i++) {
        net[i].r_ref = a[i];
    }
}

void cpg::setX(double a[2])
{
    for (int i = 0; i < 2; i++) {
        net[i].x_ref = a[i];
    }
}

void cpg::setTime(double a)
{
    // head file math.h
    // #define M_PI 3.14159265358979323846
//    time = 2 * M_PI / a;
    time = 1 / a;
}

double cpg::update()
{
    for (int i = 0; i < 2; i++) {
        net[i].r[1]     = net[i].r[1] + net[i].r[0] * time;
        net[i].x[1]     = net[i].x[1] + net[i].x[0] * time;
        net[i].phi[1]   = net[i].phi[1] + net[i].phi[0] * time;
        net[i].omega[1] = net[i].omega[1] + net[i].omega[0] * time;

        net[i].r[0] = 2 * (net[i].r_ref - net[i].r[1]);
        net[i].x[0] = 2 * (net[i].x_ref - net[i].x[1]);
        net[i].omega[0] = 2 * (net[i].omega_ref - net[i].omega[1]);
    }

    net[0].phi[0] = net[0].omega[1] + 20 *
                    sin(net[1].phi[1] - net[1].omega_ref / net[0].omega_ref * net[0].phi[1] + 1.02);
    net[1].phi[0] = net[1].omega[1] + 20 *
                    sin(net[0].phi[1] - net[0].omega_ref / net[1].omega_ref * net[1].phi[1] + 0.41);
    for (int i = 0; i < 2; i++) {
        net[i].y = net[i].r[1] * sin(net[i].phi[1]) + net[i].x[1];
    }

    return net[0].y + net[1].y;
}

