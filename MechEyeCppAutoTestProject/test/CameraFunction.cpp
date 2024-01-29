#include <unordered_map>
#include <chrono>
#include <gtest/gtest.h>
#include "area3d/CameraFunction.h"

//using namespace mmind::eye;


/*******************************************************************************************************************
*                                                                Camera type
*******************************************************************************************************************/

// Categorize the configurable camera 2D exposure modes
Camera2DExposureMode get2DExposureModeCamera(const std::string& input) {
    static const std::unordered_map<std::string, Camera2DExposureMode> cameraTypeMap = {
        {"Mech-Eye LSR L", Camera2DExposureMode::Exposure2DModeNoFlash},
        //{"Mech-Eye Deep", Camera2DExposureMode::Exposure2DModeNoFlash},
        {"Mech-Eye DEEP", Camera2DExposureMode::Exposure2DModeNoFlash}
    };

    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return Camera2DExposureMode::Exposure2DALLMode;
}

// Categorize cameras with the type of 2D exposure time that can be set
Camera2DExposure get2DExposureCameraType(const std::string& input) {
    static const std::unordered_map<std::string, Camera2DExposure> cameraTypeMap = {
        {"Mech-Eye Laser L", Camera2DExposure::Exposure42D},
        {"Mech-Eye Laser L Enhanced", Camera2DExposure::Exposure42D}
    };

    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return Camera2DExposure::Exposure2DOther;
}

// Categorize cameras with the type of HDR exposure time that can be set
CameraScanHDRExposureType getScanHDRExposureTypeCameraType(const std::string& input) {
    if (input == "Mech-Eye Laser L Enhanced" || input == "Mech-Eye Laser L")
        return CameraScanHDRExposureType::HDR_4_996;
    else
        return CameraScanHDRExposureType::HDR_01_999;

}

//Categorize cameras with configurable types of 3D exposure times
Camera3DExposure getCamera3DExposureType(const std::string& input) {
    static const std::unordered_map<std::string, Camera3DExposure> cameraTypeMap = {
        {"Mech-Eye Laser L", Camera3DExposure::Exposure43D},
        {"Mech-Eye Laser L Enhanced", Camera3DExposure::Exposure43D},
        {"Mech-Eye LSR L", Camera3DExposure::Exposure83D},
        {"Mech-Eye DEEP", Camera3DExposure::Exposure83D},
        {"Mech-Eye LSR S", Camera3DExposure::Exposure83D},
        {"Mech-Eye Pro L Enhanced", Camera3DExposure::Exposure453D}
    };

    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return Camera3DExposure::Exposure3DOther;
}

//Categorize cameras with configurable types of 3D specific camera
SpecificCameraType getSpecificCameraType(const std::string& input) {
    if (input == "Mech-Eye UHP-140")
        return SpecificCameraType::UHPCamera;
    else if (input == "Mech-Eye Laser L" || input == "Mech-Eye Laser L Enhanced" || input == "Mech-Eye LSR L" || input == "Mech-Eye DEEP")
        return SpecificCameraType::LaserCameras;
    else
        return SpecificCameraType::OtherCamera;

}

CameraProjectorCodingMode getProjectorCodingModeCameraType(const std::string& input) {
    static const std::unordered_map<std::string, CameraProjectorCodingMode> codingModeCameraTypeMap = {
        {"Mech-Eye NANO", CameraProjectorCodingMode::ProjectorCodingModeCamera},
        {"Mech-Eye PRO M", CameraProjectorCodingMode::ProjectorCodingModeCamera},
        {"Mech-Eye PRO S", CameraProjectorCodingMode::ProjectorCodingModeCamera},
        {"Mech-Eye UHP 140", CameraProjectorCodingMode::ProjectorCodingModeCamera},
        {"Mech-Eye PRO XS", CameraProjectorCodingMode::ProjectorCodingModeCamera}
    };
    auto it = codingModeCameraTypeMap.find(input);
    if (it != codingModeCameraTypeMap.end()) {
        return it->second;
    }

    return CameraProjectorCodingMode::OtherCamera;
}

