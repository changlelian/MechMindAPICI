#pragma once
#include "TestFixture.h"


void testErrorStatusSuccessful(const mmind::eye::ErrorStatus& status);

void testIntValue(mmind::eye::VirtualProfiler& profiler, const std::string& parameterName);

void testFloatValue(mmind::eye::VirtualProfiler& profiler, const std::string& parameterName);

void testBoolValue(mmind::eye::VirtualProfiler& profiler, const std::string& parameterName);

