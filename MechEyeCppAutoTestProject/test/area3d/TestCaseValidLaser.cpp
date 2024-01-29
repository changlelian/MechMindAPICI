#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Laser.h"

using namespace mmind::eye;


TEST_P(CameraParametersLaserPowerLevel, LaserPowerLevel) {

	const int setValue = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		testIntValue(camera, laser_setting::PowerLevel::name, setValue);
		break;
	}
	default:
		std::cout << "The camera is not Laser series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersLaserPowerLevel, ::testing::Range(50, 101));




TEST_P(CameraParametersLaserFringeCodingMode, LaserFringeCodingMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::LaserCameras:
	{
		testEnumValue(camera, laser_setting::FringeCodingMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is not Laser series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersLaserFringeCodingMode,
	::testing::Values(std::make_pair("Fast", 0), std::make_pair("Accurate", 1)));




TEST_P(CameraParametersLaserFramePartitionCount, LaserFramePartitionCount) {

	const int setValue = GetParam();

	if (getSpecificCameraType(modelName) != SpecificCameraType::LaserCameras) {
		std::cout << "The camera is not Laser series" << std::endl;
		return;
	}
	if (getCodingModeReflectiveCameraType(modelName) == CameraCodingModeReflective::ReflectiveModeCamera) {
		testEnumValue(camera, laser_setting::FringeCodingMode::name, std::make_pair("Fast", 0));
	}
	testIntValue(camera, laser_setting::FramePartitionCount::name, setValue);

}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersLaserFramePartitionCount, ::testing::Range(1, 5));
