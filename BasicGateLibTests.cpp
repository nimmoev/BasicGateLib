#include "BasicGateLibTests.h"

std::vector<void (*)()> BasicGateLibTestFunctionVector = {
    Node_Constr_ShouldMatch,
    Node_ConstrName_NameShouldMatch,
    Gate_Constr_GateTypeShouldBeUNDEF,
    Gate_ConstrName_NameShouldMatch,
    Gate_ConstrGateType_GateTypeShouldBeINV,
    Gate_ConstrGateTypeName_NameShouldMatch,
    Gate_ConstrInputsOutputs_InputShouldMatch,
    Gate_ConstrInputsOutputs_InputsShouldBeEmpty,
    Gate_ConstrInputsOutputs_OutputShouldMatch,
    Gate_ConstrInputsOutputsName_NameShouldMatch,
    Gate_GetGateType_GateTypeShouldBeAND,
    Gate_GetInputs_ShouldMatch,
    Gate_GetInputs_ShouldBeEmpty,
    Gate_GetOutputs_ShouldMatch,
    Wire_ConstrName_NameShouldMatch,
    Wire_GetInputs_ShouldMatch,
    Wire_GetInputs_ShouldBeEmpty,
    Wire_GetOutputs_ShouldMatch,
    Wire_GetOutputs_ShouldBeEmpty,
    None_ConnectWireGate_ShouldSucceed,
    None_ConnectWireGate_ShouldBeErrorNone,
    None_ConnectWireGate_GateInputShouldMatch,
    None_ConnectWireGate_GateOutputShouldMatch,
    None_ConnectWireGate_WireInputShouldMatch,
    None_ConnectWireGate_WireOutputShouldMatch,
    None_ConnectWireGate_ShouldFailWireNullptr,
    None_ConnectWireGate_ShouldBeErrorWireIsNull,
    None_ConnectWireGate_ShouldFailGateNullptr,
    None_ConnectWireGate_ShouldBeErrorGateIsNull,
    None_ConnectGateWire_ShouldSucceed,
    None_ConnectGateWire_ShouldBeErrorNone,
    None_ConnectGateWire_GateInputShouldMatch,
    None_ConnectGateWire_GateOutputShouldMatch,
    None_ConnectGateWire_WireInputShouldMatch,
    None_ConnectGateWire_WireOutputShouldMatch,
    None_ConnectGateWire_ShouldFailWireNullptr,
    None_ConnectGateWire_ShouldBeErrorWireIsNull,
    None_ConnectGateWire_ShouldFailGateNullptr,
    None_ConnectGateWire_ShouldBeErrorGateIsNull,
    None_GetIDListNodes_ShouldMatch,
    None_GetIDListGates_ShouldMatch,
    None_GetIDListWires_ShouldMatch,
    None_GetNameListNodes_NameShouldMatch,
    None_GetNameListGates_NameShouldMatch,
    None_GetNameListWires_NameShouldMatch,
    None_GetGateList_ShouldMatch,
    None_GetWireList_ShouldMatch,
    None_GetInputsList_ShouldMatch,
    None_GetOutputsList_ShouldMatch
};

std::vector<std::string> BasicGateLibTestNameVector = {
    "Node_Constr_ShouldMatch",
    "Node_ConstrName_NameShouldMatch",
    "Gate_Constr_GateTypeShouldBeUNDEF",
    "Gate_ConstrName_NameShouldMatch",
    "Gate_ConstrGateType_GateTypeShouldBeINV",
    "Gate_ConstrGateTypeName_NameShouldMatch",
    "Gate_ConstrInputsOutputs_InputShouldMatch",
    "Gate_ConstrInputsOutputs_InputsShouldBeEmpty",
    "Gate_ConstrInputsOutputs_OutputShouldMatch",
    "Gate_ConstrInputsOutputsName_NameShouldMatch",
    "Gate_GetGateType_GateTypeShouldBeAND",
    "Gate_GetInputs_ShouldMatch",
    "Gate_GetInputs_ShouldBeEmpty",
    "Gate_GetOutputs_ShouldMatch",
    "Wire_ConstrName_NameShouldMatch",
    "Wire_GetInputs_ShouldMatch",
    "Wire_GetInputs_ShouldBeEmpty",
    "Wire_GetOutputs_ShouldMatch",
    "Wire_GetOutputs_ShouldBeEmpty",
    "None_ConnectWireGate_ShouldSucceed",
    "None_ConnectWireGate_ShouldBeErrorNone",
    "None_ConnectWireGate_GateInputShouldMatch",
    "None_ConnectWireGate_GateOutputShouldMatch",
    "None_ConnectWireGate_WireInputShouldMatch",
    "None_ConnectWireGate_WireOutputShouldMatch",
    "None_ConnectWireGate_ShouldFailWireNullptr",
    "None_ConnectWireGate_ShouldBeErrorWireIsNull",
    "None_ConnectWireGate_ShouldFailGateNullptr",
    "None_ConnectWireGate_ShouldBeErrorGateIsNull",
    "None_ConnectGateWire_ShouldSucceed",
    "None_ConnectGateWire_ShouldBeErrorNone",
    "None_ConnectGateWire_GateInputShouldMatch",
    "None_ConnectGateWire_GateOutputShouldMatch",
    "None_ConnectGateWire_WireInputShouldMatch",
    "None_ConnectGateWire_WireOutputShouldMatch",
    "None_ConnectGateWire_ShouldFailWireNullptr",
    "None_ConnectGateWire_ShouldBeErrorWireIsNull",
    "None_ConnectGateWire_ShouldFailGateNullptr",
    "None_ConnectGateWire_ShouldBeErrorGateIsNull",
    "None_GetIDListNodes_ShouldMatch",
    "None_GetIDListGates_ShouldMatch",
    "None_GetIDListWires_ShouldMatch",
    "None_GetNameListNodes_NameShouldMatch",
    "None_GetNameListGates_NameShouldMatch",
    "None_GetNameListWires_NameShouldMatch",
    "None_GetGateList_ShouldMatch",
    "None_GetWireList_ShouldMatch",
    "None_GetInputsList_ShouldMatch",
    "None_GetOutputsList_ShouldMatch"
};

