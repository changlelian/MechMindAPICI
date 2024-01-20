#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Uhp.h"

using namespace mmind::eye;




TEST_P(CameraInvalidParametersUhpCaptureMode, UhpCaptureMode) {

	std::pair<std::string, int> modeMap = GetParam();
	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::UHPCamera:
	{
		testInvalidEnumValue(camera, uhp_setting::CaptureMode::name, modeMap, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	}
	default:
		GTEST_SKIP();
		std::cout << "The camera is not uhp series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersUhpCaptureMode, ::testing::Values(std::make_pair(" ", -1), std::make_pair("Test", 3)));

