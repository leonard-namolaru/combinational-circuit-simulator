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
    bool getValeurBooleenne() override;
    virtual ~AndGate();
};





#endif
