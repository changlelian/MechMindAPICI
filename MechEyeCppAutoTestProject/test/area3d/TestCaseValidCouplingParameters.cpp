#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning3D.h"
#include "area_scan_3d_camera/parameters/Scanning2D.h"
#include "area_scan_3d_camera/parameters/PointCloudProcessing.h"
#include "area_scan_3d_camera/parameters/Uhp.h"
#include "area_scan_3d_camera/parameters/Projector.h"
#include "area_scan_3d_camera/parameters/Laser.h"

using namespace mmind::eye;

/**
*    Scan2DExposure-Timed
*/

TEST_F(CameraCouplingParameters, Test2DExposureTimed) {

    mmind::eye::UserSet us = camera.currentUserSet();

    testStautsSuccessful(us.setEnumValue(mmind::eye::scanning2d_setting::ExposureMode::name,
        static_cast<int>(mmind::eye::scanning2d_setting::ExposureMode::Value::Timed)));  // success

    // available
    testStautsSuccessful(us.setFloatValue(mmind::eye::scanning2d_setting::ExposureTime::name, 4));
    testStautsSuccessful(us.setFloatValue(mmind::eye::scanning2d_setting::SharpenFactor::name, 0.1));

    // not available
    mmind::eye::ROI roi(0, 0, 3, 3);
    std::vector<double> hdrArray(4, 4);
    testStautsFailed(us.setIntValue(mmind::eye::scanning2d_setting::ExpectedGrayValue::name, 0));
    testStautsFailed(us.setBoolValue(mmind::eye::scanning2d_setting::ToneMappingEnable::name, true));  // Faild
    testStautsFailed(us.setRoiValue(mmind::eye::scanning2d_setting::AutoExposureROI::name, roi));  // Faild
    testStautsFailed(us.setFloatArrayValue(mmind::eye::scanning2d_setting::HDRExposureSequence::name, hdrArray));  // 


}



TEST_F(CameraCouplingParameters, Test2DExposureAuto) {

    mmind::eye::UserSet us = camera.currentUserSet();

    mmind::eye::ROI roi(0, 0, 3, 3);
    std::vector<double> hdrArray(4, 4);

    testStautsSuccessful(us.setEnumValue(mmind::eye::scanning2d_setting::ExposureMode::name,
        static_cast<int>(mmind::eye::scanning2d_setting::ExposureMode::Value::Auto)));  // success
    
    // available
    testStautsSuccessful(us.setFloatValue(mmind::eye::scanning2d_setting::SharpenFactor::name, 0.1));
    testStautsSuccessful(us.setIntValue(mmind::eye::scanning2d_setting::ExpectedGrayValue::name, 0));
    testStautsSuccessful(us.setRoiValue(mmind::eye::scanning2d_setting::AutoExposureROI::name, roi));
    
    // not available
    testStautsFailed(us.setFloatValue(mmind::eye::scanning2d_setting::ExposureTime::name, 4));
    testStautsFailed(us.setBoolValue(mmind::eye::scanning2d_setting::ToneMappingEnable::name, true));  // Faild
    testStautsFailed(us.setFloatArrayValue(mmind::eye::scanning2d_setting::HDRExposureSequence::name, hdrArray));  // 


}




TEST_F(CameraCouplingParameters, Test2DExposureHDR) {

    mmind::eye::UserSet us = camera.currentUserSet();
    mmind::eye::ROI roi(0, 0, 3, 3);
    std::vector<double> hdrArray(4, 4);

    testStautsSuccessful(us.setEnumValue(mmind::eye::scanning2d_setting::ExposureMode::name,
        static_cast<int>(mmind::eye::scanning2d_setting::ExposureMode::Value::HDR)));  // success

    // available
    testStautsSuccessful(us.setFloatValue(mmind::eye::scanning2d_setting::SharpenFactor::name, 0.1));
    testStautsSuccessful(us.setBoolValue(mmind::eye::scanning2d_setting::ToneMappingEnable::name, true));  // 
    testStautsSuccessful(us.setFloatArrayValue(mmind::eye::scanning2d_setting::HDRExposureSequence::name, hdrArray));  // 

    // not available
    testStautsFailed(us.setFloatValue(mmind::eye::scanning2d_setting::ExposureTime::name, 4));
    testStautsFailed(us.setIntValue(mmind::eye::scanning2d_setting::ExpectedGrayValue::name, 0));
    testStautsFailed(us.setRoiValue(mmind::eye::scanning2d_setting::AutoExposureROI::name, roi));


}


