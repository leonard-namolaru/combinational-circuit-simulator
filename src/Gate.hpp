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
   string name;
   vector<Gate*>* entrees;
public:
    Gate(const string name);
    virtual ~Gate();
    virtual Gate* operationLogique();
    vector<Gate*>* getEntrees() const;
    string getName() const;
};


#endif