CameraProjectorPowerLevel getProjectorPowerLevelCameraType(const std::string& input) {
    static const std::unordered_map<std::string, CameraProjectorPowerLevel> cameraTypeMap = {
        {"Mech-Eye Log M", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye Log S", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye NANO", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye PRO XS", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye PRO M", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye PRO S", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye S Enhanced", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye M Enhanced", CameraProjectorPowerLevel::ProjectorPowerLevelCamera},
        {"Mech-Eye UHP 140", CameraProjectorPowerLevel::ProjectorPowerLevelCamera}
    };
    auto it = cameraTypeMap.find(input);
    if (it != cameraTypeMap.end()) {
        return it->second;
    }

    return CameraProjectorPowerLevel::OtherCamera;
}


CameraProjectorAntiflicker getProjectorAntiflickerCameraType(const std::string& input) {
    static const std::unordered_map<std::string, CameraProjectorAntiflicker> antiFlickerCameraTypeMap = {
        {"Mech-Eye NANO", CameraProjectorAntiflicker::ProjectorAntiflickerCamera},
        {"Mech-Eye PRO M", CameraProjectorAntiflicker::ProjectorAntiflickerCamera},
        {"Mech-Eye PRO S", CameraProjectorAntiflicker::ProjectorAntiflickerCamera}
    };
    auto it = antiFlickerCameraTypeMap.find(input);
    if (it != antiFlickerCameraTypeMap.end()) {
        return it->second;
    }

    return CameraProjectorAntiflicker::OtherCamera;
}


CameraDepthSourceExposure getDepthSourceExposureCameraType(const std::string& input) {
    static const std::unordered_map<std::string, CameraDepthSourceExposure> depthSourceExposureMap = {
        {"Mech-Eye DEEP", CameraDepthSourceExposure::DepthSourceExposureCamera},
        {"Mech-Eye LSR L", CameraDepthSourceExposure::DepthSourceExposureCamera}
    };
    auto it = depthSourceExposureMap.find(input);
    if (it != depthSourceExposureMap.end()) {
        return it->second;
    }
    return CameraDepthSourceExposure::OtherCamera;
}

CameraProjectorCodingTranslucentMode getProjectorCodingTranslucentModeCameraType(const std::string& input) {
    static const std::unordered_map<std::string, CameraProjectorCodingTranslucentMode> translucentModeMap = {
        {"Mech-Eye PRO S", CameraProjectorCodingTranslucentMode::TranslucentModeCamera},
        {"Mech-Eye PRO M", CameraProjectorCodingTranslucentMode::TranslucentModeCamera}
    };
    auto it = translucentModeMap.find(input);
    if (it != translucentModeMap.end()) {
        return it->second;
    }
    return CameraProjectorCodingTranslucentMode::OtherCamera;
}


CameraCodingModeReflective getCodingModeReflectiveCameraType(const std::string& input) {
    static const std::unordered_map<std::string, CameraCodingModeReflective> reflectiveModeMap = {
    {"Mech-Eye PRO S", CameraCodingModeReflective::ReflectiveModeCamera},
    {"Mech-Eye PRO M", CameraCodingModeReflective::ReflectiveModeCamera}
    };
    auto it = reflectiveModeMap.find(input);
    if (it != reflectiveModeMap.end()) {
        return it->second;
    }
    return CameraCodingModeReflective::OtherCamera;
}

/*******************************************************************************************************************
*                                                                Function tool
*******************************************************************************************************************/

std::string CurrentTimeToString() {
    auto currentTime = std::chrono::system_clock::now();

    // Converts the current point in time to a time structure
    std::time_t currentTimeT = std::chrono::system_clock::to_time_t(currentTime);
    struct std::tm* currentTimeInfo = std::localtime(&currentTimeT);

    // Format the time as a string using the put time function
    std::ostringstream oss;
    oss << std::put_time(currentTimeInfo, "%Y-%m-%d %H:%M:%S");
    std::string formattedTimeStr = oss.str();
    return formattedTimeStr;
}

bool ExpectROIAlmostEqual(const mmind::eye::ROI& roi1, const mmind::eye::ROI& roi2) {
    if ((roi1.upperLeftX == roi2.upperLeftX) &&
        (roi1.upperLeftY == roi2.upperLeftY) &&
        (roi1.width == roi2.width) &&
        (roi1.height == roi2.height))
        return true;
    return false;
    // EXPECT_EQ(roi1.upperLeftX, roi1.upperLeftX) << "ROI differ at upperLeftX " << roi1.upperLeftX << "   " << roi2.upperLeftX;
    // EXPECT_EQ(roi1.upperLeftY, roi1.upperLeftY) << "ROI differ at upperLeftY " << roi1.upperLeftY << "   " << roi2.upperLeftY;
    // EXPECT_EQ(roi1.width, roi1.width) << "ROI differ at width " << roi1.width << "   " << roi2.width;
    // EXPECT_EQ(roi1.height, roi1.height) << "ROI differ at height " << roi1.height << "   " << roi2.height;
}

void ExpectVectorsAlmostEqual(const std::vector<double>& vec1, const std::vector<double>& vec2, double tolerance) {
    ASSERT_EQ(vec1.size(), vec2.size()) << "Vectors are of unequal length";

    for (size_t i = 0; i < vec1.size(); ++i) {
        EXPECT_NEAR(vec1[i], vec2[i], tolerance) << "Vectors differ at index " << i;
    }
}

void isIncludeUserSet(mmind::eye::UserSetManager& usm, const std::string& userSetName, bool flag) {
    std::vector<std::string> userSets;
    testStautsSuccessful(usm.getAllUserSetNames(userSets));
    bool found = std::find(userSets.begin(), userSets.end(), userSetName) != userSets.end();

    if (flag == found) {
        FAIL();
    }
}

void testStautsSuccessful(const mmind::eye::ErrorStatus& status, int code, std::string description) {
    EXPECT_EQ(status.errorCode, code);
    EXPECT_EQ(status.errorDescription, description);
}


void testStautsFailed(const mmind::eye::ErrorStatus& status, int code, std::string description) {
    EXPECT_NE(status.errorCode, code);
    EXPECT_NE(status.errorDescription, description);
}


/*******************************************************************************************************************
*                                                               Parameter validity  Test
*******************************************************************************************************************/

void testIntValue(mmind::eye::Camera& camera, const std::string& parameterName, const int& setValue) {
    // by name
    int getValue;
    testStautsSuccessful(camera.currentUserSet().setIntValue(parameterName, setValue));
    testStautsSuccessful(camera.currentUserSet().getIntValue(parameterName, getValue));
    EXPECT_EQ(setValue, getValue);
    std::cout << "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue << std::endl;

    // by child class
    int step, min, max;
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::IntParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    int getValue2;
    testStautsSuccessful(parameterValue->setValue(max - setValue + min));
    testStautsSuccessful(parameterValue->getValue(getValue2));
    EXPECT_EQ(max - setValue + min, getValue2);
    //std::cout << "setIntValue: " << max - setValue + min << "  ->  " << "getIntValue: " << getValue2 << std::endl;
}

void testDoubleValue(mmind::eye::Camera& camera, const std::string& parameterName, const double& setValue) {
    // by name

    double getValue;
    testStautsSuccessful(camera.currentUserSet().setFloatValue(parameterName, setValue));
    testStautsSuccessful(camera.currentUserSet().getFloatValue(parameterName, getValue));
    EXPECT_NEAR(setValue, getValue, 0.08);
    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    double step, min, max;
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::FloatParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    double getValue2;
    testStautsSuccessful(parameterValue->setValue(setValue));
    testStautsSuccessful(parameterValue->getValue(getValue2));
    EXPECT_NEAR(setValue, getValue2, 0.08);
    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue2 << std::endl;

}

void testDoubleValue(mmind::eye::Camera& camera, const std::string& parameterName, const double& setValue, const int& repeat) {

    for (int rep = 1; rep < repeat; ++rep)
    {
        // by name
        std::vector<double> getArrayValue;
        std::vector<double> setArrayValue(rep, setValue);
        testStautsSuccessful(camera.currentUserSet().setFloatArrayValue(parameterName, setArrayValue));
        testStautsSuccessful(camera.currentUserSet().getFloatArrayValue(parameterName, getArrayValue));
        ExpectVectorsAlmostEqual(setArrayValue, getArrayValue, 0.1);
    }

    // by child class
    double step, min, max;
    int asize;

    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::FloatArrayParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    parameterValue->getStep(step);
    parameterValue->getMin(min);
    parameterValue->getMax(max);
    parameterValue->getMaxArraySize(asize);
    for (int rep = 1; rep < repeat; ++rep)
    {
        std::vector<double> getArrayValue;
        std::vector<double> setArrayValue(rep, setValue);
        parameterValue->setValue(setArrayValue);
        parameterValue->getValue(getArrayValue);
        ExpectVectorsAlmostEqual(setArrayValue, getArrayValue, 0.1);
    }
}

void testEnumValue(mmind::eye::Camera& camera, const std::string& parameterName, const std::pair<std::string, int>& modePair) {

    //  Cannot merge the two for loops
    std::string getModeName;
    // set int
    testStautsSuccessful(camera.currentUserSet().setEnumValue(parameterName, modePair.second));
    // get string
    testStautsSuccessful(camera.currentUserSet().getEnumValue(parameterName, getModeName));
    EXPECT_EQ(getModeName, modePair.first);
    //std::cout << getModeName << "  ->  " << modePair.first << std::endl;


    int getModeValue;
    // set string
    testStautsSuccessful(camera.currentUserSet().setEnumValue(parameterName, modePair.first));
    // get int
    testStautsSuccessful(camera.currentUserSet().getEnumValue(parameterName, getModeValue));
    EXPECT_EQ(getModeValue, modePair.second);
    //std::cout << getModeValue << "  ->  " << modePair.second << std::endl;


    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    ////  Cannot merge the two for loops
    std::string getModeName1;
    // set int
    testStautsSuccessful(parameterValue->setValue(modePair.second));
    // get string
    testStautsSuccessful(parameterValue->getValue(getModeName1));
    EXPECT_EQ(getModeName1, modePair.first);
    //std::cout << getModeName1 << "  ->  " << modePair.first << std::endl;

    int getModeValue1;
    // set string
    testStautsSuccessful(parameterValue->setValue(modePair.first));
    // get int
    testStautsSuccessful(parameterValue->getValue(getModeValue1));
    EXPECT_EQ(getModeValue1, modePair.second);
    //std::cout << getModeValue1 << "  ->  " << modePair.second << std::endl;


    std::map<std::string, int> getValueList;
    testStautsSuccessful(parameterValue->getValues(getValueList));
    EXPECT_NE(getValueList.size(), 0);
}

void testBoolValue(mmind::eye::Camera& camera, const std::string& parameterName, const bool& setValue) {
    // by name
    bool getValue;
    testStautsSuccessful(camera.currentUserSet().setBoolValue(parameterName, setValue));
    testStautsSuccessful(camera.currentUserSet().getBoolValue(parameterName, getValue));
    EXPECT_EQ(setValue, getValue);
    //std::cout << "setBoolValue: " << setValue << "  ->  " << "getBoolValue: " << getValue << std::endl;

    // by child class
    bool getBoolValue;
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::BoolParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testStautsSuccessful(parameterValue->setValue(setValue));
    testStautsSuccessful(parameterValue->getValue(getBoolValue));
    EXPECT_EQ(setValue, getBoolValue);

    //std::cout << "setBoolValue: " << setValue << "  ->  " << "getBoolValue: " << getBoolValue << std::endl;

}

void testROIValue(mmind::eye::Camera& camera, const std::string& parameterName, const mmind::eye::ROI& setRoi) {
    // by name
    mmind::eye::ROI getRoi;
    testStautsSuccessful(camera.currentUserSet().setRoiValue(parameterName, setRoi));
    testStautsSuccessful(camera.currentUserSet().getRoiValue(parameterName, getRoi));
    //std::cout << "setROI: [" << setRoi.upperLeftX << "," << setRoi.upperLeftY << "," << setRoi.width << "," << setRoi.height << "]    ->    "
    //    << "getROI: [" << getRoi.upperLeftX << "," << getRoi.upperLeftY << "," << getRoi.width << "," << getRoi.height << "]"
    //    << std::endl;
    EXPECT_TRUE(ExpectROIAlmostEqual(setRoi, getRoi));

    // by child class
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::RoiParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    mmind::eye::ROI getRoiValue;
    testStautsSuccessful(parameterValue->setValue(setRoi));
    testStautsSuccessful(parameterValue->getValue(getRoiValue));
    EXPECT_TRUE(ExpectROIAlmostEqual(setRoi, getRoiValue));
    //std::cout << "setROI: [" << setRoi.upperLeftX << "," << setRoi.upperLeftY << "," << setRoi.width << "," << setRoi.height << "]    ->    "
    //    << "getROI: [" << getRoiValue.upperLeftX << "," << getRoiValue.upperLeftY << "," << getRoiValue.width << "," << getRoiValue.height << "]"
    //    << std::endl;
}

void testRangeValue(mmind::eye::Camera& camera, const std::string& parameterName, const int& setValue, const int& winSize) {
    // TestCase: 1 -> setValue + 1
    mmind::eye::Range<int> setRange(1, setValue + 1), getRange;
    testStautsSuccessful(camera.currentUserSet().setRangeValue(parameterName, setRange));
    testStautsSuccessful(camera.currentUserSet().getRangeValue(parameterName, getRange));
    EXPECT_EQ(setRange.min, getRange.min);
    EXPECT_EQ(setRange.max, getRange.max);
    //std::cout << "setRange:  [" << setRange.min << "," << setRange.max << "]  ->  "
    //    << "getRange:  [" << getRange.min << "," << getRange.max << "]"
    //    << std::endl;


    // by child class
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<mmind::eye::RangeParameter*>(parameter);
    if (!parameterValue)
        FAIL();


    int getStep, getMin, getMax;
    std::string getUnit;
    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    mmind::eye::Range<int> setRange1(1, getMax + 1 - setValue), getRange1;
    testStautsSuccessful(parameterValue->setValue(setRange1));
    testStautsSuccessful(parameterValue->getValue(getRange1));

    //std::cout << "setRange:  [" << setRange1.min << "," << setRange1.max << "]  ->  "
    //    << "getRange:  [" << getRange1.min << "," << getRange1.max << "]"
    //    << std::endl;

    // TestCase: slide windows, window width = winSize
    if ((setValue + winSize) <= 5000) {
        mmind::eye::Range<int> setRange(setValue, setValue + winSize), getRange;
        testStautsSuccessful(camera.currentUserSet().setRangeValue(parameterName, setRange));
        testStautsSuccessful(camera.currentUserSet().getRangeValue(parameterName, getRange));
        EXPECT_EQ(setRange.min, getRange.min);
        EXPECT_EQ(setRange.max, getRange.max);
        //std::cout << "setRange:  [" << setRange.min << "," << setRange.max << "]  ->  "
        //    << "getRange:  [" << getRange.min << "," << getRange.max << "]"
        //    << std::endl;


        mmind::eye::Range<int> setRange1(getMax - setValue - winSize + 1, getMax - setValue + 1), getRange1;
        testStautsSuccessful(parameterValue->setValue(setRange1));
        testStautsSuccessful(parameterValue->getValue(getRange1));

        //std::cout << "setRange:  [" << setRange1.min << "," << setRange1.max << "]  ->  "
        //    << "getRange:  [" << getRange1.min << "," << getRange1.max << "]"
        //    << std::endl;
    }


}



/*******************************************************************************************************************
*                                                         Parameter Attribute Test
*******************************************************************************************************************/
void testIntParameterAttribute(mmind::eye::Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<mmind::eye::IntParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    int getStep, getMin, getMax;
    std::string getUnit;
    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);

}

