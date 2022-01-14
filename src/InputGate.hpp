#ifndef INPUTGATE
#define INPUTGATE
#include "Gate.hpp"
#include <vector>
#include <iostream>

using namespace std;

class InputGate : public Gate{
public:
    InputGate(char a);
    bool getValeurBooleenne() override;
    void setValeurBooleenne(bool valeurBool);
    virtual ~InputGate();
};



#endif
