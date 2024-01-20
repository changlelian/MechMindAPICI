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
*  2D Parameters attribute
*/

TEST_F(CameraAttribute, Scan2DExposureMode) {
	std::vector<std::string>vec1{ "Timed", "Auto", "HDR", "Flash" };
	std::vector<std::string>vec2{ "Timed", "Auto", "HDR"};

	switch (get2DExposureModeCamera(modelName))
	{
	case Camera2DExposureMode::Exposure2DModeNoFlash:
	{
		auto* param = testParameterAttribute(camera, "Scan2DExposureMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec2.size(), vec2);
		break;
	}
	case Camera2DExposureMode::Exposure2DALLMode:
	{
		auto* param = testParameterAttribute(camera, "Scan2DExposureMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec1.size(), vec1);
		break;
	}
	default:
		break;
	}
}

TEST_F(CameraAttribute, Scan2DSharpenFactor) {
	auto* param = testParameterAttribute(camera, "Scan2DSharpenFactor", Parameter::_Float);
	testDoubleParameterAttribute(param, 0.1, 0.0, 5.0);
}

TEST_F(CameraAttribute, Scan2DExposureTime) {

	switch (get2DExposureCameraType(modelName))
	{
	case Camera2DExposure::Exposure2DOther:
	{
		auto* param = testParameterAttribute(camera, "Scan2DExposureTime", Parameter::_Float);
		testDoubleParameterAttribute(param, 0.1, 0.1, 999, "ms");
		break;
	}
	case Camera2DExposure::Exposure42D:
	{
		auto* param = testParameterAttribute(camera, "Scan2DExposureTime", Parameter::_Float);
		testDoubleParameterAttribute(param, 4, 4, 996, "ms");
		break;
	}

	default:
		break;
	}
}

TEST_F(CameraAttribute, Scan2DExpectedGrayValue) {
	auto* param = testParameterAttribute(camera, "Scan2DExpectedGrayValue", Parameter::_Int);
	testIntParameterAttribute(param, 1, 0, 255);
}

TEST_F(CameraAttribute, Scan2DToneMappingEnable) {
	testParameterAttribute(camera, "Scan2DToneMappingEnable", Parameter::_Bool);
}

TEST_F(CameraAttribute, Scan2DROI) {
	auto* param = testParameterAttribute(camera, "Scan2DROI", Parameter::_Roi);
	testRoiParameterAttribute(param, colorWidthResolution, colorHeightResolution);
}

TEST_F(CameraAttribute, Scan2DHDRExposureSequence) {
	switch (get2DExposureCameraType(modelName))
	{
	case Camera2DExposure::Exposure2DOther:
	{
		auto* param = testParameterAttribute(camera, "Scan2DHDRExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 0.1, 0.1, 999, "ms");
		break;
	}

	case Camera2DExposure::Exposure42D:
	{
		auto* param = testParameterAttribute(camera, "Scan2DHDRExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 4, 4, 996, "ms");
		break;
	}
	default:
		break;
	}
}



/**
*  3D Parameters attribute
*/
TEST_F(CameraAttribute, Scan3DExposureSequence) {
	switch (getCamera3DExposureType(modelName))
	{
	case Camera3DExposure::Exposure83D:
	{
		auto* param = testParameterAttribute(camera, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 4, 8, 96, "ms");
		break;
	}
	case Camera3DExposure::Exposure43D:
	{
		auto* param = testParameterAttribute(camera, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 4, 4, 96, "ms");
		break;
	}
	case Camera3DExposure::Exposure453D:
	{
		auto* param = testParameterAttribute(camera, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 0.1, 0.1, 45, "ms");
		break;
	}
	case Camera3DExposure::Exposure3DOther:
	{
		auto* param = testParameterAttribute(camera, "Scan3DExposureSequence", Parameter::_FloatArray);
		testDoubleArrayParameterAttribute(param, 0.1, 0.1, 99, "ms");
		break;
	}
	default:
		break;
	}

}

TEST_F(CameraAttribute, Scan3DROI) {
	auto* param = testParameterAttribute(camera, "Scan3DROI", Parameter::_Roi);
	testRoiParameterAttribute(param, depthWidthResolution, depthHeightResolution);
}



TEST_F(CameraAttribute, Scan3DGain) {
	auto* param = testParameterAttribute(camera, "Scan3DGain", Parameter::_Float);
	testDoubleParameterAttribute(param, 0.1, 0, 16, "dB");
}



TEST_F(CameraAttribute, DepthRange) {
	auto* param = testParameterAttribute(camera, "DepthRange", Parameter::_Range);
	testRangeArrayParameterAttribute(param, 1, 1, 5000, "mm");
}



/**
*   Pointcloud attribute
*/
TEST_F(CameraAttribute, PointCloudSurfaceSmoothing) {
	std::vector<std::string>vec{ "Off", "Weak", "Normal", "Strong" };
	auto* param = testParameterAttribute(camera, "PointCloudSurfaceSmoothing", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, PointCloudNoiseRemoval) {
	std::vector<std::string>vec{ "Off", "Weak", "Normal", "Strong" };
	auto* param = testParameterAttribute(camera, "PointCloudNoiseRemoval", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, PointCloudOutlierRemoval) {
	std::vector<std::string>vec{ "Off", "Weak", "Normal", "Strong" };
	auto* param = testParameterAttribute(camera, "PointCloudOutlierRemoval", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, PointCloudEdgePreservation) {
	std::vector<std::string>vec{ "Sharp", "Normal", "Smooth" };
	auto* param = testParameterAttribute(camera, "PointCloudEdgePreservation", Parameter::_Enum);
	testEnumParameterAttribute(param, vec.size(), vec);
}

TEST_F(CameraAttribute, FringeMinThreshold) {
	auto* param = testParameterAttribute(camera, "FringeMinThreshold", Parameter::_Int);
	testIntParameterAttribute(param, 1, 1, 100);
}

TEST_F(CameraAttribute, FringeContrastThreshold) {
	auto* param = testParameterAttribute(camera, "FringeContrastThreshold", Parameter::_Int);
	testIntParameterAttribute(param, 1, 1, 100);
}


/**
*   UHP attribute
*/

TEST_F(CameraAttribute, UhpCaptureMode) {
	std::vector<std::string>vec{ "Camera1", "Camera2", "Merge"};


	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::UHPCamera:
	{
		auto* param = testParameterAttribute(camera, "UhpCaptureMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not UHP" << std::endl;
		break;
	}
}


/**
*   Laser attribute
*/
TEST_F(CameraAttribute, LaserPowerLevel) {

	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		auto* param = testParameterAttribute(camera, "LaserPowerLevel", Parameter::_Int);
		testIntParameterAttribute(param, 1, 50, 100, "%");
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, LaserFrameRange) {

	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		auto* param = testParameterAttribute(camera, "LaserFrameRange", Parameter::_Range);
		testRangeArrayParameterAttribute(param, 1, 0, 100, "");
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}

TEST_F(CameraAttribute, LaserFringeCodingMode) {
	std::vector<std::string>vec{ "Fast", "Accurate" };

	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		auto* param = testParameterAttribute(camera, "LaserFringeCodingMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, LaserFramePartitionCount) {

	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		auto* param = testParameterAttribute(camera, "LaserFramePartitionCount", Parameter::_Int);
		testIntParameterAttribute(param, 1, 1, 4);
		break;
	}
	default:
		std::cout << "The camera is Not Laser series" << std::endl;
		break;
	}
}


/**
*   Projector attribute
*/
TEST_F(CameraAttribute, ProjectorPowerLevel) {
	std::vector<std::string>vec{ "High", "Normal", "Low" };


	switch (getProjectorPowerLevelCameraType(modelName))
	{
	case CameraProjectorPowerLevel::ProjectorPowerLevelCamera:
	{
		auto* param = testParameterAttribute(camera, "ProjectorPowerLevel", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorPowerLevel series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, ProjectorFringeCodingMode) {
	std::vector<std::string>vec{ "Fast", "Accurate" };

	switch (getProjectorCodingModeCameraType(modelName))
	{
	case CameraProjectorCodingMode::ProjectorCodingModeCamera:
	{
		auto* param = testParameterAttribute(camera, "ProjectorFringeCodingMode", Parameter::_Enum);
		//testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorFringeCodingMode series" << std::endl;
		break;
	}
}


TEST_F(CameraAttribute, ProjectorAntiFlickerMode) {
	std::vector<std::string>vec{ "Off", "AC50Hz",  "AC60Hz"};

	switch (getProjectorAntiflickerCameraType(modelName))
	{
	case CameraProjectorAntiflicker::ProjectorAntiflickerCamera:
	{
		auto* param = testParameterAttribute(camera, "AntiFlickerMode", Parameter::_Enum);
		testEnumParameterAttribute(param, vec.size(), vec);
		break;
	}
	default:
		std::cout << "The camera is Not ProjectorAntiflicker series" << std::endl;
		break;
	}
}