void testDoubleParameterAttribute(mmind::eye::Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<mmind::eye::FloatParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    double getStep, getMin, getMax;
    std::string getUnit;

    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);

}

void testDoubleArrayParameterAttribute(mmind::eye::Parameter* parameter, const double& step, const double& min, const double& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<mmind::eye::FloatArrayParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    double getStep, getMin, getMax;
    std::string getUnit;

    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);
}

void testEnumParameterAttribute(mmind::eye::Parameter* parameter, const int& mapSize, const std::vector<std::string>& modes) {
    auto* parameterValue = dynamic_cast<mmind::eye::EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    std::map<std::string, int> valueList;
    testStautsSuccessful(parameterValue->getValues(valueList));
    EXPECT_EQ(valueList.size(), mapSize);

    std::vector<std::string> modeVec;
    for (const auto& gPair : valueList) {
        if (std::find(modes.begin(), modes.end(), gPair.first) != modes.end())
            SUCCEED();
        else
            FAIL();
    }
}

void testRoiParameterAttribute(mmind::eye::Parameter* parameter, const int& maxWidth, const int& maxHeight) {
    auto* parameterValue = dynamic_cast<mmind::eye::RoiParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    mmind::eye::Size maxSize;
    testStautsSuccessful(parameterValue->getMaxRoiSize(maxSize));
    EXPECT_EQ(maxSize.width, maxWidth);
    EXPECT_EQ(maxSize.height, maxHeight);
}

