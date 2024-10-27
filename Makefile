output: BasicGateLib.o BasicGateLibTests.o
	g++ BasicGateLib.o BasicGateLibTests.o -o main

BasicGateLib.o: BasicGateLib.cpp
	g++ -c BasicGateLib.cpp

BasicGateLibTests.o: BasicGateLibTests.cpp
	g++ -c BasicGateLibTests.cpp

clean:
	rm *.o output