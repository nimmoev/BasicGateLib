#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>

#include "BasicGateLib.h"

int Gate::numGates = 0;

Gate::Gate() { 
    this->id = numGates;
    numGates++;
    this->gateType = UNDEF;
}
Gate::Gate(GateType gateType) {
    this->id = numGates;
    numGates++;
    this->gateType = gateType;
}
Gate::Gate(GateType gateType, std::vector<Wire*> inputs, std::vector<Wire*> outputs) {
    this->id = numGates;
    numGates++;
    this->gateType = gateType;
    this->inputs = inputs;
    this->outputs = outputs;
}

int Gate::GetID() { 
    return this->id;
}
// Debug function to print all inputs and outputs on a Gate
void Gate::Print() { 
    std::cout << "G" << this->id << " Inputs: ";
    for (int i = 0; i < this->inputs.size(); i++) { 
        std::cout << "W" << inputs.at(i)->GetID();
        if (i < this->inputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "G" << this->id << " Outputs: ";
    for (int i = 0; i < this->outputs.size(); i++) { 
        std::cout << "W" << outputs.at(i)->GetID();
        if (i < this->outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Manual function to connect Gats to Wires. Do not use, use Connect() instead
inline bool Gate::_ConnectInput(Wire* input) {
    // This check will mostly be done outside this function, but it is here since 
    // the this function is technically accessible
    if (input == nullptr) {
        return false;
    }
    this->inputs.push_back(input);
    return true;
}
// Manual function to connect Gats to Wires. Do not use, use Connect() instead
inline bool Gate::_ConnectOutput(Wire* output) { 
    // This check will mostly be done outside this function, but it is here since 
    // the this function is technically accessible
    if (output == nullptr) { 
        return false;
    }
    this->outputs.push_back(output);
    return true;
}

int Wire::numWires = 0;

Wire::Wire() { 
    this->id = numWires;
    numWires++;
}

int Wire::GetID() { 
    return this->id;
}
void Wire::Print() { 
    std::cout << "W" << this->id << " Inputs: ";
    for (int i = 0; i < this->inputs.size(); i++) { 
        std::cout << "G" << inputs.at(i)->GetID();
        if (i < this->inputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    std::cout << "W" << this->id << " Outputs: ";
    for (int i = 0; i < this->outputs.size(); i++) { 
        std::cout << "G" << outputs.at(i)->GetID();
        if (i < this->outputs.size()-1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// Manual function to connect Gates to Wires. Do not use, use Connect() instead
inline bool Wire::_ConnectInput(Gate* input) {
    // This check will mostly be done outside this function, but it is here since 
    // the this function is technically accessible
    if (input == nullptr) { 
        return false;
    }
    this->inputs.push_back(input);
    return true;
}
// Manual function to connect Gates to Wires. Do not use, use Connect() instead
inline bool Wire::_ConnectOutput(Gate* output) { 
    // This check will mostly be done outside this function, but it is here since 
    // the this function is technically accessible
    if (output == nullptr) { 
        return false;
    }
    this->outputs.push_back(output);
    return true;
}

// Main function to connect Wires and Gates
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
// Main function to connect Wires and Gates
bool Connect(Gate* input, Wire* output, int* errorCode) { 
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