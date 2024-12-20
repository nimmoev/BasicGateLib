#include "BasicGateLibTests.h"

std::vector<void (*)()> BasicGateLibTestFunctionVector = {
    Gate_Constr_GateTypeShouldBeUNDEF,
    Gate_ConstrGateType_GateTypeShouldBeINV,
    Gate_ConstrInputsOutputs_InputIDShouldMatch,
    Gate_ConstrInputsOutputs_InputsShouldBeEmpty,
    Gate_ConstrInputsOutputs_OutputIDShouldMatch,
    Gate_GetGateType_GateTypeShouldBeAND,
    Gate_GetInputs_IDShouldMatch,
    Gate_GetInputs_ShouldBeEmpty,
    Gate_GetOutputs_IDShouldMatch,
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
    "Gate_GetGateType_GateTypeShouldBeAND",
    "Gate_GetInputs_IDShouldMatch",
    "Gate_GetInputs_ShouldBeEmpty",
    "Gate_GetOutputs_IDShouldMatch",
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

UnitTestList BGL_UTL("BGL Unit Tests", BasicGateLibTestFunctionVector, BasicGateLibTestNameVector);

void Gate_Constr_GateTypeShouldBeUNDEF() {
    Gate g0;
    BGL_UTL.AssertEqual(g0.GetGateType(), UNDEF);
}

void Gate_ConstrGateType_GateTypeShouldBeINV() {
    Gate g0(INV);
    BGL_UTL.AssertEqual(g0.GetGateType(), INV);
}

void Gate_ConstrInputsOutputs_InputIDShouldMatch() {
    Wire w0;
    Gate g0(AND, {&w0}, {});
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void Gate_ConstrInputsOutputs_InputsShouldBeEmpty() {
    Gate g0(AND, {}, {});
    BGL_UTL.AssertTrue(g0.GetInputs().empty());
}

void Gate_ConstrInputsOutputs_OutputIDShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {&w0}, {&w1});
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w1.GetID());
}

void Gate_GetGateType_GateTypeShouldBeAND() {
    Gate g0(AND);
    BGL_UTL.AssertEqual(g0.GetGateType(), AND);
}

void Gate_GetInputs_IDShouldMatch() {
    Wire w0, w1, w2, w3;
    Gate g0(AND, {&w0, &w1, &w2, &w3}, {});
    BGL_UTL.AssertEqual(g0.GetInputs().at(3)->GetID(), w3.GetID());
}

void Gate_GetInputs_ShouldBeEmpty() {
    Gate g0(UNDEF);
    BGL_UTL.AssertTrue(g0.GetInputs().empty());
}

void Gate_GetOutputs_IDShouldMatch() {
    Wire w0, w1, w2, w3, w4;
    Gate g0(AND, {&w0, &w1, &w2, &w3}, {&w4});
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w4.GetID());
}

void Wire_GetInputs_IDShouldMatch() {
    Gate g0;
    Wire w0;
    Connect(&g0, &w0);
    BGL_UTL.AssertEqual(w0.GetInputs().at(0)->GetID(), g0.GetID());
}

void Wire_GetInputs_ShouldBeEmpty() {
    Wire w0;
    BGL_UTL.AssertTrue(w0.GetInputs().empty());
}

void Wire_GetOutputs_IDShouldMatch() {
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
    BGL_UTL.AssertTrue(Connect(&w0, &g0));
}

void None_ConnectWireGate_ShouldBeErrorNone() {
    int res = -1;
    Wire w0;
    Gate g0;
    Connect(&w0, &g0, &res);
    BGL_UTL.AssertEqual(res, ERROR_NONE);
}

void None_ConnectWireGate_GateInputIDShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void None_ConnectWireGate_GateOutputIDShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {}, {&w1});
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w1.GetID());
}

void None_ConnectWireGate_WireInputIDShouldMatch() {
    Wire w0, w1;
    Gate g0;
    Connect(&g0, &w1);
    BGL_UTL.AssertEqual(w1.GetInputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectWireGate_WireOutputIDShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {}, {&w1});
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(w0.GetOutputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectWireGate_ShouldFailWireNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertFalse(Connect(nullptr, &g0));
}

void None_ConnectWireGate_ShouldBeErrorWireIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    Connect(nullptr, &g0, &res);
    BGL_UTL.AssertEqual(res, ERROR_WIRE_IS_NULL);
}

void None_ConnectWireGate_ShouldFailGateNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertFalse(Connect(&w0, nullptr));
}

void None_ConnectWireGate_ShouldBeErrorGateIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    Connect(&w0, nullptr, &res);
    BGL_UTL.AssertEqual(res, ERROR_GATE_IS_NULL);
}

void None_ConnectGateWire_ShouldSucceed() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertTrue(Connect(&g0, &w0));
}

void None_ConnectGateWire_ShouldBeErrorNone() {
    int res = -1;
    Wire w0;
    Gate g0;
    Connect(&g0, &w0, &res);
    BGL_UTL.AssertEqual(res, ERROR_NONE);
}

void None_ConnectGateWire_GateInputIDShouldMatch() {
    Wire w0, w1;
    Gate g0(AND, {&w0}, {});
    Connect(&g0, &w1);
    BGL_UTL.AssertEqual(g0.GetInputs().at(0)->GetID(), w0.GetID());
}

void None_ConnectGateWire_GateOutputIDShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&g0, &w0);
    BGL_UTL.AssertEqual(g0.GetOutput()->GetID(), w0.GetID());
}

void None_ConnectGateWire_WireInputIDShouldMatch() {
    Wire w0;
    Gate g0(AND, {&w0}, {});
    Connect(&g0, &w0);
    BGL_UTL.AssertEqual(w0.GetInputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectGateWire_WireOutputIDShouldMatch() {
    Wire w0;
    Gate g0;
    Connect(&w0, &g0);
    BGL_UTL.AssertEqual(w0.GetOutputs().at(0)->GetID(), g0.GetID());
}

void None_ConnectGateWire_ShouldFailWireNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertFalse(Connect(&g0, nullptr));
}

void None_ConnectGateWire_ShouldBeErrorWireIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    Connect(&g0, nullptr, &res);
    BGL_UTL.AssertEqual(res, ERROR_WIRE_IS_NULL);
}

void None_ConnectGateWire_ShouldFailGateNullptr() {
    Wire w0;
    Gate g0;
    BGL_UTL.AssertFalse(Connect(nullptr, &w0));
}

void None_ConnectGateWire_ShouldBeErrorGateIsNull() {
    int res = -1;
    Wire w0;
    Gate g0;
    Connect(nullptr, &w0, &res);
    BGL_UTL.AssertEqual(res, ERROR_GATE_IS_NULL);
}
