#include "profiler/ProfilerFunction.h"



 ProfilerType JudgeProfilerType(mmind::eye::Profiler& profiler) {
     mmind::eye::ProfilerInfo info;
     profiler.getProfilerInfo(info);
     if (info.model == "Mech-Eye LNX 8300")
         return ProfilerType::LNX_8300;
     else if (info.model == "Mech-Eye LNX-8030")
         return ProfilerType::LNX_8030;
     else if (info.model == "Mech-Eye LNX 8080")
         return ProfilerType::LNX_8080;
     else
         return ProfilerType::UnkonwType;
 }



void testProStautsSuccessful(const ErrorStatus& status, int code, std::string description, bool isMatch) {
    EXPECT_EQ(status.errorCode, code);
    if (isMatch) {
        EXPECT_EQ(status.errorDescription, description)<< "SDK ErrorDescription: "<< status.errorDescription << std::endl;
    } else{
        EXPECT_EQ(status.errorDescription.substr(0,20), description) << "SDK ErrorDescription: "<< status.errorDescription << std::endl;
    }
}


void testProStautsFailed(const ErrorStatus& status, int code, std::string description) {
    EXPECT_NE(status.errorCode, code);
    EXPECT_NE(status.errorDescription, description);
}

/*******************************************************************************************************************
*                                                                Valid Parameter Test
*******************************************************************************************************************/

// test int value [start value: 0]
void testIntValue(mmind::eye::Profiler& profiler, const std::string& parameterName, const int& setValue) {
    // by name
    int getValue;
    testProStautsSuccessful(profiler.currentUserSet().setIntValue(parameterName, setValue));
    testProStautsSuccessful(profiler.currentUserSet().getIntValue(parameterName, getValue));
    EXPECT_EQ(setValue, getValue);
    //std::cout <<"["<<parameterName<<"]:  "<< "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue << std::endl;
    
    // by child class
    int step, min, max;
    auto* parameter = profiler.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<IntParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testProStautsSuccessful(parameterValue->getStep(step));
    testProStautsSuccessful(parameterValue->getMin(min));
    testProStautsSuccessful(parameterValue->getMax(max));

    int getValue2;
    testProStautsSuccessful(parameterValue->setValue(setValue));
    testProStautsSuccessful(parameterValue->getValue(getValue2));
    EXPECT_EQ(setValue, getValue2);
    //std::cout <<"["<<parameterName<<"]:  "<< "setIntValue: " << setValue << "  ->  " << "getIntValue: " << getValue2 << std::endl;

}


// test LaserLineWidthint value [start value: 0]
void testIntValue(mmind::eye::Profiler& profiler, const std::string& parameterName1, const std::string& parameterName2, const int& setValue1, const int& setValue2) {
    // by name
    int getValue1;
    testProStautsSuccessful(profiler.currentUserSet().setIntValue(parameterName1, setValue1));
    testProStautsSuccessful(profiler.currentUserSet().getIntValue(parameterName1, getValue1));
    EXPECT_EQ(setValue1, getValue1);
    //std::cout <<"["<<parameterName1<<"]:  "<< "setIntValue1: " << setValue1 << "  ->  " << "getIntValue1: " << getValue1 << std::endl;

    int getValue2;
    testProStautsSuccessful(profiler.currentUserSet().setIntValue(parameterName2, setValue2));
    testProStautsSuccessful(profiler.currentUserSet().getIntValue(parameterName2, getValue2));
    EXPECT_EQ(setValue2, getValue2);
    //std::cout <<"["<<parameterName2<<"]:  "<< "setIntValue2: " << setValue2 << "  ->  " << "getIntValue2: " << getValue2 << std::endl;

    
    // by child class
    int step1, min1, max1;
    auto* parameter1 = profiler.currentUserSet().getParameter(parameterName1);
    if (!parameter1)
        FAIL();

    auto* parameterValue1 = dynamic_cast<IntParameter*>(parameter1);
    if (!parameterValue1)
        FAIL();

    testProStautsSuccessful(parameterValue1->getStep(step1));
    testProStautsSuccessful(parameterValue1->getMin(min1));
    testProStautsSuccessful(parameterValue1->getMax(max1));

    int getChileValue1;
    testProStautsSuccessful(parameterValue1->setValue(setValue1));
    testProStautsSuccessful(parameterValue1->getValue(getChileValue1));
    EXPECT_EQ(setValue1, getChileValue1);
    //std::cout <<"["<<parameterName1<<"]:  "<< "setIntValue: " << setValue1 << "  ->  " << "getIntValue: " << getChileValue1 << std::endl;

    int step2, min2, max2;
    auto* parameter2 = profiler.currentUserSet().getParameter(parameterName2);
    if (!parameter2)
        FAIL();

    auto* parameterValue2 = dynamic_cast<IntParameter*>(parameter2);
    if (!parameterValue2)
        FAIL();

    testProStautsSuccessful(parameterValue2->getStep(step2));
    testProStautsSuccessful(parameterValue2->getMin(min2));
    testProStautsSuccessful(parameterValue2->getMax(max2));

    int getChileValue2;
    testProStautsSuccessful(parameterValue2->setValue(setValue2));
    testProStautsSuccessful(parameterValue2->getValue(getChileValue2));
    EXPECT_EQ(setValue2, getChileValue2);
    //std::cout <<"["<<parameterName2<<"]:  "<< "setIntValue: " << setValue2 << "  ->  " << "getIntValue: " << getChileValue2 << std::endl << std::endl;


}


