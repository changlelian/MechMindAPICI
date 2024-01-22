#include <cstdlib>
#include <string>
#include <unordered_set>
#include "area_scan_3d_camera/Camera.h"
#include "profiler/Profiler.h"
#include <algorithm>
#include <chrono>



void upgrade(std::string& ipAddress) {

        std::cout <<"===============IP: " << ipAddress << " is upgrading===============" << std::endl;
        std::string update = "/opt/mech-mind/mech-eye-sdk/bin/firmware_upgrader -h " + ipAddress + " -z /opt/mech-mind/mech-eye-sdk/resource/mmind_eye_v2.3.0.zip";
        system(update.c_str());
}


bool verifyRefind(std::vector<std::string>& ipAddressArr, const std::chrono::high_resolution_clock::time_point& startTime) {

    while (ipAddressArr.size()) {
        const auto endTime = std::chrono::high_resolution_clock::now();

        std::vector<mmind::eye::CameraInfo>cameraInfos = mmind::eye::Camera::discoverCameras();
        std::vector<mmind::eye::ProfilerInfo>profileInfos = mmind::eye::Profiler::discoverProfilers();

        for (auto& cam : cameraInfos)
            ipAddressArr.erase(std::remove(ipAddressArr.begin(), ipAddressArr.end(), cam.ipAddress), ipAddressArr.end());
    
        for (auto& prof : profileInfos)
            ipAddressArr.erase(std::remove(ipAddressArr.begin(), ipAddressArr.end(), prof.ipAddress), ipAddressArr.end());


        auto timeSpend = std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime).count();
        std::cout << "Finding device: [ ";
        for (auto& arr : ipAddressArr) { std::cout << arr << ", "; }
        std::cout << " ] has been taken " << timeSpend << " s" << std::endl;

        if (timeSpend >= 300)   // 5 * 60s 
        {
            std::cerr << "[Upgrade Error]  The mech eye device not be found . please check the upgrade program." << std::endl;
            return false;
        }

    }

    return ipAddressArr.size() == 0;
}

int main(int argc, char** argv) {
    const std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();
    std::vector<std::string> ipAddressArr(argc - 1);

    for (int i = 1; i < argc; ++i) {
        ipAddressArr[i - 1] = argv[i];
        std::string ipAddress(argv[i]);
        upgrade(ipAddress);
    }
    verifyRefind(ipAddressArr, startTime);
    return 0;
}