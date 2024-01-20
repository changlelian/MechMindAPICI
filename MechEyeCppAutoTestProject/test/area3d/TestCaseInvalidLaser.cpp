#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Laser.h"

using namespace mmind::eye;



TEST_P(CameraInvalidParametersLaserPowerLevel, LaserPowerLevel) {
	int  setValue = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		testInvalidIntValue(camera, laser_setting::PowerLevel::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not Laser series" << std::endl;
		break;
	}
}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersLaserPowerLevel, ::testing::Values(49, 101));





TEST_P(CameraInvalidParametersLaserFringeCodingMode, LaserFringeCodingMode) {

	std::pair<std::string, int>  setValue = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		testInvalidEnumValue(camera, laser_setting::FringeCodingMode::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not Laser series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersLaserFringeCodingMode, ::testing::Values(std::make_pair("Test", 4)));






TEST_P(CameraInvalidParametersLaserFramePartitionCount, LaserFramePartitionCount) {
	int  setValue = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		testInvalidIntValue(camera, laser_setting::FramePartitionCount::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not Laser series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersLaserFramePartitionCount, ::testing::Values(0, 5));
