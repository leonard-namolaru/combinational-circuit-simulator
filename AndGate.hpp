#ifndef ANDGATE
#define ANDGATE

#include <vector>
#include <iostream>
#include "InputGate.hpp"
#include "Gate.hpp"
using namespace std;

class AndGate : public Gate{
private:
    /* data */
public:
    AndGate(Gate *p1, Gate *p2);
    virtual ~AndGate();
};





#endif