TEST_F(CameraCouplingParameters, Test2DExposureFlash) {

    if (get2DExposureModeCamera(modelName) == Camera2DExposureMode::Exposure2DModeNoFlash)
        return;
    mmind::eye::UserSet us = camera.currentUserSet();
    mmind::eye::ROI roi(0, 0, 3, 3);
    std::vector<double> hdrArray(4, 4);

    testStautsSuccessful(us.setEnumValue(mmind::eye::scanning2d_setting::ExposureMode::name,
        static_cast<int>(mmind::eye::scanning2d_setting::ExposureMode::Value::Flash)));  // success

    // available
    testStautsSuccessful(us.setFloatValue(mmind::eye::scanning2d_setting::SharpenFactor::name, 0.1));


    // not available
    testStautsFailed(us.setFloatValue(mmind::eye::scanning2d_setting::ExposureTime::name, 4));
    testStautsFailed(us.setIntValue(mmind::eye::scanning2d_setting::ExpectedGrayValue::name, 0));
    testStautsFailed(us.setRoiValue(mmind::eye::scanning2d_setting::AutoExposureROI::name, roi));
    testStautsFailed(us.setBoolValue(mmind::eye::scanning2d_setting::ToneMappingEnable::name, true));  // 
    testStautsFailed(us.setFloatArrayValue(mmind::eye::scanning2d_setting::HDRExposureSequence::name, hdrArray));  // 


}




/**
*    ProjectorEncoding-Translucen
*/
TEST_F(CameraCouplingParameters, TestProjectorEncodingTranslucentMode) {
    mmind::eye::UserSet us = camera.currentUserSet();

    if (getProjectorCodingModeCameraType(modelName) != CameraProjectorCodingMode::ProjectorCodingModeCamera ||
        getCodingModeReflectiveCameraType(modelName) != CameraCodingModeReflective::ReflectiveModeCamera)
        return;

    std::vector<double> timeArray{ 4,4,4 };
    testStautsSuccessful(us.setEnumValue(mmind::eye::projector_setting::FringeCodingMode::name,
        static_cast<int>(mmind::eye::projector_setting::FringeCodingMode::Value::Translucent)));  // success

    //available
    testStautsSuccessful(us.setFloatArrayValue(mmind::eye::scanning3d_setting::ExposureSequence::name, timeArray));
    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::OutlierRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::OutlierRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::NoiseRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::NoiseRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::GapFilling::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::GapFilling::Value::Off)));

    testStautsSuccessful(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeContrastThreshold::name, 1));

    testStautsSuccessful(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeMinThreshold::name, 1));

    // not available
    testStautsFailed(us.setEnumValue(mmind::eye::pointcloud_processing_setting::EdgePreservation::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::EdgePreservation::Value::Sharp)));

    // pro 系列
    testStautsFailed(us.setBoolValue(mmind::eye::pointcloud_processing_setting::EnableDistortionCorrection::name, true));
    testStautsFailed(us.setIntValue(mmind::eye::pointcloud_processing_setting::DistortionCorrection::name, 1));
}






TEST_F(CameraCouplingParameters, TestProjectorEncodingReflectiveMode) {
    mmind::eye::UserSet us = camera.currentUserSet();

    if (getProjectorCodingModeCameraType(modelName) != CameraProjectorCodingMode::ProjectorCodingModeCamera ||
        getCodingModeReflectiveCameraType(modelName) != CameraCodingModeReflective::ReflectiveModeCamera)
        return;

    std::vector<double> time1Array{ 4 }, time2Array{ 8,8,8 };
    testStautsSuccessful(us.setEnumValue(mmind::eye::projector_setting::FringeCodingMode::name,
        static_cast<int>(mmind::eye::projector_setting::FringeCodingMode::Value::Reflective)));  // success

    // available

    showError(us.setFloatArrayValue(mmind::eye::scanning3d_setting::ExposureSequence::name, time1Array));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::OutlierRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::OutlierRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::NoiseRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::NoiseRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::EdgePreservation::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::EdgePreservation::Value::Sharp)));


    // not available

    // pro 系列
    testStautsFailed(us.setBoolValue(mmind::eye::pointcloud_processing_setting::EnableDistortionCorrection::name, true));
    testStautsFailed(us.setIntValue(mmind::eye::pointcloud_processing_setting::DistortionCorrection::name, 1));

    testStautsFailed(us.setEnumValue(mmind::eye::pointcloud_processing_setting::GapFilling::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::GapFilling::Value::Off)));

    testStautsFailed(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeContrastThreshold::name, 1));
    testStautsFailed(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeMinThreshold::name, 1));
    testStautsFailed(us.setFloatArrayValue(mmind::eye::scanning3d_setting::ExposureSequence::name, time2Array));
}


/**
*    LaserEncoding-Reflective
*/

