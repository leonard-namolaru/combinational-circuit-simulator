#ifndef XORGATE
#define XORGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class XnorGate : public Gate
{
private:
    
public:
    XnorGate(Gate *g1, Gate *g2);
    bool getValeurBooleenne() override;
    virtual ~XnorGate();
};







#endif
