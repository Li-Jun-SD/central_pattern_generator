#ifndef CPG_H
#define CPG_H

struct neure
{
    // reference parameters.
    double r_ref, x_ref, omega_ref;
    // state parameters.
    double r[2]     = {0.0};
    double phi[2]   = {0.0};
    double x[2]     = {0.0};
    double omega[2] = {0.0};
    // output.
    double y = 0.0;
};

class cpg
{
public:
    cpg();
    ~cpg();
    // some method to input reference parameters.
    void setR(double *);
    void setX(double *);
    void setOmega(double *);
    void setTime(double);
    double update();

private:
    // coupling weight.
    double phi_lag[2][2] = {{0   , -1.63},
                            {0.82, 0    }};
    // neure.
    neure net[2];
    // interval.
    double time;
};

#endif // CPG_H
