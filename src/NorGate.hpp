#ifndef NORGATE
#define NORGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class NorGate : public Gate
{
private:

public:
    NorGate(Gate *g1, Gate *g2);
    bool getValeurBooleenne() override;
    virtual ~NorGate();
};







#endif
