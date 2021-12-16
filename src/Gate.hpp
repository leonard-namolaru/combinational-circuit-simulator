#ifndef GATE
#define GATE

#include <vector>
#include <iostream>
#include "InputGate.hpp"
#include "OutputGate.hpp"

using namespace std;

class Gate
{
private:
   vector<InputGate*> *entrees;
   OutputGate *sortie;
public:
    Gate();
    virtual ~Gate();
    virtual Gate* operationLogique();
};


#endif
