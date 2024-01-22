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



// [GapFilling]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterGapFilling, GapFilling) {
	const int setValue = GetParam();
	// by namespace
	testIntValue(profiler, profile_processing::GapFilling::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterGapFilling, ::testing::Range(0, 17));





// [GapFillingEdgePreservation]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterGapFillingEdgePreservation, GapFillingEdgePreservation) {
    const int setValue = GetParam();
    // by namespace
    testIntValue(profiler, profile_processing::GapFillingEdgePreservation::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterGapFillingEdgePreservation, ::testing::Range(0, 6));



// [Resampling]: Testing the [set/getEnumValue] Interface with Normal Values
TEST_P(ProfilerParameterResampling, Resampling) {

    std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first << modeMap.second << std::endl;
    testEnumValue(profiler, profile_processing::Resampling::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterResampling,
    ::testing::Values(std::make_pair("Nearest", 0), std::make_pair("Farthest", 1)));




// [ResamplingEdgePreservation]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterResamplingEdgePreservation, ResamplingEdgePreservation) {
    const int setValue = GetParam();
    // by namespace
    testIntValue(profiler, profile_processing::ResamplingEdgePreservation::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterResamplingEdgePreservation, ::testing::Range(1, 6));
