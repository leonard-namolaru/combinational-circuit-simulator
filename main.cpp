#include "Gate.hpp"
#include "InputGate.hpp"
#include "OutputGate.hpp"
#include "OrGate.hpp"
#include "AndGate.hpp"
#include "XorGate.hpp"





int main(){

std::cout<<"hello world "<< endl;
InputGate *a = new InputGate('a');
InputGate *b = new InputGate('b');
Gate *or1 = new OrGate(a,b);
Gate *and1 = new AndGate(a,b); 
Gate *and2 = new XorGate(or1,and1);
OutputGate *A = new OutputGate(and2);

return 0;

}
