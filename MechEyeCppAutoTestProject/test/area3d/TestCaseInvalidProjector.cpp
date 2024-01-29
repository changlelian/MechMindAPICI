#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Projector.h"

using namespace mmind::eye;


TEST_P(CameraInvalidParametersProjectorPowerLevel, ProjectorPowerLevel) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getProjectorPowerLevelCameraType(modelName))
	{
	case CameraProjectorPowerLevel::ProjectorPowerLevelCamera:
	{
		testInvalidEnumValue(camera, projector_setting::PowerLevel::name, modeMap, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not projector power level series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersProjectorPowerLevel,
	::testing::Values(std::make_pair(" ", -1), std::make_pair("Test", 3)));






TEST_P(CameraInvalidParametersProjectorFringeCodingMode, ProjectorPowerLevel) {
	std::pair<std::string, int> modeMap = GetParam();
	switch (getProjectorCodingModeCameraType(modelName))
	{
	case CameraProjectorCodingMode::ProjectorCodingModeCamera:
	{
		testInvalidEnumValue(camera, projector_setting::FringeCodingMode::name, modeMap, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not projector power level series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersProjectorFringeCodingMode,
	::testing::Values(std::make_pair(" ", -1), std::make_pair("Test", 5)));








TEST_P(CameraInvalidParametersProjectorAntiFlickerMode, ProjectorAntiFlickerMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getProjectorAntiflickerCameraType(modelName))
	{
	case CameraProjectorAntiflicker::ProjectorAntiflickerCamera:
	{
		testEnumValue(camera, projector_setting::FringeCodingMode::name, std::make_pair("Fast", 0));
		testInvalidEnumValue(camera, projector_setting::AntiFlickerMode::name, modeMap, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not projector power level series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersProjectorAntiFlickerMode,
	::testing::Values(std::make_pair(" ", -1), std::make_pair("Test", 3)));