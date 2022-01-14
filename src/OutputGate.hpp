#ifndef OUTPUTGATE
#define OUTPUTGATE

#include <vector>
#include <iostream>
#include "Gate.hpp"

using namespace std;

class OutputGate : public Gate
{
private:
    /* data */
public:
    OutputGate(char name, Gate* g);
    bool getValeurBooleenne() override;
    virtual ~OutputGate();
};







#endif
