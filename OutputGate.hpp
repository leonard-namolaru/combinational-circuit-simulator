#ifndef OUTPUTGATE
#define OUTPUTGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class OutputGate : public Gate
{
private:
    /* data */
public:
    OutputGate(Gate *g);
    virtual ~OutputGate();
};







#endif
