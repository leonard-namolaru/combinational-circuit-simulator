#ifndef GATE
#define GATE

#include <vector>
#include <iostream>
class InputGate;
class OutputGate;

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
