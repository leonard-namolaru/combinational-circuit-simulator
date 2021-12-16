CPP=g++ --std=c++11

CFLAGS= -Wall

all : mr

mr : main.o Gate.o AndGate.o InputGate.o OutputGate.o OrGate.o XorGate.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp 
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

clean :
	rm *.o
test:
	./mr

	