TEST_F(CameraCouplingParameters, TestLaserAccurateMode) {
    mmind::eye::UserSet us = camera.currentUserSet();

    if (getSpecificCameraType(modelName) != SpecificCameraType::LaserCameras ||
        getCodingModeReflectiveCameraType(modelName) != CameraCodingModeReflective::ReflectiveModeCamera)
        return;

    std::vector<double> timeArray{ 8,8,8 };

    // LSR L系列
    testStautsSuccessful(us.setEnumValue(mmind::eye::laser_setting::FringeCodingMode::name,
        static_cast<int>(mmind::eye::laser_setting::FringeCodingMode::Value::Accurate)));

    // available
    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::OutlierRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::OutlierRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::NoiseRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::NoiseRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::EdgePreservation::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::EdgePreservation::Value::Sharp)));

    testStautsSuccessful(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeContrastThreshold::name, 1));
    testStautsSuccessful(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeMinThreshold::name, 1));
    testStautsSuccessful(us.setIntValue(mmind::eye::laser_setting::FramePartitionCount::name, 1));
    testStautsSuccessful(us.setFloatArrayValue(mmind::eye::scanning3d_setting::ExposureSequence::name, timeArray));
}



TEST_F(CameraCouplingParameters, TestLaserReflectiveMode) {
    mmind::eye::UserSet us = camera.currentUserSet();

    if (getSpecificCameraType(modelName) != SpecificCameraType::LaserCameras ||
        getCodingModeReflectiveCameraType(modelName) != CameraCodingModeReflective::ReflectiveModeCamera)
        return;

    std::vector<double> time1Array{ 8 }, time2Array{ 8,8,8 };

    testStautsSuccessful(us.setEnumValue(mmind::eye::laser_setting::FringeCodingMode::name,
        static_cast<int>(mmind::eye::laser_setting::FringeCodingMode::Value::Reflective)));

    // available
    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::SurfaceSmoothing::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::OutlierRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::OutlierRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::NoiseRemoval::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::NoiseRemoval::Value::Off)));

    testStautsSuccessful(us.setEnumValue(mmind::eye::pointcloud_processing_setting::EdgePreservation::name,
        static_cast<int>(mmind::eye::pointcloud_processing_setting::EdgePreservation::Value::Sharp)));


    testStautsSuccessful(us.setFloatArrayValue(mmind::eye::scanning3d_setting::ExposureSequence::name, time1Array));

    // not available
    testStautsFailed(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeMinThreshold::name, 1));
    testStautsFailed(us.setIntValue(mmind::eye::laser_setting::FramePartitionCount::name, 1));
    testStautsFailed(us.setFloatArrayValue(mmind::eye::scanning3d_setting::ExposureSequence::name, time2Array));
    testStautsFailed(us.setIntValue(mmind::eye::pointcloud_processing_setting::FringeContrastThreshold::name, 1));
}



/**
*    UHP-CaptureMode
*/
TEST_F(CameraCouplingParameters, TestUHPCaptureMode) {
    mmind::eye::ROI roi(0, 0, 500, 500);
    mmind::eye::UserSet us = camera.currentUserSet();
    
    if (getSpecificCameraType(modelName) != SpecificCameraType::UHPCamera)
        return;

    // available
    testStautsSuccessful(us.setEnumValue(mmind::eye::uhp_setting::CaptureMode::name,
        static_cast<int>(mmind::eye::uhp_setting::CaptureMode::Value::Camera1)));

    testStautsSuccessful(us.setRoiValue(mmind::eye::scanning3d_setting::ROI::name, roi));

    testStautsSuccessful(us.setEnumValue(mmind::eye::uhp_setting::CaptureMode::name,
        static_cast<int>(mmind::eye::uhp_setting::CaptureMode::Value::Merge)));

    testStautsSuccessful(us.setRoiValue(mmind::eye::scanning3d_setting::ROI::name, roi));
}

/**
*    DepthSource-Mode
*/
TEST_F(CameraCouplingParameters, TestDepthSourceMode) {
    mmind::eye::UserSet us = camera.currentUserSet();

    if (getDepthSourceExposureCameraType(modelName) != CameraDepthSourceExposure::DepthSourceExposureCamera)
        return;

    // available
    testStautsSuccessful(us.setEnumValue(mmind::eye::scanning2d_setting::DepthSourceExposureMode::name,
        static_cast<int>(mmind::eye::scanning2d_setting::DepthSourceExposureMode::Value::Timed)));

    testStautsSuccessful(us.setFloatValue(mmind::eye::scanning2d_setting::DepthSourceExposureTime::name, 8.0));

    // not available
    testStautsSuccessful(us.setEnumValue(mmind::eye::scanning2d_setting::DepthSourceExposureMode::name,
        static_cast<int>(mmind::eye::scanning2d_setting::DepthSourceExposureMode::Value::Flash)));

    testStautsFailed(us.setFloatValue(mmind::eye::scanning2d_setting::DepthSourceExposureTime::name, 8.0));
}