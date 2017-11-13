#ifndef NEURE_H
#define NEURE_H

class neure
{
public:
    neure();

    // functions interface.
    void setRef(double r_ref, double x_ref, double o_ref, double t_ref, double g_ref);
    void calculate(double *, double, double &out);
    void cal(double &, double &, double &);

private:
    // reference parameters and some parameters for calculate.
    double R, X, Omega, g, t;

    // state parameters.
    double r[3], x[3], omega[3];
};

#endif // NEURE_H