UnitTestList BGL_UTL("BGL Unit Tests", BasicGateLibTestFunctionVector, BasicGateLibTestNameVector);

void Node_Constr_ShouldMatch() {
    Node w0;
    BGL_UTL.AssertEqual(w0.GetID(), 1);
}

void Node_ConstrName_NameShouldMatch() {
    Node w0("w0");
    BGL_UTL.AssertEqual(w0.GetName(), "w0");
}

void Gate_Constr_GateTypeShouldBeUNDEF() {
    Gate g0;
    BGL_UTL.AssertEqual(g0.GetGateType(), UNDEF);
}

void Gate_ConstrName_NameShouldMatch() { 
    Gate g0("g0");
    BGL_UTL.AssertEqual(g0.GetName(), "g0");
}

void Gate_ConstrGateType_GateTypeShouldBeINV() {
    Gate g0(INV);
    BGL_UTL.AssertEqual(g0.GetGateType(), INV);
}

void Gate_ConstrGateTypeName_NameShouldMatch() {
    Gate g0(INV, "g0");
    BGL_UTL.AssertEqual(g0.GetName(), "g0");
}

void Gate_ConstrInputsOutputs_InputShouldMatch() {
    Wire w0;
    Gate g0(AND, {&w0}, {});
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void Gate_ConstrInputsOutputs_InputsShouldBeEmpty() {
    Gate g0(AND, {}, {});
    BGL_UTL.AssertTrue(g0.GetInputs().empty());
}

void Gate_ConstrInputsOutputs_OutputShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {&w0}, {&w1});
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w1.GetID());
}

void Gate_ConstrInputsOutputsName_NameShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {&w0}, {&w1}, "g0");
    BGL_UTL.AssertEqual(g0.GetName(), "g0");
}

void Gate_GetGateType_GateTypeShouldBeAND() {
    Gate g0(AND);
    BGL_UTL.AssertEqual(g0.GetGateType(), AND);
}

void Gate_GetInputs_ShouldMatch() {
    Wire w0, w1, w2, w3;
    Gate g0(AND, {&w0, &w1, &w2, &w3}, {});
    BGL_UTL.AssertEqual(g0.GetInputs().at(3)->GetID(), w3.GetID());
}

void Gate_GetInputs_ShouldBeEmpty() {
    Gate g0(UNDEF);
    BGL_UTL.AssertTrue(g0.GetInputs().empty());
}

void Gate_GetOutputs_ShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1, &w2, &w3}, {&w4});
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w4.GetID());
}

void Wire_ConstrName_NameShouldMatch() {
    Wire w0("w0");
    BGL_UTL.AssertEqual(w0.GetName(), "w0");
}

void Wire_GetInputs_ShouldMatch() {
    Gate g0;
    Wire w0;
    Connect(&g0, &w0);
    BGL_UTL.AssertEqual(w0.GetInputs().at(0)->GetID(), g0.GetID());
}

void Wire_GetInputs_ShouldBeEmpty() {
    Wire w0;
    BGL_UTL.AssertTrue(w0.GetInputs().empty());
}

void Wire_GetOutputs_ShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(w0.GetOutputs().at(0)->GetID(), g0.GetID());
}

void Wire_GetOutputs_ShouldBeEmpty() {
    Wire w0;
    BGL_UTL.AssertTrue(w0.GetOutputs().empty());
}

void None_ConnectWireGate_ShouldSucceed() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertFalse(Connect(&w0, &g0));
}

void None_ConnectWireGate_ShouldBeErrorNone() {
    int res = -1;
    Wire w0;
    Gate g0;
    res = Connect(&w0, &g0);
    BGL_UTL.AssertEqual(res, ERROR_NONE);
}

void None_ConnectWireGate_GateInputShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void None_ConnectWireGate_GateOutputShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {}, {&w1});
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w1.GetID());
}

