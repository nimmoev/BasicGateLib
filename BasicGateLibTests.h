#include "BasicGateLib.h"
#include "BasicTestLib/BasicTestLib.h"

#ifndef BGL_TESTS_H
#define BGL_TESTS_H

// To add a new test, follow these instructions:
//  1. Declare a parameter-less type of void 
//  2. Append that function to BasicGateLibTestFunctionVector
//  3. Append a string of the same name as the function to BasicGateLibTestNameVector

void Node_Constr_IDShouldBeZero();
void Node_Deconstr_IDShouldBeOne();
void Gate_Constr_GateTypeShouldBeUNDEF();
void Gate_ConstrGateType_GateTypeShouldBeINV();
void Gate_ConstrInputsOutputs_InputIDShouldBeZero();
void Gate_ConstrInputsOutputs_InputsShouldBeEmpty();
void Gate_ConstrInputsOutputs_OutputIDShouldBeOne();
void Gate_ConstrInputsOutputs_OutputsShouldBeEmpty();
void Gate_GetGateType_GateTypeShouldBeAND();
void Gate_GetInputs_IDShouldBeThree();
void Gate_GetInputs_ShouldBeEmpty();
void Gate_GetOutputs_IDShouldBeFour();
void Gate_GetOutputs_ShouldBeEmpty();
void Wire_GetInputs_IDShouldBeZero();
void Wire_GetInputs_ShouldBeEmpty();
void Wire_GetOutputs_IDShouldBeOne();
void Wire_GetOutputs_ShouldBeEmpty();
void None_ConnectWireGate_ShouldSucceed();
void None_ConnectWireGate_ShouldBeErrorNone();
void None_ConnectWireGate_GateInputIDShouldBeZero();
void None_ConnectWireGate_GateOutputIDShouldBeOne();
void None_ConnectWireGate_WireInputIDShouldBeTwo();
void None_ConnectWireGate_WireOutputIDShouldBeThree();
void None_ConnectWireGate_ShouldFailWireNullptr();
void None_ConnectWireGate_ShouldBeErrorWireIsNull();
void None_ConnectWireGate_ShouldFailGateNullptr();
void None_ConnectWireGate_ShouldBeErrorGateIsNull();
void None_ConnectGateWire_ShouldSucceed();
void None_ConnectGateWire_ShouldBeErrorNone();
void None_ConnectGateWire_GateInputIDShouldBeZero();
void None_ConnectGateWire_GateOutputIDShouldBeOne();
void None_ConnectGateWire_WireInputIDShouldBeTwo();
void None_ConnectGateWire_WireOutputIDShouldBeThree();
void None_ConnectGateWire_ShouldFailWireNullptr();
void None_ConnectGateWire_ShouldBeErrorWireIsNull();
void None_ConnectGateWire_ShouldFailGateNullptr();
void None_ConnectGateWire_ShouldBeErrorGateIsNull();

