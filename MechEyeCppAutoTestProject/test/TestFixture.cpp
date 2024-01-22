#include "TestFixture.h"

// Declare global variables
std::string globalIpAddress;
mmind::eye::Camera globalCamera;
mmind::eye::Profiler globalProfiler;


// read from console
void ParseCommandLine(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (arg.find("--ip=") == 0) {
            globalIpAddress = arg.substr(5); 
            break;
        }
    }

    mmind::eye::Camera camera;
    mmind::eye::Profiler profiler;
    auto cameraStatus = camera.connect(globalIpAddress);
    auto profilerStatus = profiler.connect(globalIpAddress);

    if (cameraStatus.isOK()) {
        globalCamera = camera;
        std::cout << "Camera connect successfully. " << std::endl;
    }
    else if (profilerStatus.isOK()) {
        globalProfiler = profiler;
        std::cout << "Profiler connect successfully. " << std::endl;
    }
    else
    {
        std::cerr << "Mech eye connect faild. Please check the device network.";
        exit(-1);
    }
}



CameraSDKFixture::CameraSDKFixture() {
    this->camera = globalCamera;

    mmind::eye::CameraInfo info;
    this->camera.getCameraInfo(info);
    this->modelName = info.model;
    std::cout << ">>>>>" << info.model << std::endl;

    mmind::eye::CameraResolutions resolution;
    this->camera.getCameraResolutions(resolution);
    colorWidthResolution = resolution.texture.width;
    colorHeightResolution = resolution.texture.height;
    depthWidthResolution = resolution.depth.width;
    depthHeightResolution = resolution.depth.height;
}


void CameraSDKFixture::SetUp() {
    camera.currentUserSet().resetAllParametersToDefaultValues();
}

 CameraSDKFixture::~CameraSDKFixture() {
}


 ProfilerSDKFixture::ProfilerSDKFixture() {
     this->profiler = globalProfiler;

     mmind::eye::ProfilerInfo info;
     profiler.getProfilerInfo(info);
     this->modelName = info.model;
     std::cout << ">>>>>" << info.model << std::endl;

 }

 void ProfilerSDKFixture::SetUp() {
     profiler.currentUserSet().resetAllParametersToDefaultValues();
 }

 ProfilerSDKFixture::~ProfilerSDKFixture() {
 }

