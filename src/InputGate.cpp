#include "InputGate.hpp"


InputGate::InputGate(char n) : inputName{n} , val{false} , Gate{std::string(1,n) } {

}



InputGate::~InputGate()
{
}

char InputGate::getInputName() const {
	return inputName;
}

// RENVOIE LA VALEUR EN BINAIRE 0 SI C'EST FALSE ET 1 SI C'EST TRUE
int InputGate::getValEnBinaire() const{
	return (int) val;
}
