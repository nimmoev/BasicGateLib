#include "BasicGateLibTests.h"

const std::vector<UnitTest> BGL_UnitTests = {
    UnitTest(Node_Constr_ShouldMatch, "Node_Constr_ShouldMatch"),
    UnitTest(Node_ConstrName_NameShouldMatch, "Node_ConstrName_NameShouldMatch"),
    UnitTest(Gate_Constr_GateTypeShouldBeUNDEF, "Gate_Constr_GateTypeShouldBeUNDEF"),
    UnitTest(Gate_ConstrName_NameShouldMatch, "Gate_ConstrName_NameShouldMatch"),
    UnitTest(Gate_ConstrGateType_GateTypeShouldBeINV, "Gate_ConstrGateType_GateTypeShouldBeINV"),
    UnitTest(Gate_ConstrGateTypeName_NameShouldMatch, "Gate_ConstrGateTypeName_NameShouldMatch"),
    UnitTest(Gate_ConstrInputsOutputs_InputShouldMatch, "Gate_ConstrInputsOutputs_InputShouldMatch"),
    UnitTest(Gate_ConstrInputsOutputs_InputsShouldBeEmpty, "Gate_ConstrInputsOutputs_InputsShouldBeEmpty"),
    UnitTest(Gate_ConstrInputsOutputs_OutputShouldMatch, "Gate_ConstrInputsOutputs_OutputShouldMatch"),
    UnitTest(Gate_ConstrInputsOutputsName_NameShouldMatch, "Gate_ConstrInputsOutputsName_NameShouldMatch"),
    UnitTest(Gate_GetGateType_GateTypeShouldBeAND, "Gate_GetGateType_GateTypeShouldBeAND"),
    UnitTest(Gate_GetInputs_ShouldMatch, "Gate_GetInputs_ShouldMatch"),
    UnitTest(Gate_GetInputs_ShouldBeEmpty, "Gate_GetInputs_ShouldBeEmpty"),
    UnitTest(Gate_GetOutputs_ShouldMatch, "Gate_GetOutputs_ShouldMatch"),
    UnitTest(Wire_ConstrName_NameShouldMatch, "Wire_ConstrName_NameShouldMatch"),
    UnitTest(Wire_GetInputs_ShouldMatch, "Wire_GetInputs_ShouldMatch"),
    UnitTest(Wire_GetInputs_ShouldBeEmpty, "Wire_GetInputs_ShouldBeEmpty"),
    UnitTest(Wire_GetOutputs_ShouldMatch, "Wire_GetOutputs_ShouldMatch"),
    UnitTest(Wire_GetOutputs_ShouldBeEmpty, "Wire_GetOutputs_ShouldBeEmpty"),
    UnitTest(None_ConnectWireGate_ShouldSucceed, "None_ConnectWireGate_ShouldSucceed"),
    UnitTest(None_ConnectWireGate_ShouldBeErrorNone, "None_ConnectWireGate_ShouldBeErrorNone"),
    UnitTest(None_ConnectWireGate_GateInputShouldMatch, "None_ConnectWireGate_GateInputShouldMatch"),
    UnitTest(None_ConnectWireGate_GateOutputShouldMatch, "None_ConnectWireGate_GateOutputShouldMatch"),
    UnitTest(None_ConnectWireGate_WireInputShouldMatch, "None_ConnectWireGate_WireInputShouldMatch"),
    UnitTest(None_ConnectWireGate_WireOutputShouldMatch, "None_ConnectWireGate_WireOutputShouldMatch"),
    UnitTest(None_ConnectWireGate_ShouldFailWireNullptr, "None_ConnectWireGate_ShouldFailWireNullptr"),
    UnitTest(None_ConnectWireGate_ShouldBeErrorWireIsNull, "None_ConnectWireGate_ShouldBeErrorWireIsNull"),
    UnitTest(None_ConnectWireGate_ShouldFailGateNullptr, "None_ConnectWireGate_ShouldFailGateNullptr"),
    UnitTest(None_ConnectWireGate_ShouldBeErrorGateIsNull, "None_ConnectWireGate_ShouldBeErrorGateIsNull"),
    UnitTest(None_ConnectGateWire_ShouldSucceed, "None_ConnectGateWire_ShouldSucceed"),
    UnitTest(None_ConnectGateWire_ShouldBeErrorNone, "None_ConnectGateWire_ShouldBeErrorNone"),
    UnitTest(None_ConnectGateWire_GateInputShouldMatch, "None_ConnectGateWire_GateInputShouldMatch"),
    UnitTest(None_ConnectGateWire_GateOutputShouldMatch, "None_ConnectGateWire_GateOutputShouldMatch"),
    UnitTest(None_ConnectGateWire_WireInputShouldMatch, "None_ConnectGateWire_WireInputShouldMatch"),
    UnitTest(None_ConnectGateWire_WireOutputShouldMatch, "None_ConnectGateWire_WireOutputShouldMatch"),
    UnitTest(None_ConnectGateWire_ShouldFailWireNullptr, "None_ConnectGateWire_ShouldFailWireNullptr"),
    UnitTest(None_ConnectGateWire_ShouldBeErrorWireIsNull, "None_ConnectGateWire_ShouldBeErrorWireIsNull"),
    UnitTest(None_ConnectGateWire_ShouldFailGateNullptr, "None_ConnectGateWire_ShouldFailGateNullptr"),
    UnitTest(None_ConnectGateWire_ShouldBeErrorGateIsNull, "None_ConnectGateWire_ShouldBeErrorGateIsNull"),
    UnitTest(None_GetIDListNodes_ShouldMatch, "None_GetIDListNodes_ShouldMatch"),
    UnitTest(None_GetIDListGates_ShouldMatch, "None_GetIDListGates_ShouldMatch"),
    UnitTest(None_GetIDListWires_ShouldMatch, "None_GetIDListWires_ShouldMatch"),
    UnitTest(None_GetNameListNodes_NameShouldMatch, "None_GetNameListNodes_NameShouldMatch"),
    UnitTest(None_GetNameListGates_NameShouldMatch, "None_GetNameListGates_NameShouldMatch"),
    UnitTest(None_GetNameListWires_NameShouldMatch, "None_GetNameListWires_NameShouldMatch"),
    UnitTest(None_GetGateList_ShouldMatch, "None_GetGateList_ShouldMatch"),
    UnitTest(None_GetWireList_ShouldMatch, "None_GetWireList_ShouldMatch"),
    UnitTest(None_GetInputsList_ShouldMatch, "None_GetInputsList_ShouldMatch"),
    UnitTest(None_GetOutputsList_ShouldMatch, "None_GetOutputsList_ShouldMatch")
};

