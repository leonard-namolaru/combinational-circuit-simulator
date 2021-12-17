#ifndef GATE
#define GATE

#include <vector>
#include <iostream>
class InputGate;
class OutputGate;

using namespace std;

class Gate
{
protected:
   vector<Gate*>* entrees;
   OutputGate *sortie;
public:
    Gate();
    virtual ~Gate();
    virtual Gate* operationLogique();
    vector<Gate*>* getEntrees() const;
};


#endif
