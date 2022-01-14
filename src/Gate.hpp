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
   bool valeurBooleenne; // valeur booléenne
public:
    Gate(const string name);
    Gate(const string name, bool valeurBooleenne);
    virtual ~Gate();
    vector<Gate*>* getEntrees() const;
    string getName() const;
    virtual bool getValeurBooleenne();
};


#endif
