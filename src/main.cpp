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
InputGate *d = new InputGate('d');
InputGate *e = new InputGate('e');
InputGate *f = new InputGate('f');

Gate *or1 = new OrGate(a,b);
Gate *and1 = new AndGate(a,b); 

Gate *or_new = new OrGate(c,d);
Gate *and_new = new AndGate(c,d);


Gate *and2 = new XorGate(or1,and1);
Gate *and3 = new AndGate(or_new,and_new);
OutputGate *A = new OutputGate(and2);

*A=nullptr;

vector<InputGate*>* inputsCircuit = new vector<InputGate*>;
inputsCircuit->push_back(a);
inputsCircuit->push_back(b);
inputsCircuit->push_back(c);
inputsCircuit->push_back(d);
inputsCircuit->push_back(e);
inputsCircuit->push_back(f);


vector<Gate*>* gates = new vector<Gate*>;
gates->push_back(or1);
gates->push_back(and1);
gates->push_back(and2);
gates->push_back(or_new);
gates->push_back(and_new);
gates->push_back(and3);

Circuit* circuit = new Circuit(inputsCircuit, gates);
circuit->afficheCircuit();
return 0;

}
