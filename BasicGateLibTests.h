#ifndef BGL_TESTS_H
#define BGL_TESTS_H

#include <iostream>

#include "BasicGateLib.h"
#include "BasicTestLib/BasicTestLib.h"

// To add a new test, follow these instructions:
//  1. Declare a parameter-less function of type void in header file
//  2. Define a parameter-less function of type void in source file
//  3. Append the test function to BasicGateLibTestFunctionVector in source file
//  4. Append a string of the same name as the test function to BasicGateLibTestNameVector in source file

extern std::vector<void (*)()> BasicGateLibTestFunctionVector;
extern std::vector<std::string> BasicGateLibTestNameVector;
extern UnitTestList BGL_UTL;

void Gate_Constr_GateTypeShouldBeUNDEF();
void Gate_ConstrGateType_GateTypeShouldBeINV();
void Gate_ConstrInputsOutputs_InputShouldMatch();
void Gate_ConstrInputsOutputs_InputsShouldBeEmpty();
void Gate_ConstrInputsOutputs_OutputShouldMatch();
void Gate_GetGateType_GateTypeShouldBeAND();
void Gate_GetInputs_ShouldMatch();
void Gate_GetInputs_ShouldBeEmpty();
void Gate_GetOutputs_ShouldMatch();
void Wire_GetInputs_ShouldMatch();
void Wire_GetInputs_ShouldBeEmpty();
void Wire_GetOutputs_ShouldMatch();
void Wire_GetOutputs_ShouldBeEmpty();
void None_ConnectWireGate_ShouldSucceed();
void None_ConnectWireGate_ShouldBeErrorNone();
void None_ConnectWireGate_GateInputShouldMatch();
void None_ConnectWireGate_GateOutputShouldMatch();
void None_ConnectWireGate_WireInputShouldMatch();
void None_ConnectWireGate_WireOutputShouldMatch();
void None_ConnectWireGate_ShouldFailWireNullptr();
void None_ConnectWireGate_ShouldBeErrorWireIsNull();
void None_ConnectWireGate_ShouldFailGateNullptr();
void None_ConnectWireGate_ShouldBeErrorGateIsNull();
void None_ConnectGateWire_ShouldSucceed();
void None_ConnectGateWire_ShouldBeErrorNone();
void None_ConnectGateWire_GateInputShouldMatch();
void None_ConnectGateWire_GateOutputShouldMatch();
void None_ConnectGateWire_WireInputShouldMatch();
void None_ConnectGateWire_WireOutputShouldMatch();
void None_ConnectGateWire_ShouldFailWireNullptr();
void None_ConnectGateWire_ShouldBeErrorWireIsNull();
void None_ConnectGateWire_ShouldFailGateNullptr();
void None_ConnectGateWire_ShouldBeErrorGateIsNull();
void None_GetIDListNodes_ShouldMatch();
void None_GetIDListGates_ShouldMatch();
void None_GetIDListWires_ShouldMatch();
void None_GetGateList_ShouldMatch();
void None_GetWireList_ShouldMatch();
void None_GetInputsList_ShouldMatch();
void None_GetOutputsList_ShouldMatch(); 

#endif
