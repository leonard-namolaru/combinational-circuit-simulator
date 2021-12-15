#ifndef ORGATE
#define ORGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"
using namespace std;

class OrGate : public Gate
{
private:
    /* data */
public:
    OrGate(Gate *g1, Gate *g2);
    virtual ~OrGate();
};







#endif
