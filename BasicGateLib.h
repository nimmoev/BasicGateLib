#ifndef BGL_H
#define BGL_H

#include <iostream>
#include <vector>

enum GateType {GATETYPE_INV, GATETYPE_AND, GATETYPE_OR, GATETYPE_NAND, GATETYPE_NOR, GATETYPE_XOR, GATETYPE_XNOR, GATETYPE_UNDEF};

const int ERROR_NONE = 0x00;
const int ERROR_GENERIC = 0x01;
const int ERROR_NOT_IMPLEMENTED = 0x02;
const int ERROR_WIRE_IS_NULL = 0x03;
const int ERROR_GATE_IS_NULL = 0x04;
const int ERROR_CONNECT_INPUT = 0x05;
const int ERROR_CONNECT_OUTPUT = 0x06;

// Class prototypes
class Node;
class Gate;
class Wire;

/// @brief  A class which offers a unique ID for the Gate and Wire classes
class Node {
protected:
    int id;
    std::string name;
    static int numNodes;

public:
    Node();
    Node(std::string name);
    ~Node();
    int GetID();
    std::string GetName();
    virtual void PrintID();

};

/// @brief  A class which offers a GateType and a connection between series of Wires
class Gate : public Node { 
protected:
    GateType gateType;
    std::vector<Wire*> inputs;
    Wire* output;

public:
    Gate();
    Gate(std::string name);
    Gate(GateType gateType);
    Gate(GateType gateType, std::string name);
    Gate(GateType gateType, std::vector<Wire*> inputs, Wire* output);
    Gate(GateType gateType, std::vector<Wire*> inputs, Wire* output, std::string name);
    GateType GetGateType();
    std::vector<Wire*> GetInputs();
    Wire* GetOutput();
    void Print();

private:
    inline bool _ConnectInput(Wire* input);
    inline bool _ConnectOutput(Wire* output);
    friend int Connect(Wire* input, Gate* output);
    friend int Connect(Gate* input, Wire* output);

};

/// @brief  A class which offers a connection between series of Gates
class Wire: public Node {
protected:
    std::vector<Gate*> inputs;
    std::vector<Gate*> outputs;

public:
    Wire();
    Wire(std::string name);
    std::vector<Gate*> GetInputs();
    std::vector<Gate*> GetOutputs();
    void Print();

private:
    inline bool _ConnectInput(Gate* input);
    inline bool _ConnectOutput(Gate* output);
    friend int Connect(Wire* input, Gate* output);
    friend int Connect(Gate* input, Wire* output);

};

int Connect(Wire* input, Gate* output);
int Connect(Gate* input, Wire* output);

std::vector<int> GetIDList(std::vector<Node*> netList);
std::vector<int> GetIDList(std::vector<Gate*> gateList);
std::vector<int> GetIDList(std::vector<Wire*> wireList);
std::vector<std::string> GetNameList(std::vector<Node*> netList);
std::vector<std::string> GetNameList(std::vector<Gate*> gateList);
std::vector<std::string> GetNameList(std::vector<Wire*> wireList);
std::vector<Gate*> GetGateList(std::vector<Node*> netList);
std::vector<Wire*> GetWireList(std::vector<Node*> netList);
std::vector<Wire*> GetInputsList(std::vector<Node*> netList);
std::vector<Wire*> GetOutputsList(std::vector<Node*> netList);
void CleanupNetList(std::vector<Node*> netList);

#endif