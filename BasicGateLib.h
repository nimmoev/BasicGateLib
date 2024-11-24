#ifndef BGL_H
#define BGL_H

#include <iostream>
#include <vector>

enum GateType {INV, AND, OR, NAND, NOR, XOR, XNOR, UNDEF};

const int ERROR_NONE = 0;
const int ERROR_GENERIC = 1;
const int ERROR_NOT_IMPLEMENTED = 2;
const int ERROR_WIRE_IS_NULL = 3;
const int ERROR_GATE_IS_NULL = 4;
const int ERROR_CONNECT_INPUT = 5;
const int ERROR_CONNECT_OUTPUT = 6;

// Class prototypes
class Node;
class Gate;
class Wire;

/// @brief  A class which offers a unique ID for the Gate and Wire classes
class Node {
protected:
    int id;
    static int numNodes;

public:
    Node();
    ~Node();
    int GetID();

};

/// @brief  A class which offers a GateType and a connection between series of Wires
class Gate : public Node { 
private:
    GateType gateType;
    std::vector<Wire*> inputs;
    Wire* output;

public:
    Gate();
    Gate(GateType gateType);
    Gate(GateType gateType, std::vector<Wire*> inputs, Wire* output);
    GateType GetGateType();
    std::vector<Wire*> GetInputs();
    Wire* GetOutput();
    void Print();

private:
    inline bool _ConnectInput(Wire* input);
    inline bool _ConnectOutput(Wire* output);
    friend bool Connect(Wire* input, Gate* output, int* errorCode);
    friend bool Connect(Gate* input, Wire* output, int* errorCode);

};

/// @brief  A class which offers a connection between series of Gates
class Wire: public Node {
private:
    std::vector<Gate*> inputs;
    std::vector<Gate*> outputs;

public:
    Wire();
    std::vector<Gate*> GetInputs();
    std::vector<Gate*> GetOutputs();
    void Print();

private:
    inline bool _ConnectInput(Gate* input);
    inline bool _ConnectOutput(Gate* output);
    friend bool Connect(Wire* input, Gate* output, int* errorCode);
    friend bool Connect(Gate* input, Wire* output, int* errorCode);

};

bool Connect(Wire* input, Gate* output, int* errorCode = nullptr);
bool Connect(Gate* input, Wire* output, int* errorCode = nullptr);

#endif