void testRangeArrayParameterAttribute(mmind::eye::Parameter* parameter, const int& step, const int& min, const int& max, const std::string& unit) {
    auto* parameterValue = dynamic_cast<mmind::eye::RangeParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    int getStep, getMin, getMax;
    std::string getUnit;

    testStautsSuccessful(parameterValue->getStep(getStep));
    testStautsSuccessful(parameterValue->getMin(getMin));
    testStautsSuccessful(parameterValue->getMax(getMax));
    testStautsSuccessful(parameterValue->getUnit(getUnit));

    EXPECT_EQ(getStep, step);
    EXPECT_EQ(getMin, min);
    EXPECT_EQ(getMax, max);
    EXPECT_EQ(getUnit, unit);
}


mmind::eye::Parameter* testParameterAttribute(mmind::eye::Camera& camera, const std::string& parameterName,
    const mmind::eye::Parameter::Type& pType, const int& readFlag, const int& writeFlag)
{

    auto* parameter = camera.currentUserSet().getParameter(parameterName);

    EXPECT_EQ(parameter->name(), parameterName);
    EXPECT_NE(parameter->description(), "");
    EXPECT_EQ(parameter->isReadable(), readFlag);
    EXPECT_EQ(parameter->isWritable(), writeFlag);

    switch (parameter->type())
    {
    case mmind::eye::Parameter::Type::_Int:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_Int);
        break;
    case mmind::eye::Parameter::Type::_Float:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_Float);
        break;
    case mmind::eye::Parameter::Type::_Bool:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_Bool);
        break;
    case mmind::eye::Parameter::Type::_Enum:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_Enum);
        break;
    case mmind::eye::Parameter::Type::_Roi:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_Roi);
        break;
    case mmind::eye::Parameter::Type::_Range:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_Range);
        break;
    case mmind::eye::Parameter::Type::_FloatArray:
        EXPECT_EQ(pType, mmind::eye::Parameter::Type::_FloatArray);
        break;
    default:
        break;
    }
    return parameter;
}



