#ifndef NEGATEGATE
#define NEGATEGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"
using namespace std;

class NegateGate : public Gate{

private:
    
public:
    NegateGate(Gate *p1);
    bool getValeurBooleenne() override;
    virtual ~NegateGate();
};





#endif
