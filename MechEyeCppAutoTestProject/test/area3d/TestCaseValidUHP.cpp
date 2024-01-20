#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Uhp.h"

using namespace mmind::eye;


TEST_P(CameraParametersUhpCaptureMode, UhpFringeCodingMode) {

	std::pair<std::string, int> modeMap = GetParam();

	switch (getSpecificCameraType(modelName))
	{
	case SpecificCameraType::UHPCamera:
	{
		testEnumValue(camera, uhp_setting::CaptureMode::name, modeMap);
		break;
	}
	default:
		std::cout << "The camera is not UHP series" << std::endl;
		break;
	}

}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersUhpCaptureMode,
	::testing::Values(std::make_pair("Camera1", 0), std::make_pair("Camera2", 1), std::make_pair("Merge", 2)));