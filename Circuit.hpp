#ifndef CIRCUIT
#define CIRCUIT
#include "Gate.hpp"
#include <vector>
#include <iostream>

using namespace std;
class Circuit
{
private:
    /* data */
	vector<InputGate*>* inputs;
	vector<OutputGate*>* ouputs;
	vector<Gate*>* gates;
public:
    Circuit(/* args */);
    ~Circuit();
};

Circuit::Circuit(/* args */)
{
}

Circuit::~Circuit()
{
}








#endif
