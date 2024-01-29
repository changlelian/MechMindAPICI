#include <iostream>
#include "gtest/gtest.h"
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Projector.h"

using namespace mmind::eye;


TEST_P(CameraParametersProjectorPowerLevel, ProjectorPowerLevel) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getProjectorPowerLevelCameraType(modelName))
	{
	case CameraProjectorPowerLevel::ProjectorPowerLevelCamera:
	{
		testEnumValue(camera, projector_setting::PowerLevel::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is not projector power level camera series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersProjectorPowerLevel,
	::testing::Values(std::make_pair("High", 0), std::make_pair("Normal", 1), std::make_pair("Low", 2)));






TEST_P(CameraParametersProjectorFringeCodingMode, ProjectorFringeCodingMode) {

	std::pair<std::string, int> modeMap = GetParam();

	if (getProjectorCodingModeCameraType(modelName) != CameraProjectorCodingMode::ProjectorCodingModeCamera) {
		std::cout << "The camera is not projector coding mode camera series" << std::endl;
		return;
	}

	if (getProjectorCodingTranslucentModeCameraType(modelName) == CameraProjectorCodingTranslucentMode::OtherCamera) {
		if (modeMap.second != 2 && modeMap.second != 3)  {
			testEnumValue(camera, projector_setting::FringeCodingMode::name, modeMap);
		}
	}
	else {
		// pro serious
		testEnumValue(camera, projector_setting::FringeCodingMode::name, modeMap);
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersProjectorFringeCodingMode,
	::testing::Values(std::make_pair("Fast", 0), std::make_pair("Accurate", 1), std::make_pair("Translucent", 2), std::make_pair("Reflective", 3)));





TEST_P(CameraParametersProjectorAntiFlickerMode, ProjectorAntiFlickerMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getProjectorAntiflickerCameraType(modelName))
	{
	case CameraProjectorAntiflicker::ProjectorAntiflickerCamera:
	{
		testEnumValue(camera, projector_setting::FringeCodingMode::name, std::make_pair("Fast", 0));
		testEnumValue(camera, projector_setting::AntiFlickerMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is Not Projector AntiFlicker Mode series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersProjectorAntiFlickerMode,
	::testing::Values(std::make_pair("Off", 0), std::make_pair("AC50Hz", 1), std::make_pair("AC60Hz", 2)));