void None_ConnectWireGate_WireInputShouldMatch() {
    Wire w0, w1;
    Gate g0;
    Connect(&g0, &w1);
    BGL_UTL.AssertEqual(w1.GetInputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectWireGate_WireOutputShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {}, {&w1});
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(w0.GetOutputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectWireGate_ShouldFailWireNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertTrue(Connect(nullptr, &g0));
}

void None_ConnectWireGate_ShouldBeErrorWireIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    res = Connect(nullptr, &g0);
    BGL_UTL.AssertEqual(res, ERROR_WIRE_IS_NULL);
}

void None_ConnectWireGate_ShouldFailGateNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertTrue(Connect(&w0, nullptr));
}

void None_ConnectWireGate_ShouldBeErrorGateIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    res = Connect(&w0, nullptr);
    BGL_UTL.AssertEqual(res, ERROR_GATE_IS_NULL);
}

void None_ConnectGateWire_ShouldSucceed() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertFalse(Connect(&g0, &w0));
}

void None_ConnectGateWire_ShouldBeErrorNone() {
    int res = -1;
    Wire w0;
    Gate g0;
    res = Connect(&g0, &w0);
    BGL_UTL.AssertEqual(res, ERROR_NONE);
}

void None_ConnectGateWire_GateInputShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {&w0}, {});
    Connect(&g0, &w1);
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void None_ConnectGateWire_GateOutputShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&g0, &w0);
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w0.GetID());
}

void None_ConnectGateWire_WireInputShouldMatch() {
    Wire w0;
    Gate g0(AND, {&w0}, {});
    Connect(&g0, &w0);
    BGL_UTL.AssertEqual(w0.GetInputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectGateWire_WireOutputShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(w0.GetOutputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectGateWire_ShouldFailWireNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertTrue(Connect(&g0, nullptr));
}

void None_ConnectGateWire_ShouldBeErrorWireIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    res = Connect(&g0, nullptr);
    BGL_UTL.AssertEqual(res, ERROR_WIRE_IS_NULL);
}

void None_ConnectGateWire_ShouldFailGateNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertTrue(Connect(nullptr, &w0));
}

void None_ConnectGateWire_ShouldBeErrorGateIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    res = Connect(nullptr, &w0);
    BGL_UTL.AssertEqual(res, ERROR_GATE_IS_NULL);
}

void None_GetIDListNodes_ShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1}, &w2);
    Gate g1(OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w0.GetID(), w1.GetID(), g0.GetID(), w2.GetID(), w3.GetID(), g1.GetID(), w4.GetID()}, GetIDList(netList));
}

void None_GetIDListGates_ShouldMatch() {
    Wire w0, w1;
    Gate g0, g1;
    std::vector<Gate*> gateList = {&g0, &g1};
    BGL_UTL.AssertEqual({g0.GetID(), g1.GetID()}, GetIDList(gateList));
}

void None_GetIDListWires_ShouldMatch() {
    Wire w0, w1;
    std::vector<Wire*> wireList = {&w0, &w1};
    BGL_UTL.AssertEqual({w0.GetID(), w1.GetID()}, GetIDList(wireList));
}

void None_GetNameListNodes_NameShouldMatch() {
    Wire w0("w0"), w1("w1"), w2("w2"), w3("w3"), w4("w4");
    Gate g0(AND, {&w0, &w1}, &w2, "g0");
    Gate g1(OR, {&w2, &w3}, &w4, "g1");
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w0.GetName(), w1.GetName(), g0.GetName(), w2.GetName(), w3.GetName(), g1.GetName(), w4.GetName()}, GetNameList(netList));
}

void None_GetNameListGates_NameShouldMatch() {
    Wire w0, w1;
    Gate g0("g0"), g1("g1");
    std::vector<Gate*> gateList = {&g0, &g1};
    BGL_UTL.AssertEqual({g0.GetName(), g1.GetName()}, GetNameList(gateList));
}

void None_GetNameListWires_NameShouldMatch() {
    Wire w0("w0"), w1("w1");
    std::vector<Wire*> wireList = {&w0, &w1};
    BGL_UTL.AssertEqual({w0.GetName(), w1.GetName()}, GetNameList(wireList));
}

void None_GetGateList_ShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1}, &w2);
    Gate g1(OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({g0.GetID(), g1.GetID()}, GetIDList(GetGateList(netList)));
}

void None_GetWireList_ShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1}, &w2);
    Gate g1(OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w0.GetID(), w1.GetID(), w2.GetID(), w3.GetID(), w4.GetID()}, GetIDList(GetWireList(netList)));
}

void None_GetInputsList_ShouldMatch() { 
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1}, &w2);
    Gate g1(OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w0.GetID(), w1.GetID(), w3.GetID()}, GetIDList(GetInputsList(netList)));
}

void None_GetOutputsList_ShouldMatch() { 
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1}, &w2);
    Gate g1(OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w4.GetID()}, GetIDList(GetOutputsList(netList)));
}