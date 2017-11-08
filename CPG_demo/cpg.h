#ifndef CPG_H
#define CPG_H
#include <iostream>

class CPG
{
public:
    CPG();
    ~CPG();

    void setRef(double amp, double off, double pal);  // set reference parameters, amplitude, offset, palstance.
    double updatePVT();                               // generating new PVT data.

private:
    double AMP, OFFSET, PAL; // reference parameters.
    double ampOld, ampNew;   // amplitude.
    double offOld, offNew;   // offset.
    double palOld, palNew;   // palstance.
    double out, outVel;      // position and velocity.
};

#endif // CPG_H
