#include "ProfilerVirtualFixture.h"
#include "ProfilerVirtualFunction.h"

TEST_F(ProVirtualSDKFixture, GetProVirtualInfo) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0 , "mraw_path");
    std::cout << mrawPath << std::endl;

    mmind::eye::VirtualProfiler profiler(mrawPath);
    mmind::eye::ProfilerInfo info;
    auto stautus = profiler.getProfilerInfo(info);

    EXPECT_EQ(info.model, jsonfile.getJsonValue("mraw", 1, "model_name"));
    EXPECT_EQ(info.controllerSN, jsonfile.getJsonValue("mraw", 2, "controller_sn"));
    EXPECT_EQ(info.sensorSN, jsonfile.getJsonValue("mraw", 3, "sensor_sn"));
    EXPECT_EQ(info.hardwareVersion.toString(), jsonfile.getJsonValue("mraw", 4, "hardware_version"));
    EXPECT_EQ(info.firmwareVersion.toString(), jsonfile.getJsonValue("mraw", 5, "firmware_version"));
    EXPECT_EQ(info.ipAddress, jsonfile.getJsonValue("mraw", 6, "ip_address"));
    EXPECT_EQ(ipAssignmentMethodToString(info.ipAssignmentMethod), jsonfile.getJsonValue("mraw", 7, "ip_method"));
    EXPECT_EQ(std::to_string(info.port), jsonfile.getJsonValue("mraw", 8, "port"));
}

TEST_F(ProVirtualSDKFixture, GetCurrentUserSetName) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    std::cout << mrawPath << std::endl;
    mmind::eye::VirtualProfiler profiler(mrawPath);

    std::string virtualUserSetName;
    mmind::eye::VirtualUserSet virtualUserSet = profiler.currentUserSet();
    virtualUserSet.getName(virtualUserSetName);

    EXPECT_EQ(virtualUserSetName , jsonfile.getJsonValue("mraw", 9, "user_set_name"));
}



TEST_F(ProVirtualSDKFixture, GetAvailableParameterNames) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    std::cout << mrawPath << std::endl;
    mmind::eye::VirtualProfiler profiler(mrawPath);

    std::vector<std::string> parameterArrayNames;
    mmind::eye::VirtualUserSet virtualUserSet = profiler.currentUserSet();
    virtualUserSet.getAvailableParameterNames(parameterArrayNames);

    EXPECT_NE(parameterArrayNames.size(), 0);
}


TEST_F(ProVirtualSDKFixture, GetParameters) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    std::cout << mrawPath << std::endl;
    mmind::eye::VirtualProfiler profiler(mrawPath);

    std::vector<std::string> parameterArrayNames;
    mmind::eye::VirtualUserSet virtualUserSet = profiler.currentUserSet();
    virtualUserSet.getAvailableParameterNames(parameterArrayNames);

    for (auto& parameterName : parameterArrayNames) {
        std::cout << parameterName << std::endl;
        mmind::eye::Parameter* parameter = virtualUserSet.getParameter(parameterName);

        EXPECT_NE(parameter->name(), "");
        EXPECT_NE(parameter->description(), "");
        EXPECT_FALSE(parameter->isWritable());
        EXPECT_TRUE(parameter->isReadable());
    }
}


TEST_F(ProVirtualSDKFixture, IntParameters) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    mmind::eye::VirtualProfiler profiler(mrawPath);
    testIntValue(profiler, "CallbackRetrievalTimeout");
}

TEST_F(ProVirtualSDKFixture, FloatParameters) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    mmind::eye::VirtualProfiler profiler(mrawPath);
    testFloatValue(profiler, "HeightCorrectionRatio");
}

TEST_F(ProVirtualSDKFixture, BoolParameters) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    mmind::eye::VirtualProfiler profiler(mrawPath);
    testBoolValue(profiler, "MedianFilterWindowSize");
}

