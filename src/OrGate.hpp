#ifndef ORGATE
#define ORGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class OrGate : public Gate
{
private:

public:
    OrGate(Gate *g1, Gate *g2);
    virtual ~OrGate();
    Gate* operationLogique();
};







#endif