// Test double value  [start value: 0.1]
void testDoubleValue(mmind::eye::Profiler& profiler, const std::string& parameterName, const double& setValue) {
    // by name
    double getValue;
    testProStautsSuccessful(profiler.currentUserSet().setFloatValue(parameterName, setValue));
    testProStautsSuccessful(profiler.currentUserSet().getFloatValue(parameterName, getValue));
    EXPECT_NEAR(setValue, getValue, 0.99);
    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue << std::endl;

    // by child class
    double step, min, max;
    auto* parameter = profiler.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<FloatParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    testProStautsSuccessful(parameterValue->getStep(step));
    testProStautsSuccessful(parameterValue->getMin(min));
    testProStautsSuccessful(parameterValue->getMax(max));

    double getValue2;
    testProStautsSuccessful(parameterValue->setValue(setValue));
    testProStautsSuccessful(parameterValue->getValue(getValue2));
    EXPECT_NEAR(setValue, getValue2, 0.99);
    //std::cout << "setDoubleValue: " << setValue << "  ->  " << "getDoubleValue: " << getValue2 << std::endl;

}

// Test Enum value  
void testEnumValue(mmind::eye::Profiler& profiler, const std::string& parameterName, const std::pair<std::string, int>& modePair) {

    std::string getModeName;
    // set int
    testProStautsSuccessful(profiler.currentUserSet().setEnumValue(parameterName, modePair.second));
    // get string
    testProStautsSuccessful(profiler.currentUserSet().getEnumValue(parameterName, getModeName));
    EXPECT_EQ(getModeName, modePair.first);
    //std::cout << getModeName << "  ->  " << modePair.first << std::endl;


    int getModeValue;
    // set string
    testProStautsSuccessful(profiler.currentUserSet().setEnumValue(parameterName, modePair.first));
    // get int
    testProStautsSuccessful(profiler.currentUserSet().getEnumValue(parameterName, getModeValue));
    EXPECT_EQ(getModeValue, modePair.second);
    //std::cout << getModeValue << "  ->  " << modePair.second << std::endl;

   
    auto* parameter = profiler.currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

    //  Cannot merge the two for loops
    std::string getModeName1;
    // set int
    testProStautsSuccessful(parameterValue->setValue(modePair.second));
    // get string
    testProStautsSuccessful(parameterValue->getValue(getModeName1));
    EXPECT_EQ(getModeName1, modePair.first);
    //std::cout << getModeName1 << "  ->  " << modePair.first << std::endl;


    int getModeValue1;
    // set string
    testProStautsSuccessful(parameterValue->setValue(modePair.first));
    // get int
    testProStautsSuccessful(parameterValue->getValue(getModeValue1));
    EXPECT_EQ(getModeValue1, modePair.second);
    //std::cout << getModeValue1 << "  ->  " << modePair.second << std::endl;


    std::map<std::string, int> getValueList;
    testProStautsSuccessful(parameterValue->getValues(getValueList));
    EXPECT_NE(getValueList.size(), 0);

}



