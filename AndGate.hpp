#ifndef ANDGATE
#define ANDGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"
using namespace std;

class AndGate : public Gate{

private:
    
public:

    AndGate(Gate *p1, Gate *p2);

    virtual ~AndGate();

    Gate* operationLogique();
};





#endif
