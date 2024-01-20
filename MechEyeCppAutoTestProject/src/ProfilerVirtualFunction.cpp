#include "ProfilerVirtualFunction.h"

void testErrorStatusSuccessful(const mmind::eye::ErrorStatus& status) {
    EXPECT_TRUE(status.isOK());
    EXPECT_EQ(status.errorCode, 0);
    EXPECT_EQ(status.errorDescription, "");
}


void testIntValue(mmind::eye::VirtualProfiler& profiler, const std::string& parameterName) {
    mmind::eye::VirtualUserSet virtualUserSet = profiler.currentUserSet();
    auto* intParam = virtualUserSet.getParameter(parameterName);
    auto* intParameter = dynamic_cast<mmind::eye::IntParameter*>(intParam);
    if (!intParameter)
        FAIL();

    int getValue, minValue, maxValue, step;
    std::string unit;
    EXPECT_EQ(intParameter->setValue(40).errorCode, static_cast<int>(mmind::eye::ErrorStatus::MMIND_STATUS_NO_SUPPORT_ERROR));
    EXPECT_NE(intParameter->setValue(40).errorDescription, "");
    showError(intParameter->getValue(getValue));
    showError(intParameter->getMin(minValue));
    showError(intParameter->getMax(maxValue));
    showError(intParameter->getStep(step));
    showError(intParameter->getUnit(unit));
}

void testFloatValue(mmind::eye::VirtualProfiler& profiler, const std::string& parameterName) {
    mmind::eye::VirtualUserSet virtualUserSet = profiler.currentUserSet();
    auto* intParam = virtualUserSet.getParameter(parameterName);
    auto* floatParameter = dynamic_cast<mmind::eye::FloatParameter*>(intParam);
    if (!floatParameter)
        FAIL();

    double getValue, minValue, maxValue, step;
    std::string unit;
    EXPECT_EQ(floatParameter->setValue(40).errorCode, static_cast<int>(mmind::eye::ErrorStatus::MMIND_STATUS_NO_SUPPORT_ERROR));
    EXPECT_NE(floatParameter->setValue(40).errorDescription, "");
    showError(floatParameter->getValue(getValue));
    showError(floatParameter->getMin(minValue));
    showError(floatParameter->getMax(maxValue));
    showError(floatParameter->getStep(step));
    showError(floatParameter->getUnit(unit));
}

void testBoolValue(mmind::eye::VirtualProfiler& profiler, const std::string& parameterName) {
    mmind::eye::VirtualUserSet virtualUserSet = profiler.currentUserSet();
    auto* intParam = virtualUserSet.getParameter(parameterName);
    auto* enumParameter = dynamic_cast<mmind::eye::EnumParameter*>(intParam);
    if (!enumParameter)
        FAIL();

    int getIntValue, valueInt = 0;
    std::string getStringValue, valueString="0";
    std::map<std::string, int> valueList;

    EXPECT_EQ(enumParameter->setValue(valueInt).errorCode, static_cast<int>(mmind::eye::ErrorStatus::MMIND_STATUS_NO_SUPPORT_ERROR));
    EXPECT_NE(enumParameter->setValue(valueInt).errorDescription, "");

    EXPECT_EQ(enumParameter->setValue(valueString).errorCode, static_cast<int>(mmind::eye::ErrorStatus::MMIND_STATUS_NO_SUPPORT_ERROR));
    EXPECT_NE(enumParameter->setValue(valueString).errorDescription, "");

    showError(enumParameter->getValue(getIntValue));
    showError(enumParameter->getValue(getStringValue));
    showError(enumParameter->getValues(valueList));
}