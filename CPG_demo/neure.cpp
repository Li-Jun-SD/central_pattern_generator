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
    // calculate position.
    a[0] = a[0] + a[1] * t;
    out = a[0];
    // calculate speed.
    a[1] = a[1] + a[2] * t;
    // calculate acceleration.
    a[2] = g / 4 * (g * (ref - a[0]) - a[1]);
}

// return amplitude, offset and omega.
void neure::cal(double &rOut, double &xOut, double &oOut)
{
    calculate(r, R, rOut);
    calculate(x, X, xOut);
    calculate(omega, Omega, oOut);
}
