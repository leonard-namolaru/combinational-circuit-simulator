#ifndef NANDGATE
#define NANDGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"
using namespace std;

class NandGate : public Gate{

private:
    
public:
    NandGate(Gate *p1, Gate *p2);
    bool getValeurBooleenne() override;
    virtual ~NandGate();
};





#endif
