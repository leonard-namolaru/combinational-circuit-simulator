#include "InputGate.hpp"


InputGate::InputGate(char n) : Gate{std::string(1,n), false } {

}



InputGate::~InputGate()
{
}


bool InputGate::getValeurBooleenne() {
	return valeurBooleenne;
}

void InputGate::setValeurBooleenne(bool valeurBool){
	valeurBooleenne = valeurBool;
}

