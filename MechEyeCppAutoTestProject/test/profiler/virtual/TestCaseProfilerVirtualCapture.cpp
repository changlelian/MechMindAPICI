#include <mutex>
#include "ProfilerVirtualFixture.h"
#include "ProfilerVirtualFunction.h"
#include "profiler/parameters/ScanParameters.h"

TEST_F(ProVirtualSDKFixture, CaptureByPolling) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0 , "mraw_path");
    std::cout << mrawPath << std::endl;

    mmind::eye::VirtualProfiler profiler(mrawPath);
    mmind::eye::VirtualUserSet currentUserSet = profiler.currentUserSet();

    auto statusStop = profiler.stopAcquisition();
    testErrorStatusSuccessful(statusStop);

    auto statusStart = profiler.startAcquisition();
    testErrorStatusSuccessful(statusStart);

    int captureLineCount = 0, dataPoints = 0;;
    auto statusDataPoints = currentUserSet.getIntValue(mmind::eye::scan_settings::DataPointsPerProfile::name, dataPoints);
    testErrorStatusSuccessful(statusDataPoints);

    auto statusLineCount = currentUserSet.getIntValue(mmind::eye::scan_settings::ScanLineCount::name,  captureLineCount);
    testErrorStatusSuccessful(statusLineCount);

    mmind::eye::ProfileBatch profileBatch(dataPoints);

    while (profileBatch.height() < captureLineCount) {
        mmind::eye::ProfileBatch batch(dataPoints);
        auto status = profiler.retrieveBatchData(batch);
        testErrorStatusSuccessful(status);

        if (!profileBatch.append(batch))
            break;
    }
   
    EXPECT_FALSE(profileBatch.isEmpty());
}

std::mutex kMutex;

void callbackFunc(const mmind::eye::ProfileBatch& batch, void* pUser)
{
    std::unique_lock<std::mutex> lock(kMutex);
    auto* outPutBatch = static_cast<mmind::eye::ProfileBatch*>(pUser);
    outPutBatch->append(batch);
}

TEST_F(ProVirtualSDKFixture, CaptureByCallBack) {
    ReadJson jsonfile(jsonPath);
    std::string mrawPath = jsonfile.getJsonValue("mraw", 0, "mraw_path");
    std::cout << mrawPath << std::endl;

    mmind::eye::VirtualProfiler profiler(mrawPath);
    mmind::eye::VirtualUserSet currentUserSet = profiler.currentUserSet();

    int captureLineCount = 0, dataPoints = 0;;
    auto statusDataPoints = currentUserSet.getIntValue(mmind::eye::scan_settings::DataPointsPerProfile::name, dataPoints);
    testErrorStatusSuccessful(statusDataPoints);

    auto statusLineCount = currentUserSet.getIntValue(mmind::eye::scan_settings::ScanLineCount::name, captureLineCount);
    testErrorStatusSuccessful(statusLineCount);

    mmind::eye::ProfileBatch profileBatch(dataPoints);

    auto status = profiler.registerAcquisitionCallback(callbackFunc, &profileBatch);
    testErrorStatusSuccessful(status);

    auto statusStop = profiler.stopAcquisition();
    testErrorStatusSuccessful(statusStop);

    auto statusStart = profiler.startAcquisition();
    testErrorStatusSuccessful(statusStart);

    while (true) {
        std::unique_lock<std::mutex> lock(kMutex);
        if (!profileBatch.isEmpty()) {
            break;
        }
        lock.unlock();
    }

    EXPECT_FALSE(profileBatch.isEmpty());
}