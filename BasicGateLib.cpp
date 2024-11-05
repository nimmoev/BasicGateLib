#include <iostream>
#include <vector>

#include "BasicGateLib.h"

int Node::numNodes = 0;

Node::Node() { 
    this->id = ++numNodes;
}

Node::~Node() { 
    numNodes--;
}

// Return a unique integer ID assigned to this object
int Node::GetID() { 
    return this->id;
}

Gate::Gate() { 
    this->gateType = UNDEF;
    this->inputs.clear();
    this->outputs.clear();
}

Gate::Gate(GateType gateType) {
    this->gateType = gateType;
    this->inputs.clear();
    this->outputs.clear();
}

Gate::Gate(GateType gateType, std::vector<Wire*> inputs, std::vector<Wire*> outputs) {
    this->gateType = gateType;
    for (int i = 0; i < inputs.size(); i++) {
        Connect(inputs.at(i), this);
    }
    for (int i = 0; i < outputs.size(); i++) { 
        Connect(this, outputs.at(i));
    }
}

// Return an integer representing the GateType of the Gate
GateType Gate::GetGateType() {
    return this->gateType;
} 

// Return a copy of all input Wires in the Gate
std::vector<Wire*> Gate::GetInputs() {
    return this->inputs;
}

// Return a copy of all output Wires in the Gate
std::vector<Wire*> Gate::GetOutputs() {
    return this->outputs;
}

// Debug function to print all members of the Gate
void Gate::Print() { 
    std::cout << "G" << this->id << " (GateType=" << this->gateType << "):" << std::endl;
    std::cout << "   Inputs: ";
    for (int i = 0; i < this->inputs.size(); i++) { 
        std::cout << "W" << inputs.at(i)->GetID();
        if (i < this->inputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout <<  "   Outputs: ";
    for (int i = 0; i < this->outputs.size(); i++) { 
        std::cout << "W" << outputs.at(i)->GetID();
        if (i < this->outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Append an input Wire to this Gate's input vector. Use Connect() to maintain integrity of the Wires and Gates. 
inline bool Gate::_ConnectInput(Wire* input) {
    // Will probably be done prior, but here for safety reasons
    if (input == nullptr) {
        return false;
    }
    this->inputs.push_back(input);
    return true;
}

// Append output Wire to this Gate's output vector. Use Connect() to maintain integrity of the Wires and Gates. 
inline bool Gate::_ConnectOutput(Wire* output) { 
    // Will probably be done prior, but here for safety reasons
    if (output == nullptr) { 
        return false;
    }
    this->outputs.push_back(output);
    return true;
}

Wire::Wire() {
    this->inputs.clear();
    this->outputs.clear();
}

// Return a copy of all input Gates of the Wire
std::vector<Gate*> Wire::GetInputs() {
    return this->inputs;
}

// Return a copy of all output Gates of the Wire
std::vector<Gate*> Wire::GetOutputs() {
    return this->outputs;
}

// Debug function to print all members of the Wire
void Wire::Print() { 
    std::cout << "W" << this->id << ":" << std::endl;
    std::cout << "   Inputs: ";
    for (int i = 0; i < this->inputs.size(); i++) { 
        std::cout << "G" << inputs.at(i)->GetID();
        if (i < this->inputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "   Outputs: ";
    for (int i = 0; i < this->outputs.size(); i++) { 
        std::cout << "G" << outputs.at(i)->GetID();
        if (i < this->outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Append an input Gate to this Wire's input vector. Use Connect() to maintain integrity of the Wire and Gate. 
inline bool Wire::_ConnectInput(Gate* input) {
    // Will probably be done prior, but here for safety reasons
    if (input == nullptr) { 
        return false;
    }
    this->inputs.push_back(input);
    return true;
}

// Append an output Gate to this Wire's output vector. Use Connect() to maintain integrity of the Wire and Gate. 
inline bool Wire::_ConnectOutput(Gate* output) { 
    // Will probably be done prior, but here for safety reasons
    if (output == nullptr) { 
        return false;
    }
    this->outputs.push_back(output);
    return true;
}

// Connect an input Wire and an output Gate
bool Connect(Wire* input, Gate* output, int* errorCode) { 
    int error = ERROR_NONE;
    bool res = true;

    if (res && input == nullptr) { 
        error = ERROR_WIRE_IS_NULL;
        res = false;
    }
    if (res && output == nullptr) {
        error = ERROR_GATE_IS_NULL;
        res = false;
    }
    if (res && !input->_ConnectOutput(output)) {
        error = ERROR_CONNECT_OUTPUT;
        res = false;
    }
    if (res && !output->_ConnectInput(input)) {
        error = ERROR_CONNECT_INPUT;
        res = false;
    }

    if (errorCode != nullptr) { 
        *errorCode = error;
    }
    return res;
}

// Connect an input Gate and an output Wire
bool Connect(Gate* input, Wire* output, int* errorCode) { 
    int error = ERROR_NONE;
    bool res = true;

    if (res && input == nullptr) { 
        error = ERROR_GATE_IS_NULL;
        res = false;
    }
    if (res && output == nullptr) {
        error = ERROR_WIRE_IS_NULL;
        res = false;
    }
    if (res && !input->_ConnectOutput(output)) {
        error = ERROR_CONNECT_OUTPUT;
        res = false;
    }
    if (res && !output->_ConnectInput(input)) {
        error = ERROR_CONNECT_INPUT;
        res = false;
    }

    if (errorCode != nullptr) { 
        *errorCode = error;
    }
    return res;
}