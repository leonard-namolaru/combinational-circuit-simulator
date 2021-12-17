#include "Gate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "XorGate.hpp"
#include "Circuit.hpp"

int main(){

std::cout<<"hello world "<< endl;

InputGate *a = new InputGate('a');
InputGate *b = new InputGate('b');

Gate *or1 = new OrGate(a,b);
Gate *and1 = new AndGate(a,b); 

Gate *and2 = new XorGate(or1,and1);
OutputGate *A = new OutputGate(and2);

*A=nullptr;

vector<InputGate*>* inputsCircuit = new vector<InputGate*>;
inputsCircuit->push_back(a);

Circuit* circuit = new Circuit(inputsCircuit);
circuit->afficheCircuit();
return 0;

}
