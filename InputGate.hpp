#ifndef INPUTGATE
#define INPUTGATE
#include "Gate.hpp"
#include <vector>
#include <iostream>

using namespace std;
class InputGate : public Gate
{
private:
    bool *val; 
    char inputName;
public:
    InputGate(const char a);
    virtual ~InputGate();
    bool *getVal();
    void setVal(bool *val);
    int valeurInput(bool *val); // RENVOIE LA VALEUR EN BINAIRE 0 SI C'EST FALSE ET 1 SI C'EST TRUE
};








#endif
