#include "neure.h"

neure::neure()
{
    r[3]     = {0.0};
    x[3]     = {0.0};
    omega[3] = {0.0};
}

// set some parameters for calculate.
void neure::setRef(double r_ref, double x_ref, double o_ref, double t_ref, double g_ref)
{
    R     = r_ref;
    X     = x_ref;
    Omega = o_ref;

    g     = g_ref;
    t     = t_ref;
}

// calculate new data base on parts of CPG model.
void neure::calculate(double *a, double ref, double &out)
{
    // method 1:
    // calculate position.
    a[0] = a[0] + a[1] * t;
    // calculate speed.
    a[1] = a[1] + a[2] * t;
    // calculate acceleration.
    a[2] = g / 0.25 * (g * (ref - a[0]) - a[1]);
    // when the constant below the first g become smaller, its overshoot and
    // shock would be smaller. and almost has no effects to accomodation time.
    // method 1 can change smoothly, but its overshoot and shock is serious.

//    // method 2:
//    a[0] = a[0] + a[1] * t;
//    a[1] = g * (ref - a[0]);
//    // method 2 cant change smmothly, it always has some peak in change point.
//    // but it has less overshoot and stable quickly.

    // method 3:
    // i think if we can get current state parameters, we could use PID to control
    // those parameter go to reference.

    out = a[0];
}

// return amplitude, offset and omega.
void neure::cal(double &rOut, double &xOut, double &oOut)
{
    calculate(r, R, rOut);
    calculate(x, X, xOut);
    calculate(omega, Omega, oOut);
}
