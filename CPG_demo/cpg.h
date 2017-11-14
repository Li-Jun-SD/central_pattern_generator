#ifndef CPG_H
#define CPG_H
#include "neure.h"
#include <math.h>

const int N = 8;

// walk.
const double setWalk[8][3] = {{-12.94,  3.76, 2 * M_PI},  // R_hip_1
                              {  4.78,  3.76, 4 * M_PI},  // R_hip_2
                              {-23.69, 11.35, 2 * M_PI},  // R_knee_1
                              { 18.54, 11.35, 4 * M_PI},  // R_knee_2
                              { 12.94,  3.76, 2 * M_PI},  // l_hip_1
                              {  4.78,  3.76, 4 * M_PI},  // l_hip_2
                              { 23.69, 11.35, 2 * M_PI},  // l_knee_1
                              { 18.54, 11.35, 4 * M_PI}}; // l_knee_2
// stop.
const double setStop1[8][3] = {{0.0 ,  0.0 , 2 * M_PI},
                              {0.0 ,  0.0 , 4 * M_PI},
                              {0.0 ,  0.0 , 2 * M_PI},
                              {0.0 ,  0.0 , 4 * M_PI},
                              {0.0 ,  0.0 , 2 * M_PI},
                              {0.0 ,  0.0 , 4 * M_PI},
                              {0.0 ,  0.0 , 2 * M_PI},
                              {0.0 ,  0.0 , 4 * M_PI}};

// stop model 2.
const double setStop2[8][3] = {{0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0},
                                  {0.0 ,  0.0 , 0.0}};

// stop.
const double setStop3[8][3] = {{0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI},
                               {0.0 ,  0.0 , 2 * M_PI}};


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

//    // just knee, not work     1      2      3      4      5      6      7      8
//    double phi_lag[N][N] = {{ 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 1
//                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 2
//                            { 0.0 ,  0.0 ,  0.0 , -0.07,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 3
//                            { 0.0 ,  0.0 ,  0.04,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 4
//                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 5
//                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 6
//                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 },  // 7
//                            { 0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 ,  0.0 }}; // 8

    double time, g, weight;
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