/*
// Test invalid Enum value
void testInvalidValue(mmind::eye::Camera* camera, const std::string& parameterName, const std::map<std::string, int>& setValueList,
                                   const int& setCode,  const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription)
{
    for (const auto& modePair : setValueList) {

        int getModeValue;
        std::string getModeString;
        // set string
        testProStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.first), setCode, setDescription);
        // get string
        testProStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeString), getCode, getDescription);
        // set int
        testProStautsSuccessful(camera->currentUserSet().setEnumValue(parameterName, modePair.second), setCode, setDescription);
        // get int
        testProStautsSuccessful(camera->currentUserSet().getEnumValue(parameterName, getModeValue), getCode, getDescription);

        EXPECT_NE(getModeString, modePair.first);
        EXPECT_NE(getModeValue, modePair.second);
        std::cout << "Invalid:    " << getModeString << "  ->  " << modePair.first << std::endl;
        std::cout << "Invalid:    " << getModeValue << "  ->  " << modePair.second << std::endl;

    }

    auto* parameter = camera->currentUserSet().getParameter(parameterName);
    if (!parameter)
        FAIL();

    auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
    if (!parameterValue)
        FAIL();

   
    for (const auto& modePair : setValueList) {
        int getModeValue;
        std::string getModeString;

        // set string
        testProStautsSuccessful(parameterValue->setValue(modePair.first), setCode, setDescription);
        // get string
        testProStautsSuccessful(parameterValue->getValue(getModeString), getCode, getDescription);
        // set int
        testProStautsSuccessful(parameterValue->setValue(modePair.second), setCode, setDescription);
        // get int
        testProStautsSuccessful(parameterValue->getValue(getModeValue), getCode, getDescription);

        EXPECT_NE(getModeString, modePair.first);
        EXPECT_NE(getModeValue, modePair.second);

        std::cout << getModeValue << "  ->  " << modePair.second << std::endl;

    }

    std::map<std::string, int> getValueList;
    testProStautsSuccessful(parameterValue->getValues(getValueList));
    EXPECT_NE(getValueList, setValueList);
   
}

*/

// Test invalid Enum value
void testInvalidValue(mmind::eye::Profiler* profiler, const std::string& parameterName, const std::pair<std::string, int>& setValueList,
                                   const int& setCode, const std::string& setDescription,
                                   const int& getCode, const std::string& getDescription,
                                   const bool& otherCameraFlag)
{
    int getModeValue;
    std::string getModeString;
    // set string
    testProStautsSuccessful(profiler->currentUserSet().setEnumValue(parameterName, setValueList.first), setCode, setDescription, true);
    // get string
    testProStautsSuccessful(profiler->currentUserSet().getEnumValue(parameterName, getModeString), getCode, getDescription, true);
    // set int
    testProStautsSuccessful(profiler->currentUserSet().setEnumValue(parameterName, setValueList.second), setCode, setDescription, true);
    // get int
    testProStautsSuccessful(profiler->currentUserSet().getEnumValue(parameterName, getModeValue), getCode, getDescription, true);

    EXPECT_NE(getModeString, setValueList.first);
    EXPECT_NE(getModeValue, setValueList.second);
    //std::cout << "Invalid:    " << getModeString << "  ->  " << setValueList.first << std::endl;
    //std::cout << "Invalid:    " << getModeValue << "  ->  " << setValueList.second << std::endl;


    auto* parameter = profiler->currentUserSet().getParameter(parameterName);

    if (!otherCameraFlag)
        EXPECT_FALSE(parameter);
    else {
        if (!parameter)
            FAIL();

        auto* parameterValue = dynamic_cast<EnumParameter*>(parameter);
        if (!parameterValue)
            FAIL();



        // set string
        testProStautsSuccessful(parameterValue->setValue(setValueList.first), setCode, setDescription, true);
        // get string
        testProStautsSuccessful(parameterValue->getValue(getModeString), getCode, getDescription, true);
        // set int
        testProStautsSuccessful(parameterValue->setValue(setValueList.second), setCode, setDescription, true);
        // get int
        testProStautsSuccessful(parameterValue->getValue(getModeValue), getCode, getDescription, true);

        EXPECT_NE(getModeString, setValueList.first);
        EXPECT_NE(getModeValue, setValueList.second);

        //std::cout << getModeValue << "  ->  " << setValueList.second << std::endl;
    }
}

