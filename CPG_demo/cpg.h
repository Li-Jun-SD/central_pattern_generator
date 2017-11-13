#ifndef CPG_H
#define CPG_H
#include "neure.h"
#include <math.h>

const int N = 8;

// walk.
//const double setWalk[N][3] = {{-12.94,  3.76, 2 * M_PI},  // 0 R_hip_1
//                              {  4.78,  3.76, 4 * M_PI},  // 1 R_hip_2
//                              {-23.69, 11.35, 2 * M_PI},  // 2 R_knee_1
//                              { 18.54, 11.35, 4 * M_PI},  // 3 R_knee_2
//                              { 12.94,  3.76, 2 * M_PI},  // 4 l_hip_1
//                              {  4.78,  3.76, 4 * M_PI},  // 5 l_hip_2
//                              { 23.69, 11.35, 2 * M_PI},  // 6 l_knee_1
//                              { 18.54, 11.35, 4 * M_PI}}; // 7 l_knee_2
const double setWalk[N][3] = {{-12.94,  3.76,  6.18},  // 0 R_hip_1
                              {  4.78,  3.76, 12.56},  // 1 R_hip_2
                              {-23.69, 11.35,  6.18},  // 2 R_knee_1
                              { 18.54, 11.35, 12.56},  // 3 R_knee_2
                              { 12.94,  3.76,  6.18},  // 4 l_hip_1
                              {  4.78,  3.76, 12.56},  // 5 l_hip_2
                              { 23.69, 11.35,  6.18},  // 6 l_knee_1
                              { 18.54, 11.35, 12.56}}; // 7 l_knee_2
// stop.
//const double setStop[8][3] = {{0.0 ,  0.0 , 2 * M_PI},
//                              {0.0 ,  0.0 , 4 * M_PI},
//                              {0.0 ,  0.0 , 2 * M_PI},
//                              {0.0 ,  0.0 , 4 * M_PI},
//                              {0.0 ,  0.0 , 2 * M_PI},
//                              {0.0 ,  0.0 , 4 * M_PI},
//                              {0.0 ,  0.0 , 2 * M_PI},
//                              {0.0 ,  0.0 , 4 * M_PI}};
const double setStop[N][3] = {{0.0 ,  0.0 ,  6.18},
                              {0.0 ,  0.0 , 12.56},
                              {0.0 ,  0.0 ,  6.18},
                              {0.0 ,  0.0 , 12.56},
                              {0.0 ,  0.0 ,  6.18},
                              {0.0 ,  0.0 , 12.56},
                              {0.0 ,  0.0 ,  6.18},
                              {0.0 ,  0.0 , 12.56}};

class cpg
{
public:
    cpg();

    // some method to input reference parameters and update data.
    void set(const double a[N][3]);
    void update(double &lHip, double &lKnee, double &rHip, double &rKnee);

private:
    // coupling phase lag, weight, interval.
    //                         1      2      3      4      5      6      7        8
    double phi_lag[N][N] = {{ 0.0 , -1.63,  0.0 ,  0.0 ,  0.4 ,  0.0 ,  0.0   ,  0.0 },  // 1
                            { 0.82,  0.0 , -0.35,  0.0 ,  0.0 ,  0.0 ,  0.0   ,  0.0 },  // 2
                            { 0.0 ,  0.98,  0.0 , -0.07,  0.0 ,  0.0 ,  0.0   ,  0.0 },  // 3
                            { 0.0 ,  0.0 ,  0.04,  0.0 ,  0.0 ,  0.0 ,  0.0   ,  0.0 },  // 4
                            {-0.04,  0.0 ,  0.0 ,  0.0 ,  0.0 , -1.64,  0.0   ,  0.0 },  // 5
                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.84,  0.0 , -0.49  ,  0.0 },  // 6
                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.98,  0.0   ,  0.01},  // 7
                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0063,  0.0 }}; // 8
    double weight[N][N] = {{2}};
    double time, g;
    double Amp[N], Omega[N], Offset[N];

    // calculate parameters phase.
    double p[N][2] = {{0.0}};
    // amplitude, offset, frequency, output.
    double r[N] = {0.0};
    double x[N] = {0.0};
    double o[N] = {0.0};
    double y[N] = {0.0};

    // neure.
    neure net[N];
};

#endif // CPG_H
