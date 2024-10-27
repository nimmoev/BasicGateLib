#include <vector>

#ifndef BGL_H
#define BGL_H
enum GateType {INV, AND, OR, NAND, NOR, XOR, XNOR, UNDEF};

const int ERROR_NONE = 0;
const int ERROR_GENERIC = 1;
const int ERROR_NOT_IMPLEMENTED = 2;
const int ERROR_WIRE_IS_NULL = 3;
const int ERROR_GATE_IS_NULL = 4;
const int ERROR_CONNECT_INPUT = 5;
const int ERROR_CONNECT_OUTPUT = 6;

// Class prototypes
class Gate;
class Wire;

class Gate { 
private:
    int id;
    GateType gateType;
    std::vector<Wire*> inputs;
    std::vector<Wire*> outputs;
public:
    static int numGates;
    Gate();
    Gate(GateType gateType);
    Gate(GateType gateType, std::vector<Wire*> inputs, std::vector<Wire*> outputs);
    
    int GetID();
    void Print();

    // Manual functions to connect gates to wires. Do not use, use Connect() instead
    inline bool _ConnectInput(Wire* input);
    inline bool _ConnectOutput(Wire* output);
};


// Wire class has two goals: to be either:
// 1. Connect gates
// 2. Be an input or an output 
class Wire {
private:
    int id;
    std::vector<Gate*> inputs;
    std::vector<Gate*> outputs;
public:
    static int numWires;
    Wire();

    int GetID();
    void Print();

    // Manual functions to connect gates to wires. Do not use, use Connect() instead
    inline bool _ConnectInput(Gate* input);
    inline bool _ConnectOutput(Gate* output);
};

// Main functions to connect Wires and Gates
bool Connect(Wire* input, Gate* output, int* errorCode = nullptr);
bool Connect(Gate* input, Wire* output, int* errorCode = nullptr);

#endif