#pragma once
#include <iostream>
#include <string>
#include "area_scan_3d_camera/Camera.h"


/*******************************************************************************************************************
*                                                                Camera type
*******************************************************************************************************************/

// Categorize the configurable camera 2D exposure modes
enum class Camera2DExposureMode {
    Exposure2DModeNoFlash,             //  No Flash camera
    Exposure2DALLMode                     //  All exposure 2D mode camera
};

// Categorize the configurable camera 2D exposure modes
Camera2DExposureMode get2DExposureModeCamera(const std::string& input);


// Categorize cameras with the type of 2D exposure time that can be set
enum class Camera2DExposure {
    Exposure42D,              // 4-996/1
    Exposure2DOther       // 0.1-999/0.1
};

// Categorize cameras with the type of 2D exposure time that can be set
Camera2DExposure get2DExposureCameraType(const std::string& input);


// Categorize cameras with the type of HDR exposure time that can be set
enum class CameraScanHDRExposureType {
    HDR_4_996,
    HDR_01_999
};

// Categorize cameras with the type of HDR exposure time that can be set
CameraScanHDRExposureType getScanHDRExposureTypeCameraType(const std::string& input);

//Categorize cameras with configurable types of 3D exposure times
enum class Camera3DExposure {
    Exposure43D,             // 4-96
    Exposure83D,             //  8-96
    Exposure453D,           //  0.1-45
    Exposure3DOther       // 0.1-99
};

//Categorize cameras with configurable types of 3D exposure times
Camera3DExposure getCamera3DExposureType(const std::string& input);

//Categorize cameras with configurable types of 3D specific camera
enum class SpecificCameraType {
    LaserCameras,
    UHPCamera,
    OtherCamera
};

//Categorize cameras with configurable types of 3D specific camera
SpecificCameraType getSpecificCameraType(const std::string& input);


enum class CameraProjectorCodingMode {
    ProjectorCodingModeCamera,    //  ProjectorCodingMode  camera
    OtherCamera
};

CameraProjectorCodingMode getProjectorCodingModeCameraType(const std::string& input);


enum class CameraProjectorPowerLevel {
    ProjectorPowerLevelCamera,       //  ProjectorPowerLevel camera
    OtherCamera
};
CameraProjectorPowerLevel getProjectorPowerLevelCameraType(const std::string& input);


enum class CameraProjectorAntiflicker {
    ProjectorAntiflickerCamera,         //  ProjectorAntiflicker  camera
    OtherCamera
};
CameraProjectorAntiflicker getProjectorAntiflickerCameraType(const std::string& input);


enum class CameraDepthSourceExposure {
    DepthSourceExposureCamera,
    OtherCamera
};
CameraDepthSourceExposure getDepthSourceExposureCameraType(const std::string& input);


enum class CameraProjectorCodingTranslucentMode {
    TranslucentModeCamera,  // Translucent mode Pro S/M
    OtherCamera
};
CameraProjectorCodingTranslucentMode getProjectorCodingTranslucentModeCameraType(const std::string& input);


enum class CameraCodingModeReflective {
    ReflectiveModeCamera,  // Translucent mode Pro S/M  LSR
    OtherCamera
};
CameraCodingModeReflective getCodingModeReflectiveCameraType(const std::string& input);

/*******************************************************************************************************************
*                                                                Function tool
*******************************************************************************************************************/

std::string CurrentTimeToString();

bool ExpectROIAlmostEqual(const mmind::eye::ROI& roi1, const mmind::eye::ROI& roi2);

void ExpectVectorsAlmostEqual(const std::vector<double>& vec1, const std::vector<double>& vec2, double tolerance);

void isIncludeUserSet(mmind::eye::UserSetManager& usm, const std::string& userSetName, bool flag);

void testStautsSuccessful(const mmind::eye::ErrorStatus& status, int code=0, std::string description="");

void testStautsFailed(const mmind::eye::ErrorStatus& status, int code = 0, std::string description = "");


/*******************************************************************************************************************
*                                                               Parameter Test
*******************************************************************************************************************/

void testIntValue(mmind::eye::Camera& camera, const std::string& parameterName, const int& setValue);

void testDoubleValue(mmind::eye::Camera& camera, const std::string& parameterName, const double& setValue);

void testDoubleValue(mmind::eye::Camera& camera, const std::string& parameterName, const double& setValue, const int& repeat);

void testEnumValue(mmind::eye::Camera& camera, const std::string& parameterName, const std::pair<std::string, int>& modePair);

void testBoolValue(mmind::eye::Camera& camera, const std::string& parameterName, const bool& setValue);

void testROIValue(mmind::eye::Camera& camera, const std::string& parameterName, const mmind::eye::ROI& setRoi);

void testRangeValue(mmind::eye::Camera& camera, const std::string& parameterName, const int& setValue, const int& winSize);



/*******************************************************************************************************************
*                                                         Parameter Attribute Test
*******************************************************************************************************************/

void testIntParameterAttribute(mmind::eye::Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit = "");

void testDoubleParameterAttribute(mmind::eye::Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit="");

void testDoubleArrayParameterAttribute(mmind::eye::Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit = "");

void testEnumParameterAttribute(mmind::eye::Parameter* parameter, const int& mapSize, const std::vector<std::string>& modes);

void testRoiParameterAttribute(mmind::eye::Parameter* parameter, const int& maxWidth, const int& maxHeight);

void testRangeArrayParameterAttribute(mmind::eye::Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit = "");


mmind::eye::Parameter* testParameterAttribute(mmind::eye::Camera& camera, const std::string& parameterName,
    const mmind::eye::Parameter::Type& pType, const int& readFlag = 1, const int& writeFlag = 1);



/*******************************************************************************************************************
*                                                               Parameter invalidity  Test
*******************************************************************************************************************/

void testInvalidIntValue(mmind::eye::Camera& camera, const std::string& parameterName, const int& setValue, const mmind::eye::ErrorStatus::ErrorCode& code);

void testInvalidDoubleValue(mmind::eye::Camera& camera, const std::string& parameterName, const double& setValue, const mmind::eye::ErrorStatus::ErrorCode& code);

void testInvalidDoubleArrayValue(mmind::eye::Camera& camera, const std::string& parameterName, const std::vector<double>& setArrayValue, const mmind::eye::ErrorStatus::ErrorCode& code);

void testInvalidEnumValue(mmind::eye::Camera& camera, const std::string& parameterName, const std::pair<std::string, int>& setValueList, const mmind::eye::ErrorStatus::ErrorCode& code);

void testInvalidROIValue(mmind::eye::Camera& camera, const std::string& parameterName, const mmind::eye::ROI& setRoi, const mmind::eye::ErrorStatus::ErrorCode& code);

void testInvalidRangeValue(mmind::eye::Camera& camera, const std::string& parameterName, const mmind::eye::Range<int>& setRange, const mmind::eye::ErrorStatus::ErrorCode& code);