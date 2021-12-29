#include "Gate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "XorGate.hpp"
#include "Circuit.hpp"

int main(){

InputGate *a = new InputGate('a');
InputGate *b = new InputGate('b');
InputGate *c = new InputGate('c');


Gate *or1 = new OrGate(a,b);
Gate *and1 = new AndGate(a,b); 

Gate *and2 = new XorGate(or1,and1);
OutputGate *A = new OutputGate(and2);

*A=nullptr;

vector<InputGate*>* inputsCircuit = new vector<InputGate*>;
inputsCircuit->push_back(a);
inputsCircuit->push_back(b);
inputsCircuit->push_back(c);


vector<Gate*>* gates = new vector<Gate*>;
gates->push_back(or1);
gates->push_back(and1);
gates->push_back(and2);

Circuit* circuit = new Circuit(inputsCircuit, gates);
circuit->afficheCircuit();
return 0;

}