std::vector<void (*)()> BasicGateLibTestFunctionVector = {
    Node_Constr_IDShouldBeZero,
    Node_Deconstr_IDShouldBeOne,
    Gate_Constr_GateTypeShouldBeUNDEF,
    Gate_ConstrGateType_GateTypeShouldBeINV,
    Gate_ConstrInputsOutputs_InputIDShouldBeZero,
    Gate_ConstrInputsOutputs_InputsShouldBeEmpty,
    Gate_ConstrInputsOutputs_OutputIDShouldBeOne,
    Gate_ConstrInputsOutputs_OutputsShouldBeEmpty,
    Gate_GetGateType_GateTypeShouldBeAND,
    Gate_GetInputs_IDShouldBeThree,
    Gate_GetInputs_ShouldBeEmpty,
    Gate_GetOutputs_IDShouldBeFour,
    Gate_GetOutputs_ShouldBeEmpty,
    Wire_GetInputs_IDShouldBeZero,
    Wire_GetInputs_ShouldBeEmpty,
    Wire_GetOutputs_IDShouldBeOne,
    Wire_GetOutputs_ShouldBeEmpty,
    None_ConnectWireGate_ShouldSucceed,
    None_ConnectWireGate_ShouldBeErrorNone,
    None_ConnectWireGate_GateInputIDShouldBeZero,
    None_ConnectWireGate_GateOutputIDShouldBeOne,
    None_ConnectWireGate_WireInputIDShouldBeTwo,
    None_ConnectWireGate_WireOutputIDShouldBeThree,
    None_ConnectWireGate_ShouldFailWireNullptr,
    None_ConnectWireGate_ShouldBeErrorWireIsNull,
    None_ConnectWireGate_ShouldFailGateNullptr,
    None_ConnectWireGate_ShouldBeErrorGateIsNull,
    None_ConnectGateWire_ShouldSucceed,
    None_ConnectGateWire_ShouldBeErrorNone,
    None_ConnectGateWire_GateInputIDShouldBeZero,
    None_ConnectGateWire_GateOutputIDShouldBeOne,
    None_ConnectGateWire_WireInputIDShouldBeTwo,
    None_ConnectGateWire_WireOutputIDShouldBeThree,
    None_ConnectGateWire_ShouldFailWireNullptr,
    None_ConnectGateWire_ShouldBeErrorWireIsNull,
    None_ConnectGateWire_ShouldFailGateNullptr,
    None_ConnectGateWire_ShouldBeErrorGateIsNull
};

std::vector<std::string> BasicGateLibTestNameVector = {
    "Node_Constr_IDShouldBeZero",
    "Node_Deconstr_IDShouldBeOne",
    "Gate_Constr_GateTypeShouldBeUNDEF",
    "Gate_ConstrGateType_GateTypeShouldBeINV",
    "Gate_ConstrInputsOutputs_InputIDShouldBeZero",
    "Gate_ConstrInputsOutputs_InputsShouldBeEmpty",
    "Gate_ConstrInputsOutputs_OutputIDShouldBeOne",
    "Gate_ConstrInputsOutputs_OutputsShouldBeEmpty",
    "Gate_GetGateType_GateTypeShouldBeAND",
    "Gate_GetInputs_IDShouldBeThree",
    "Gate_GetInputs_ShouldBeEmpty",
    "Gate_GetOutputs_IDShouldBeFour",
    "Gate_GetOutputs_ShouldBeEmpty",
    "Wire_GetInputs_IDShouldBeZero",
    "Wire_GetInputs_ShouldBeEmpty",
    "Wire_GetOutputs_IDShouldBeOne",
    "Wire_GetOutputs_ShouldBeEmpty",
    "None_ConnectWireGate_ShouldSucceed",
    "None_ConnectWireGate_ShouldBeErrorNone",
    "None_ConnectWireGate_GateInputIDShouldBeZero",
    "None_ConnectWireGate_GateOutputIDShouldBeOne",
    "None_ConnectWireGate_WireInputIDShouldBeTwo",
    "None_ConnectWireGate_WireOutputIDShouldBeThree",
    "None_ConnectWireGate_ShouldFailWireNullptr",
    "None_ConnectWireGate_ShouldBeErrorWireIsNull",
    "None_ConnectWireGate_ShouldFailGateNullptr",
    "None_ConnectWireGate_ShouldBeErrorGateIsNull",
    "None_ConnectGateWire_ShouldSucceed",
    "None_ConnectGateWire_ShouldBeErrorNone",
    "None_ConnectGateWire_GateInputIDShouldBeZero",
    "None_ConnectGateWire_GateOutputIDShouldBeOne",
    "None_ConnectGateWire_WireInputIDShouldBeTwo",
    "None_ConnectGateWire_WireOutputIDShouldBeThree",
    "None_ConnectGateWire_ShouldFailWireNullptr",
    "None_ConnectGateWire_ShouldBeErrorWireIsNull",
    "None_ConnectGateWire_ShouldFailGateNullptr",
    "None_ConnectGateWire_ShouldBeErrorGateIsNull"
};

#endif