/*******************************************************************************************************************
*                                                               Parameter invalidity  Test
*******************************************************************************************************************/
void testInvalidIntValue(mmind::eye::Camera& camera, const std::string& parameterName, const int& setValue, const mmind::eye::ErrorStatus::ErrorCode& code) {
    // by name
    int getValue;
    EXPECT_EQ(camera.currentUserSet().setIntValue(parameterName, setValue).errorCode, code);
    EXPECT_EQ(camera.currentUserSet().getIntValue(parameterName, getValue).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    EXPECT_NE(setValue, getValue);
    //std::cout << "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue << std::endl;

    // by child class
    int step, min, max;
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);

    auto* parameterValue = dynamic_cast<mmind::eye::IntParameter*>(parameter);
    EXPECT_TRUE(parameterValue);

    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    int getValue2;
    EXPECT_EQ(parameterValue->setValue(setValue).errorCode, code);
    EXPECT_EQ(parameterValue->getValue(getValue2).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    EXPECT_NE(setValue, getValue2);
    //std::cout << "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue2 << std::endl;
    
}

void testInvalidDoubleValue(mmind::eye::Camera& camera, const std::string& parameterName, const double& setValue , const mmind::eye::ErrorStatus::ErrorCode& code) {
    // by name
    double getValue;
    EXPECT_EQ(camera.currentUserSet().setFloatValue(parameterName, setValue).errorCode, code);
    EXPECT_EQ(camera.currentUserSet().getFloatValue(parameterName, getValue).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    EXPECT_NE(setValue, getValue);
    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    double step, min, max;
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);


    auto* parameterValue = dynamic_cast<mmind::eye::FloatParameter*>(parameter);
    EXPECT_TRUE(parameterValue);


    testStautsSuccessful(parameterValue->getStep(step));
    testStautsSuccessful(parameterValue->getMin(min));
    testStautsSuccessful(parameterValue->getMax(max));

    double getValue2;
    EXPECT_EQ(parameterValue->setValue(setValue).errorCode, code);
    EXPECT_EQ(parameterValue->getValue(getValue2).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    EXPECT_NE(setValue, getValue2);
    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue2 << std::endl;

}

void testInvalidDoubleArrayValue(mmind::eye::Camera& camera, const std::string& parameterName, const std::vector<double>& setArrayValue, const mmind::eye::ErrorStatus::ErrorCode& code) {
    // by name
    std::vector<double> getArrayValue;
    EXPECT_EQ(camera.currentUserSet().setFloatArrayValue(parameterName, setArrayValue).errorCode, code);
    EXPECT_EQ(camera.currentUserSet().getFloatArrayValue(parameterName, getArrayValue).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);


    // by child class
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);


    auto* parameterValue = dynamic_cast<mmind::eye::FloatArrayParameter*>(parameter);
    EXPECT_TRUE(parameterValue);


    EXPECT_EQ(parameterValue->setValue(setArrayValue).errorCode, code);
    EXPECT_EQ(parameterValue->getValue(getArrayValue).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
}



void testInvalidEnumValue(mmind::eye::Camera& camera, const std::string& parameterName, const std::pair<std::string, int>& setValueList, const mmind::eye::ErrorStatus::ErrorCode& code) {
    int getModeValue;
    std::string getModeString;
    // set string
    EXPECT_EQ(camera.currentUserSet().setEnumValue(parameterName, setValueList.first).errorCode, code);
    // get string
    EXPECT_EQ(camera.currentUserSet().getEnumValue(parameterName, getModeString).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS) ;
    // set int
    EXPECT_EQ(camera.currentUserSet().setEnumValue(parameterName, setValueList.second).errorCode, code)  << "Enum: " << setValueList.second;
    // get int
    EXPECT_EQ(camera.currentUserSet().getEnumValue(parameterName, getModeValue).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);

    EXPECT_NE(getModeString, setValueList.first);
    EXPECT_NE(getModeValue, setValueList.second);
    //std::cout << "Invalid:    " << getModeString << "  ->  " << setValueList.first << std::endl;
    //std::cout << "Invalid:    " << getModeValue << "  ->  " << setValueList.second << std::endl;

    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);

    auto* parameterValue = dynamic_cast<mmind::eye::EnumParameter*>(parameter);
    EXPECT_TRUE(parameterValue);

    // set string
    EXPECT_EQ(parameterValue->setValue(setValueList.first).errorCode, code);
    // get string
    EXPECT_EQ(parameterValue->getValue(getModeString).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    // set int
    EXPECT_EQ(parameterValue->setValue(setValueList.second).errorCode, code) << "Enum: " << setValueList.second;
    // get int
    EXPECT_EQ(parameterValue->getValue(getModeValue).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);

    EXPECT_NE(getModeString, setValueList.first);
    EXPECT_NE(getModeValue, setValueList.second);

    //std::cout << getModeValue << "  ->  " << setValueList.second << std::endl;
}


void testInvalidROIValue(mmind::eye::Camera& camera, const std::string& parameterName, const mmind::eye::ROI& setRoi, const mmind::eye::ErrorStatus::ErrorCode& code) {

    // by name
    mmind::eye::ROI getRoi;
    EXPECT_EQ(camera.currentUserSet().setRoiValue(parameterName, setRoi).errorCode, code);
    EXPECT_EQ(camera.currentUserSet().setRoiValue(parameterName, getRoi).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    EXPECT_FALSE(ExpectROIAlmostEqual(setRoi, getRoi));

    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);

    auto* parameterValue = dynamic_cast<mmind::eye::RoiParameter*>(parameter);
    EXPECT_TRUE(parameterValue);

    mmind::eye::ROI getRoi1;
    EXPECT_EQ(parameterValue->setValue(setRoi).errorCode, code);  // use match
    EXPECT_EQ(parameterValue->getValue(getRoi1).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
    EXPECT_FALSE(ExpectROIAlmostEqual(setRoi, getRoi1));
}


void testInvalidRangeValue(mmind::eye::Camera& camera, const std::string& parameterName, const mmind::eye::Range<int>& setRange, const mmind::eye::ErrorStatus::ErrorCode& code) {

    // by name
    mmind::eye::Range<int> getRange;
    EXPECT_EQ(camera.currentUserSet().setRangeValue(parameterName, setRange).errorCode, code);
    EXPECT_EQ(camera.currentUserSet().getRangeValue(parameterName, getRange).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);


    auto* parameter = camera.currentUserSet().getParameter(parameterName);
    EXPECT_TRUE(parameter);


    auto* parameterValue = dynamic_cast<mmind::eye::RangeParameter*>(parameter);
    EXPECT_TRUE(parameterValue);

    EXPECT_EQ(parameterValue->setValue(setRange).errorCode, code);
    EXPECT_EQ(parameterValue->getValue(getRange).errorCode, mmind::eye::ErrorStatus::ErrorCode::MMIND_STATUS_SUCCESS);
}