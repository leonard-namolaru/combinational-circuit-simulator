CPP=g++ --std=c++11

CFLAGS= -Wall

all : mr

mr : main.o Gate.o AndGate.o InputGate.o OutputGate.o OrGate.o XorGate.o Circuit.o CircuitException.o NandGate.o XnorGate.o NorGate.o Outils.o
	$(CPP) $(CFLAGS) -o $@ $^

Circuit.o : Circuit.cpp Circuit.hpp
	$(CPP) $(CFLAGS) -c $<

CircuitException.o : CircuitException.cpp CircuitException.hpp 
	$(CPP) $(CFLAGS) -c $<

main.o : main.cpp 
	$(CPP) $(CFLAGS) -c $<

Outils.o : Outils.cpp Outils.hpp
	$(CPP) $(CFLAGS) -c $<

Gate.o : Gate.cpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

AndGate.o : AndGate.cpp AndGate.hpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

InputGate.o : InputGate.cpp InputGate.hpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

OrGate.o : OrGate.cpp OrGate.hpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

OutputGate.o : OutputGate.cpp OutputGate.hpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

XorGate.o : XorGate.cpp XorGate.hpp Gate.hpp
	$(CPP) $(CFLAGS) -c $<

NandGate.o : NandGate.cpp NandGate.hpp
	$(CPP) $(CFLAGS) -c $<

NorGate.o : NorGate.cpp NorGate.hpp
	$(CPP) $(CFLAGS) -c $<

XnorGate.o : XnorGate.cpp XnorGate.hpp
	$(CPP) $(CFLAGS) -c $<	

clean :
	rm *.o
test:
	./mr

	