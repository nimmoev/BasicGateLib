#include "BasicGateLibTests.h"

// Test basic level inverter gate
void test1() {
    // Declare Wires and Gates
    Wire in0, out0;
    Gate g0(AND);

    // Connect Wires and Gates
    Connect(&in0, &g0);
    Connect(&g0, &out0);

    in0.Print();
    g0.Print();
    out0.Print();
}

int main() { 
    test1();
    return 0;
}