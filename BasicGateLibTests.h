#include "BasicGateLib.h"
#include "BasicTestLib/BasicTestLib.h"

#ifndef BGL_TESTS_H
#define BGL_TESTS_H

// To add a new test, follow these instructions:
//  1. Declare a parameter-less type of void 
//  2. Append that function to BasicGateLibTestFunctionVector
//  3. Append a string of the same name as the function to BasicGateLibTestNameVector

void Gate_Constr_GateTypeShouldBeUNDEF();
void Gate_ConstrGateType_GateTypeShouldBeINV();
void Gate_ConstrInputsOutputs_InputIDShouldMatch();
void Gate_ConstrInputsOutputs_InputsShouldBeEmpty();
void Gate_ConstrInputsOutputs_OutputIDShouldMatch();
void Gate_ConstrInputsOutputs_OutputsShouldBeEmpty();
void Gate_GetGateType_GateTypeShouldBeAND();
void Gate_GetInputs_IDShouldMatch();
void Gate_GetInputs_ShouldBeEmpty();
void Gate_GetOutputs_IDShouldMatch();
void Gate_GetOutputs_ShouldBeEmpty();
void Wire_GetInputs_IDShouldMatch();
void Wire_GetInputs_ShouldBeEmpty();
void Wire_GetOutputs_IDShouldMatch();
void Wire_GetOutputs_ShouldBeEmpty();
void None_ConnectWireGate_ShouldSucceed();
void None_ConnectWireGate_ShouldBeErrorNone();
void None_ConnectWireGate_GateInputIDShouldMatch();
void None_ConnectWireGate_GateOutputIDShouldMatch();
void None_ConnectWireGate_WireInputIDShouldMatch();
void None_ConnectWireGate_WireOutputIDShouldMatch();
void None_ConnectWireGate_ShouldFailWireNullptr();
void None_ConnectWireGate_ShouldBeErrorWireIsNull();
void None_ConnectWireGate_ShouldFailGateNullptr();
void None_ConnectWireGate_ShouldBeErrorGateIsNull();
void None_ConnectGateWire_ShouldSucceed();
void None_ConnectGateWire_ShouldBeErrorNone();
void None_ConnectGateWire_GateInputIDShouldMatch();
void None_ConnectGateWire_GateOutputIDShouldMatch();
void None_ConnectGateWire_WireInputIDShouldMatch();
void None_ConnectGateWire_WireOutputIDShouldMatch();
void None_ConnectGateWire_ShouldFailWireNullptr();
void None_ConnectGateWire_ShouldBeErrorWireIsNull();
void None_ConnectGateWire_ShouldFailGateNullptr();
void None_ConnectGateWire_ShouldBeErrorGateIsNull();

std::vector<void (*)()> BasicGateLibTestFunctionVector = {
    Gate_Constr_GateTypeShouldBeUNDEF,
    Gate_ConstrGateType_GateTypeShouldBeINV,
    Gate_ConstrInputsOutputs_InputIDShouldMatch,
    Gate_ConstrInputsOutputs_InputsShouldBeEmpty,
    Gate_ConstrInputsOutputs_OutputIDShouldMatch,
    Gate_ConstrInputsOutputs_OutputsShouldBeEmpty,
    Gate_GetGateType_GateTypeShouldBeAND,
    Gate_GetInputs_IDShouldMatch,
    Gate_GetInputs_ShouldBeEmpty,
    Gate_GetOutputs_IDShouldMatch,
    Gate_GetOutputs_ShouldBeEmpty,
    Wire_GetInputs_IDShouldMatch,
    Wire_GetInputs_ShouldBeEmpty,
    Wire_GetOutputs_IDShouldMatch,
    Wire_GetOutputs_ShouldBeEmpty,
    None_ConnectWireGate_ShouldSucceed,
    None_ConnectWireGate_ShouldBeErrorNone,
    None_ConnectWireGate_GateInputIDShouldMatch,
    None_ConnectWireGate_GateOutputIDShouldMatch,
    None_ConnectWireGate_WireInputIDShouldMatch,
    None_ConnectWireGate_WireOutputIDShouldMatch,
    None_ConnectWireGate_ShouldFailWireNullptr,
    None_ConnectWireGate_ShouldBeErrorWireIsNull,
    None_ConnectWireGate_ShouldFailGateNullptr,
    None_ConnectWireGate_ShouldBeErrorGateIsNull,
    None_ConnectGateWire_ShouldSucceed,
    None_ConnectGateWire_ShouldBeErrorNone,
    None_ConnectGateWire_GateInputIDShouldMatch,
    None_ConnectGateWire_GateOutputIDShouldMatch,
    None_ConnectGateWire_WireInputIDShouldMatch,
    None_ConnectGateWire_WireOutputIDShouldMatch,
    None_ConnectGateWire_ShouldFailWireNullptr,
    None_ConnectGateWire_ShouldBeErrorWireIsNull,
    None_ConnectGateWire_ShouldFailGateNullptr,
    None_ConnectGateWire_ShouldBeErrorGateIsNull
};

std::vector<std::string> BasicGateLibTestNameVector = {
    "Gate_Constr_GateTypeShouldBeUNDEF",
    "Gate_ConstrGateType_GateTypeShouldBeINV",
    "Gate_ConstrInputsOutputs_InputIDShouldMatch",
    "Gate_ConstrInputsOutputs_InputsShouldBeEmpty",
    "Gate_ConstrInputsOutputs_OutputIDShouldMatch",
    "Gate_ConstrInputsOutputs_OutputsShouldBeEmpty",
    "Gate_GetGateType_GateTypeShouldBeAND",
    "Gate_GetInputs_IDShouldMatch",
    "Gate_GetInputs_ShouldBeEmpty",
    "Gate_GetOutputs_IDShouldMatch",
    "Gate_GetOutputs_ShouldBeEmpty",
    "Wire_GetInputs_IDShouldMatch",
    "Wire_GetInputs_ShouldBeEmpty",
    "Wire_GetOutputs_IDShouldMatch",
    "Wire_GetOutputs_ShouldBeEmpty",
    "None_ConnectWireGate_ShouldSucceed",
    "None_ConnectWireGate_ShouldBeErrorNone",
    "None_ConnectWireGate_GateInputIDShouldMatch",
    "None_ConnectWireGate_GateOutputIDShouldMatch",
    "None_ConnectWireGate_WireInputIDShouldMatch",
    "None_ConnectWireGate_WireOutputIDShouldMatch",
    "None_ConnectWireGate_ShouldFailWireNullptr",
    "None_ConnectWireGate_ShouldBeErrorWireIsNull",
    "None_ConnectWireGate_ShouldFailGateNullptr",
    "None_ConnectWireGate_ShouldBeErrorGateIsNull",
    "None_ConnectGateWire_ShouldSucceed",
    "None_ConnectGateWire_ShouldBeErrorNone",
    "None_ConnectGateWire_GateInputIDShouldMatch",
    "None_ConnectGateWire_GateOutputIDShouldMatch",
    "None_ConnectGateWire_WireInputIDShouldMatch",
    "None_ConnectGateWire_WireOutputIDShouldMatch",
    "None_ConnectGateWire_ShouldFailWireNullptr",
    "None_ConnectGateWire_ShouldBeErrorWireIsNull",
    "None_ConnectGateWire_ShouldFailGateNullptr",
    "None_ConnectGateWire_ShouldBeErrorGateIsNull"
};

#endif