UnitTestList BGL_UTL("BGL Unit Tests", BGL_UnitTests);

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
    BGL_UTL.AssertEqual(g0.GetGateType(), GATETYPE_UNDEF);
}

void Gate_ConstrName_NameShouldMatch() { 
    Gate g0("g0");
    BGL_UTL.AssertEqual(g0.GetName(), "g0");
}

void Gate_ConstrGateType_GateTypeShouldBeINV() {
    Gate g0(GATETYPE_INV);
    BGL_UTL.AssertEqual(g0.GetGateType(), GATETYPE_INV);
}

void Gate_ConstrGateTypeName_NameShouldMatch() {
    Gate g0(GATETYPE_INV, "g0");
    BGL_UTL.AssertEqual(g0.GetName(), "g0");
}

void Gate_ConstrInputsOutputs_InputShouldMatch() {
    Wire w0;
    Gate g0(GATETYPE_AND, {&w0}, {});
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void Gate_ConstrInputsOutputs_InputsShouldBeEmpty() {
    Gate g0(GATETYPE_AND, {}, {});
    BGL_UTL.AssertTrue(g0.GetInputs().empty());
}

void Gate_ConstrInputsOutputs_OutputShouldMatch() {
    Wire w0, w1;
    Gate g0(GATETYPE_AND, {&w0}, {&w1});
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w1.GetID());
}

void Gate_ConstrInputsOutputsName_NameShouldMatch() {
    Wire w0, w1;
    Gate g0(GATETYPE_AND, {&w0}, {&w1}, "g0");
    BGL_UTL.AssertEqual(g0.GetName(), "g0");
}

void Gate_GetGateType_GateTypeShouldBeAND() {
    Gate g0(GATETYPE_AND);
    BGL_UTL.AssertEqual(g0.GetGateType(), GATETYPE_AND);
}

void Gate_GetInputs_ShouldMatch() {
    Wire w0, w1, w2, w3;
    Gate g0(GATETYPE_AND, {&w0, &w1, &w2, &w3}, {});
    BGL_UTL.AssertEqual(g0.GetInputs().at(3)->GetID(), w3.GetID());
}

void Gate_GetInputs_ShouldBeEmpty() {
    Gate g0(GATETYPE_UNDEF);
    BGL_UTL.AssertTrue(g0.GetInputs().empty());
}

void Gate_GetOutputs_ShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(GATETYPE_AND, {&w0, &w1, &w2, &w3}, {&w4});
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
    Gate g0(GATETYPE_AND, {}, {&w1});
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
    Gate g0(GATETYPE_AND, {}, {&w1});
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
    Gate g0(GATETYPE_AND, {&w0}, {});
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
    Gate g0(GATETYPE_AND, {&w0}, {});
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
    Gate g0(GATETYPE_AND, {&w0, &w1}, &w2);
    Gate g1(GATETYPE_OR, {&w2, &w3}, &w4);
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
    Gate g0(GATETYPE_AND, {&w0, &w1}, &w2, "g0");
    Gate g1(GATETYPE_OR, {&w2, &w3}, &w4, "g1");
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
    Gate g0(GATETYPE_AND, {&w0, &w1}, &w2);
    Gate g1(GATETYPE_OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({g0.GetID(), g1.GetID()}, GetIDList(GetGateList(netList)));
}

void None_GetWireList_ShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(GATETYPE_AND, {&w0, &w1}, &w2);
    Gate g1(GATETYPE_OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w0.GetID(), w1.GetID(), w2.GetID(), w3.GetID(), w4.GetID()}, GetIDList(GetWireList(netList)));
}

void None_GetInputsList_ShouldMatch() { 
    Wire w0, w1, w2, w3, w4;
    Gate g0(GATETYPE_AND, {&w0, &w1}, &w2);
    Gate g1(GATETYPE_OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w0.GetID(), w1.GetID(), w3.GetID()}, GetIDList(GetInputsList(netList)));
}

void None_GetOutputsList_ShouldMatch() { 
    Wire w0, w1, w2, w3, w4;
    Gate g0(GATETYPE_AND, {&w0, &w1}, &w2);
    Gate g1(GATETYPE_OR, {&w2, &w3}, &w4);
    std::vector<Node*> netList = {&w0, &w1, &g0, &w2, &w3, &g1, &w4};
    BGL_UTL.AssertEqual({w4.GetID()}, GetIDList(GetOutputsList(netList)));
}