#pragma once
#include <iostream>
#include <chrono>
#include "gtest/gtest.h"
#include <type_traits>
#include <unordered_map>
#include "profiler/ProfilerFixture.h"
#include "ErrorStatus.h"
#include "UserSetManager.h"
#include "profiler/Profiler.h"




enum class ProfilerType
{
	LNX_8030,
	LNX_8300,
	LNX_8080,
	UnkonwType
};

ProfilerType JudgeProfilerType(mmind::eye::Profiler& profiler);


enum class ProfilerAnalogGainType
{
    AnalogGain_1_to_4,
    AnalogGain_1_to_5
};
ProfilerAnalogGainType getProfilerAnalogGainType(std::string& modeName);


/**
 * @brief 
 */

void testProStautsSuccessful(const ErrorStatus& status, int code=0, std::string description="", bool isMatch=true);

void testProStautsFailed(const ErrorStatus& status, int code = 0, std::string description = "");
/*******************************************************************************************************************
*                                                                Valid Parameter Test
*******************************************************************************************************************/
// Test Int value  
void testIntValue(mmind::eye::Profiler& profiler, const std::string& parameterName, const int& setValue);

// Test MinLaserLineWidth value  
void testIntValue(mmind::eye::Profiler& profiler, const std::string& parameterName1, const std::string& parameterName2, const int& setValue1, const int& setValue2);

// Test double value  [start value: 0.1]
void testDoubleValue(mmind::eye::Profiler& profiler, const std::string& parameterName, const double& setValue);

// Test Enum value  
void testEnumValue(mmind::eye::Profiler& profiler, const std::string& parameterName, const std::pair<std::string, int>& modePair);


/*
// Test invalid Enum value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::map<std::string, int>& setValueList,
                                   const int& setCode,  const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription);
*/

// Test invalid Enum value
void testInvalidValue(mmind::eye::Profiler* profiler, const std::string& parameterName, const std::pair<std::string, int>& setValueList,
                                   const int& setCode, const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription,
                                   const bool& otherCameraFlag=true);