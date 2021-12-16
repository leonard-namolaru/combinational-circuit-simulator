#ifndef CIRCUIT
#define CIRCUIT
#include "Gate.hpp"
#include <vector>
#include <iostream>
#include "InputGate.hpp"
#include "OutputGate.hpp"
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
    void afficheCircuit() const;
};

Circuit::Circuit(/* args */)
{
}

Circuit::~Circuit()
{
}










#endif
