#pragma once
#include <iostream>
#include "gtest/gtest.h"
#include "ReadConfigFile.h"
#include "profiler/VirtualProfiler.h"
#include "profiler/Profiler.h"
#include "area_scan_3d_camera/Camera.h"

extern std::string global_ip_address;
extern mmind::eye::Camera globalCamera;
extern mmind::eye::Profiler globalProfiler;

void ParseCommandLine(int argc, char** argv);


// Camera 3d test fixture
class CameraSDKFixture : public ::testing::Test {

protected:
    CameraSDKFixture();
    ~CameraSDKFixture();

    void SetUp() override;
    //void TearDown() override;

protected:
    mmind::eye::Camera camera;

    std::string modelName;
    int colorWidthResolution;
    int colorHeightResolution;
    int depthWidthResolution;
    int depthHeightResolution;
};


// Profiler test fixture
class ProfilerSDKFixture : public ::testing::Test {

protected:
    ProfilerSDKFixture();
    ~ProfilerSDKFixture();

    void SetUp() override;
    //void TearDown() override;
protected:
    mmind::eye::Profiler profiler;

    std::string modelName;
};



// Profiler virtual test fixture
class ProVirtualSDKFixture:public ::testing::Test
{
public:
	const std::string jsonPath = R"(resource/device_type.json)";
	
};

