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
Gate *and4 = new AndGate(e,f);
Gate *and5 = new AndGate(a,b);

Gate *or_new = new OrGate(c,d);
Gate *and_new = new AndGate(c,d);
Gate *or5 = new OrGate(a,f);
Gate *or6 = new OrGate(d,f);

Gate *and2 = new XorGate(or1,and1);
Gate *and3 = new AndGate(or_new,and_new);
Gate *xor2 = new XorGate(or5,or6);

Gate *or3 = new OrGate(and2,and3);
Gate *or4 = new OrGate(and4,and5);
Gate *xor3 = new XorGate(xor2,or4);

Gate *and6 = new AndGate(or3,xor3);


OutputGate *A = new OutputGate('A');
OutputGate *B = new OutputGate('B');

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
gates->push_back(or3);
gates->push_back(and4);
gates->push_back(and5);
gates->push_back(or4);
gates->push_back(or5);
gates->push_back(or6);
gates->push_back(xor2);
gates->push_back(xor3);
gates->push_back(and6);

vector<OutputGate*>* ouputs = new vector<OutputGate*>;
ouputs->push_back(A);
ouputs->push_back(B);

Circuit* circuit = new Circuit(inputsCircuit, gates, ouputs);
circuit->afficheCircuit();
return 0;

}
