#include <iostream>
#include <cmath>
#include "gtest/gtest.h"
#include "profiler/ProfilerFixture.h"
#include "profiler/ProfilerFunction.h"
#include "profiler/parameters/ProfileExtractionParameters.h"
#include "profiler/parameters/RawImageParameters.h"



// [DigitalGain->MinGrayscaleValue->Min/MaxSpotIntensity]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterMinGrayscaleValue, MinGrayscaleValue) {
	const int DigitalGain = GetParam();
    testIntValue(profiler, brightness_settings::DigitalGain::name, DigitalGain);

 //   const int value = std::ceil((DigitalGain * 0.49 + 7.54) + 5 * (DigitalGain * 0.6 + 0.43));
 //   std::cout << value << std::endl;
	//// by namespace
 //   for (int setGrayValue = value; setGrayValue <= 250; ++setGrayValue){
	//    testIntValue(profiler, profile_extraction::MinGrayscaleValue::name, setGrayValue);
 //       for (int setMinSpotValue = setGrayValue + 2; setMinSpotValue <= 255; setMinSpotValue+=15) {
	//    testIntValue(profiler, profile_extraction::MinSpotIntensity::name, profile_extraction::MaxSpotIntensity::name, setGrayValue + 1,setMinSpotValue);
 //       }
 //   }
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterMinGrayscaleValue, ::testing::Range(0, 11));



// [MinMaxLaserLineWidth]: Testing the [set/getValue] Interface with Normal Values
TEST_F(ProfilerParameterMinMaxLaserLineWidth, MinMaxLaserLineWidth) {
	for(int maxWidth=1; maxWidth<=64; ++maxWidth){
        const int minWidth = 0;
	    testIntValue(profiler, profile_extraction::MinLaserLineWidth::name, profile_extraction::MaxLaserLineWidth::name, minWidth,maxWidth);
    }

    for(int minWidth=63; minWidth>=0; --minWidth){
        const int maxWidth = 64;
	    testIntValue(profiler, profile_extraction::MinLaserLineWidth::name, profile_extraction::MaxLaserLineWidth::name, minWidth,maxWidth);
    }

    int minWidth = 0;
    for(int maxWidth=4; maxWidth<=64; maxWidth+=4){
	    testIntValue(profiler, profile_extraction::MinLaserLineWidth::name, profile_extraction::MaxLaserLineWidth::name, minWidth,maxWidth);
        minWidth += 3;
    }
}



// [SpotSelection]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterSpotSelection, SpotSelection) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testEnumValue(profiler, profile_extraction::SpotSelection::name, modeMap);
}

INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterSpotSelection,
    ::testing::Values(std::make_pair("Strongest", 0), std::make_pair("Nearest", 1), std::make_pair("Farthest", 2), std::make_pair("Invalid", 3)));