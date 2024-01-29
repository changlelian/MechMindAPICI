#include <iostream>
#include "profiler/ProfilerFixture.h"
#include "profiler/ProfilerFunction.h"
#include "profiler/parameters/ScanParameters.h"
#include "profiler/parameters/ProfileProcessingParameters.h"
#include "profiler/parameters/RawImageParameters.h"
using namespace mmind::eye;

/**
*    LineScanTriggerSource-FixedRate
*/
TEST_F(ProfilerCouplingParameters, TestDataAcquisitionTriggerSourceFixedRateMode) {
    auto us = profiler.currentUserSet();
    
    // available
    testProStautsSuccessful(us.setEnumValue(mmind::eye::trigger_settings::LineScanTriggerSource::name,
        static_cast<int>(mmind::eye::trigger_settings::LineScanTriggerSource::Value::FixedRate)));

    testProStautsSuccessful(us.setFloatValue(mmind::eye::trigger_settings::SoftwareTriggerRate::name, 1000));

    // not available
    testProStautsFailed(us.setEnumValue(mmind::eye::trigger_settings::EncoderTriggerDirection::name,
        static_cast<int>(mmind::eye::trigger_settings::EncoderTriggerDirection::Value::ChannelALeading)));

    testProStautsFailed(us.setEnumValue(mmind::eye::trigger_settings::EncoderTriggerSignalCountingMode::name,
        static_cast<int>(mmind::eye::trigger_settings::EncoderTriggerSignalCountingMode::Value::Multiple_1)));

    testProStautsFailed(us.setIntValue(mmind::eye::trigger_settings::EncoderTriggerInterval::name, 20));
}



/**
*    LineScanTriggerSource-Encoder
*/
TEST_F(ProfilerCouplingParameters, TestDataAcquisitionTriggerSourceEncoderMode) {
    auto us = profiler.currentUserSet();

    // available
    testProStautsSuccessful(us.setEnumValue(mmind::eye::trigger_settings::LineScanTriggerSource::name,
        static_cast<int>(mmind::eye::trigger_settings::LineScanTriggerSource::Value::Encoder)));

    testProStautsSuccessful(us.setEnumValue(mmind::eye::trigger_settings::EncoderTriggerDirection::name,
        static_cast<int>(mmind::eye::trigger_settings::EncoderTriggerDirection::Value::ChannelALeading)));

    testProStautsSuccessful(us.setEnumValue(mmind::eye::trigger_settings::EncoderTriggerSignalCountingMode::name,
        static_cast<int>(mmind::eye::trigger_settings::EncoderTriggerSignalCountingMode::Value::Multiple_1)));

    testProStautsSuccessful(us.setIntValue(mmind::eye::trigger_settings::EncoderTriggerInterval::name, 20));

    // not available
    testProStautsFailed(us.setFloatValue(mmind::eye::trigger_settings::SoftwareTriggerRate::name, 1000));
}




// Filter-None
TEST_F(ProfilerCouplingParameters, TestFilterNoneMode) {
    auto us = profiler.currentUserSet();

    // available
    testProStautsSuccessful(us.setEnumValue(mmind::eye::profile_processing::Filter::name,
        static_cast<int>(mmind::eye::profile_processing::Filter::Value::None)));

    // not available
    testProStautsFailed(us.setEnumValue(mmind::eye::profile_processing::MedianFilterWindowSize::name,
        static_cast<int>(mmind::eye::profile_processing::MedianFilterWindowSize::Value::WindowSize_3)));

    testProStautsFailed(us.setEnumValue(mmind::eye::profile_processing::MeanFilterWindowSize::name,
        static_cast<int>(mmind::eye::profile_processing::MeanFilterWindowSize::Value::WindowSize_2)));
}



// Filter-Mean
TEST_F(ProfilerCouplingParameters, TestFilterMeanMode) {
    auto us = profiler.currentUserSet();

    // available
    testProStautsSuccessful(us.setEnumValue(mmind::eye::profile_processing::Filter::name,
        static_cast<int>(mmind::eye::profile_processing::Filter::Value::Mean)));

    testProStautsSuccessful(us.setEnumValue(mmind::eye::profile_processing::MeanFilterWindowSize::name,
        static_cast<int>(mmind::eye::profile_processing::MeanFilterWindowSize::Value::WindowSize_2)));

    // not available
    testProStautsFailed(us.setEnumValue(mmind::eye::profile_processing::MedianFilterWindowSize::name,
        static_cast<int>(mmind::eye::profile_processing::MedianFilterWindowSize::Value::WindowSize_3)));
}




// Filter-Median
TEST_F(ProfilerCouplingParameters, TestFilterMedianMode) {
    auto us = profiler.currentUserSet();

    // available
    testProStautsSuccessful(us.setEnumValue(mmind::eye::profile_processing::Filter::name,
        static_cast<int>(mmind::eye::profile_processing::Filter::Value::Mean)));

    testProStautsSuccessful(us.setEnumValue(mmind::eye::profile_processing::MeanFilterWindowSize::name,
        static_cast<int>(mmind::eye::profile_processing::MeanFilterWindowSize::Value::WindowSize_2)));

    // not available
    testProStautsFailed(us.setEnumValue(mmind::eye::profile_processing::MedianFilterWindowSize::name,
        static_cast<int>(mmind::eye::profile_processing::MedianFilterWindowSize::Value::WindowSize_3)));
}



// Exposure-HDR
TEST_F(ProfilerCouplingParameters, TestExposureTimedMode) {
    auto us = profiler.currentUserSet();

    // available
    testProStautsSuccessful(us.setEnumValue(mmind::eye::brightness_settings::ExposureMode::name,
        static_cast<int>(mmind::eye::brightness_settings::ExposureMode::Value::HDR)));

    testProStautsSuccessful(us.setFloatValue(mmind::eye::brightness_settings::HdrExposureTimeProportion1::name, 33));
    testProStautsSuccessful(us.setFloatValue(mmind::eye::brightness_settings::HdrExposureTimeProportion2::name, 37));

    // not available
    testProStautsFailed(us.setIntValue(mmind::eye::brightness_settings::ExposureTime::name, 100));

}
