output: BasicGateLib.o BasicTestLib.o BasicGateLibTests.o
	g++ BasicGateLib.o BasicTestLib.o BasicGateLibTests.o -o RunBasicGateLibTests.out

BasicGateLib.o: BasicGateLib.cpp
	g++ -c BasicGateLib.cpp

BasicTestLib.o: BasicTestLib/BasicTestLib.cpp
	g++ -c BasicTestLib/BasicTestLib.cpp

BasicGateLibTests.o: BasicGateLibTests.cpp
	g++ -c BasicGateLibTests.cpp

clean:
	rm *.o 