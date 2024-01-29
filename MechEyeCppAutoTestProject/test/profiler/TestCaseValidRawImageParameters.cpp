#include <iostream>
#include "gtest/gtest.h"
#include "profiler/ProfilerFixture.h"
#include "profiler/ProfilerFunction.h"
#include "profiler/parameters/RawImageParameters.h"



// [ExposureMode]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterExposureMode, ExposureMode) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testEnumValue(profiler, brightness_settings::ExposureMode::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterExposureMode,
    ::testing::Values(std::make_pair("HDR", 0), std::make_pair("Timed", 1) ));




TEST_P(ProfilerParameterExposureTime, ExposureTime) {
	std::pair<std::string, int> modeMap = GetParam();

    switch (modeMap.second)
    {
    case 0:
        std::cout << "wei wan cheng " << std::endl;
        break;
    case 1:
        testEnumValue(profiler, brightness_settings::ExposureMode::name, std::make_pair("Timed", 1));

        testEnumValue(profiler, brightness_settings::ExposureMode::name, modeMap);
        for (int setvalue = 4; setvalue <=5200; setvalue+=4)
            testIntValue(profiler, brightness_settings::ExposureTime::name, setvalue);
        break;
    
    default:
        break;
    }
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterExposureTime,
    ::testing::Values(std::make_pair("HDR", 0), std::make_pair("Timed", 1)));
                




// [HdrFirstThreshold]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterHdrFirstThreshold, HdrFirstThreshold) {

    testEnumValue(profiler, brightness_settings::ExposureMode::name, std::make_pair("HDR", 0));

	const double setValue = GetParam() * 0.100;
	// by namespace
	testDoubleValue(profiler, brightness_settings::HdrFirstThreshold::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterHdrFirstThreshold, ::testing::Range(180, 601));






// [HdrSecondThreshold]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterHdrSecondThreshold, HdrSecondThreshold) {
	const double setValue = GetParam() * 0.100;

    testEnumValue(profiler, brightness_settings::ExposureMode::name, std::make_pair("HDR", 0));

	// by namespace
	testDoubleValue(profiler, brightness_settings::HdrSecondThreshold::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterHdrSecondThreshold, ::testing::Range(180, 601));






// [AnalogGain]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterAnalogGain, AnalogGain) {
    std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;

    switch (JudgeProfilerType(profiler))
    {
    case ProfilerType::LNX_8030:
        break;
    
    default:
        testEnumValue(profiler, brightness_settings::AnalogGain::name, modeMap);
        break;
    }
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterAnalogGain,
    ::testing::Values(std::make_pair("Gain_1_0", 0), std::make_pair("Gain_1_3", 1), std::make_pair("Gain_1_9", 2), std::make_pair("Gain_2_8", 3), std::make_pair("Gain_5_5", 4)));






// [AnalogGainFor8030]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterAnalogGainFor8030, AnalogGainFor8030) {

    std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    switch (JudgeProfilerType(profiler))
    {
    case ProfilerType::LNX_8030:
        testEnumValue(profiler, brightness_settings::AnalogGainFor8030::name, modeMap);
        break;
    default:
        break;
    }

}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterAnalogGainFor8030,
    ::testing::Values(std::make_pair("Gain_1_0", 0), std::make_pair("Gain_1_3", 1),  std::make_pair("Gain_2_0", 2),  std::make_pair("Gain_3_0", 3)));





// [DigitalGain]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterDigitalGain, DigitalGain) {
	const int setValue = GetParam();
	// by namespace
	testIntValue(profiler, brightness_settings::DigitalGain::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterDigitalGain, ::testing::Range(0, 11));






// [LaserPower]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterLaserPower, LaserPower) {
	const int setValue = GetParam();
	// by namespace
	testIntValue(profiler, brightness_settings::LaserPower::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterLaserPower, ::testing::Range(40, 101));




// [ZDirectionRoi]: Testing the [set/getValue] Interface with Normal Values
TEST_P(ProfilerParameterZDirectionRoi, ZDirectionRoi) {

	std::pair<std::string, int> modeMap = GetParam();
    std::cout << modeMap.first  << modeMap.second << std::endl;
    testEnumValue(profiler, roi::ZDirectionRoi::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(Parameters, ProfilerParameterZDirectionRoi,
    ::testing::Values(std::make_pair("ImageHeight_1_1", 0), std::make_pair("ImageHeight_1_2", 1), 
     std::make_pair("ImageHeight_1_4", 2), std::make_pair("ImageHeight_1_8", 3),  std::make_pair("ImageHeight_1_16", 4)));

 