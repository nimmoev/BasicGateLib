#include "BasicGateLib.h"

int Node::numNodes = 0;

Node::Node() { 
    this->id = ++numNodes;
    this->name = "";
}

Node::Node(std::string name) { 
    this->id = ++numNodes;
    this->name = name;
}

Node::~Node() { 
    numNodes--;
}

// Return the unique integer ID assigned to this object
int Node::GetID() { 
    return this->id;
}

// Return the name assigned to this object
std::string Node::GetName() { 
    return this->name;
}

// Output NodeID
void Node::PrintID() { 
    std::cout << "N" << this->id;
}

Gate::Gate() { 
    this->gateType = GATETYPE_UNDEF;
    this->inputs.clear();
    this->output = nullptr;
}

Gate::Gate(std::string name) { 
    this->name = name;
    this->gateType = GATETYPE_UNDEF;
    this->inputs.clear();
    this->output = nullptr;
}

Gate::Gate(GateType gateType) {
    this->gateType = gateType;
    this->inputs.clear();
    this->output = nullptr;
}

Gate::Gate(GateType gateType, std::string name) { 
    this->name = name;
    this->gateType = gateType;
    this->inputs.clear();
    this->output = nullptr;
}

Gate::Gate(GateType gateType, std::vector<Wire*> inputs, Wire* output) {
    this->gateType = gateType;
    for (int i = 0; i < inputs.size(); i++) {
        Connect(inputs.at(i), this);
    }
    Connect(this, output);
}

Gate::Gate(GateType gateType, std::vector<Wire*> inputs, Wire* output, std::string name) {
    this->name = name;
    this->gateType = gateType;
    for (int i = 0; i < inputs.size(); i++) {
        Connect(inputs.at(i), this);
    }
    Connect(this, output);

}

// Return an enum representing the GateType of the Gate
GateType Gate::GetGateType() {
    return this->gateType;
} 

// Return a copy of all input Wires in the Gate
std::vector<Wire*> Gate::GetInputs() {
    return this->inputs;
}

// Return an address of the output Wire in the Gate
Wire* Gate::GetOutput() {
    return this->output;
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

    std::cout <<  "   Output: ";
    std::cout << "W" << output->GetID();
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

// Set this Gate's output to an input Wire. Use Connect() to maintain integrity of the Wires and Gates. 
inline bool Gate::_ConnectOutput(Wire* output) { 
    // Will probably be done prior, but here for safety reasons
    if (output == nullptr) { 
        return false;
    }
    this->output = output;
    return true;
}

Wire::Wire() {
    this->inputs.clear();
    this->outputs.clear();
}

Wire::Wire(std::string name) {
    this->name = name;
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
int Connect(Wire* input, Gate* output) { 
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
    return error;
}

// Connect an input Gate and an output Wire
int Connect(Gate* input, Wire* output) { 
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
    return error;
}

// Return a copy of all IDs in a NetList
std::vector<int> GetIDList(std::vector<Node*> netList) {
    std::vector<int> resultIDList;
    if (netList.empty()) {
        return resultIDList;
    }
    for (int i = 0; i < netList.size(); i++) { 
        resultIDList.push_back(netList.at(i)->GetID());
    }
    return resultIDList;
}

// Return a copy of all IDs in a GateList
std::vector<int> GetIDList(std::vector<Gate*> gateList) {
    std::vector<int> resultIDList;
    if (gateList.empty()) {
        return resultIDList;
    }
    for (int i = 0; i < gateList.size(); i++) { 
        resultIDList.push_back(gateList.at(i)->GetID());
    }
    return resultIDList;
}

// Return a copy of all IDs in a WireList
std::vector<int> GetIDList(std::vector<Wire*> wireList) {
    std::vector<int> resultIDList;
    if (wireList.empty()) {
        return resultIDList;
    }
    for (int i = 0; i < wireList.size(); i++) { 
        resultIDList.push_back(wireList.at(i)->GetID());
    }
    return resultIDList;
}

// Return a copy of all Names in a NetList
std::vector<std::string> GetNameList(std::vector<Node*> netList) {
    std::vector<std::string> resultNameList;
    if (netList.empty()) {
        return resultNameList;
    }
    for (int i = 0; i < netList.size(); i++) { 
        resultNameList.push_back(netList.at(i)->GetName());
    }
    return resultNameList;
}

// Return a copy of all Names in a GateList
std::vector<std::string> GetNameList(std::vector<Gate*> gateList) {
    std::vector<std::string> resultNameList;
    if (gateList.empty()) {
        return resultNameList;
    }
    for (int i = 0; i < gateList.size(); i++) { 
        resultNameList.push_back(gateList.at(i)->GetName());
    }
    return resultNameList;
}

// Return a copy of all Names in a WireList
std::vector<std::string> GetNameList(std::vector<Wire*> wireList) {
    std::vector<std::string> resultNameList;
    if (wireList.empty()) {
        return resultNameList;
    }
    for (int i = 0; i < wireList.size(); i++) { 
        resultNameList.push_back(wireList.at(i)->GetName());
    }
    return resultNameList;
}

// Return a copy of all Gates in a NetList
std::vector<Gate*> GetGateList(std::vector<Node*> netList) {
    std::vector<Gate*> resultGateList;
    Gate* gate = nullptr;
    if (netList.empty()) {
        return resultGateList;
    }
    for (int i = 0; i < netList.size(); i++) { 
        gate = dynamic_cast<Gate*>(netList.at(i));
        if (gate != nullptr) {
            resultGateList.push_back(gate);
        }
    }
    return resultGateList;
}

// Return a copy of all Wires in a NetList
std::vector<Wire*> GetWireList(std::vector<Node*> netList) {
    std::vector<Wire*> resultWireList;
    Wire* wire = nullptr;
    if (netList.empty()) {
        return resultWireList;
    }
    for (int i = 0; i < netList.size(); i++) { 
        wire = dynamic_cast<Wire*>(netList.at(i));
        if (wire != nullptr) {
            resultWireList.push_back(wire);
        }
    }
    return resultWireList;
}

// Return a copy of all input Wires in a NetList
std::vector<Wire*> GetInputsList(std::vector<Node*> netList) {
    std::vector<Wire*> resultWireList;
    std::vector<Wire*> wireList = GetWireList(netList);
    if (wireList.empty()) {
        return resultWireList;
    }
    for (int i = 0; i < wireList.size(); i++) { 
        if (wireList.at(i)->GetInputs().empty() && !wireList.at(i)->GetOutputs().empty()) {
            resultWireList.push_back(wireList.at(i));
        }
    }
    return resultWireList;
}

// Return a copy of all output Wires in a NetList
std::vector<Wire*> GetOutputsList(std::vector<Node*> netList) {
    std::vector<Wire*> resultWireList;
    std::vector<Wire*> wireList = GetWireList(netList);
    if (wireList.empty()) {
        return resultWireList;
    }
    for (int i = 0; i < wireList.size(); i++) { 
        if (!wireList.at(i)->GetInputs().empty() && wireList.at(i)->GetOutputs().empty()) {
            resultWireList.push_back(wireList.at(i));
        }
    }
    return resultWireList;
}

// Delete all Gates and Wires in a NetList
void CleanupNetList(std::vector<Node*> netList) {
    std::vector<Gate*> gateList;
    std::vector<Wire*> wireList;
    if (netList.empty()) { 
        return;
    }

    gateList = GetGateList(netList);
    wireList = GetWireList(netList);
    for (Gate* gate : gateList) { 
        delete gate;
    }
    for (Wire* wire : wireList) {
        delete wire;
    }
    return;
}