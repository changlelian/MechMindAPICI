#pragma once
#include <iostream>
#include <gtest/gtest.h>
#include "CommonTypes.h"
// #include "CameraFunction.h"
#include "TestFixture.h"

using namespace mmind::eye;

/**
 * @brief scan.h
 * 
 */

class ProfilerParameterDataAcquisitionTriggerSource : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterLineScanTriggerSource : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};

// incomplete
class ProfilerParameterSoftwareTriggerRate : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterEncoderTriggerDirection : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterEncoderTriggerSignalCountingMode : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterEncoderTriggerInterval : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterScanLineCount : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterExposureDelay : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterCallbackRetrievalTimeout : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterTiltCorrectionAngle : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};



class ProfilerParameterHeightCorrectionRatio : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


/**
 * @brief ProfileProcessingParameters.h
 * 
 */

class ProfilerParameterFilter : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterMeanFilterWindowSize : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterMedianFilterWindowSize : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterGapFilling : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


/**
 * @brief RawImageParameters.h
 * 
 */

class ProfilerParameterExposureMode : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};

class ProfilerParameterExposureTime : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterHdrFirstThreshold : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterHdrSecondThreshold : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterAnalogGain : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterAnalogGainFor8030 : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


class ProfilerParameterDigitalGain : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterLaserPower : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};


class ProfilerParameterZDirectionRoi : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};


/**
 * @brief ProfileExtractionParameters.h
 * 
 */

class ProfilerParameterMinGrayscaleValue : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<int>  {
};

class ProfilerParameterMinMaxLaserLineWidth:
    public ProfilerSDKFixture, public ::testing::WithParamInterface<int> {

};

class ProfilerParameterSpotSelection : 
    public ProfilerSDKFixture,  public ::testing::WithParamInterface<std::pair<std::string, int>>  {
};

