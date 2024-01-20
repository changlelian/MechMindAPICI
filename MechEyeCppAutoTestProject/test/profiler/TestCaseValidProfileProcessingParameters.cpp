#include <iostream>
#include "gtest/gtest.h"
#include "profiler/ProfilerFixture.h"
#include "profiler/ProfilerFunction.h"
#include "profiler/parameters/ProfileProcessingParameters.h"



// [DepthTriggerSource]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterFilter, Filter) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testEnumValue(profiler, profile_processing::Filter::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterFilter,
    ::testing::Values(std::make_pair("None", 0), std::make_pair("Mean", 1),  std::make_pair("Median", 2)));



// [DepthTriggerSource]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterMeanFilterWindowSize, DepthTriggerSourceEnumValue) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testEnumValue(profiler, profile_processing::MeanFilterWindowSize::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterMeanFilterWindowSize,
    ::testing::Values(std::make_pair("WindowSize_2", 0), std::make_pair("WindowSize_4", 1), std::make_pair("WindowSize_8", 2),
        std::make_pair("WindowSize_16", 3),  std::make_pair("WindowSize_32", 4)));



// [DepthTriggerSource]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterMedianFilterWindowSize, MedianFilterWindowSize) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testEnumValue(profiler, profile_processing::MedianFilterWindowSize::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterMedianFilterWindowSize,
    ::testing::Values(std::make_pair("WindowSize_3", 0), std::make_pair("WindowSize_5", 1),  std::make_pair("WindowSize_7", 2), std::make_pair("WindowSize_9", 3)));



// [EncoderTriggerInterval]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterGapFilling, EncoderTriggerInterval) {
	const int setValue = GetParam();
	// by namespace
	testIntValue(profiler, profile_processing::GapFilling::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterGapFilling, ::testing::Range(0, 17));
