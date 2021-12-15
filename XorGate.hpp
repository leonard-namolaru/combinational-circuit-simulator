#ifndef XORGATE
#define XORGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class XorGate : public Gate
{
private:
    /* data */
public:
    XorGate(Gate *g1, Gate *g2);
    virtual ~XorGate();
};







#endif
