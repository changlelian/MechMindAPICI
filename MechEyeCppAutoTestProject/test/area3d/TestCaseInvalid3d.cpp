#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning3D.h"

using namespace mmind::eye;







TEST_P(CameraInvalidParametersScan3DExposureSequence, Scan3DExposureSequence) {

	const std::vector<double>  setValue = GetParam();

	switch (getCamera3DExposureType(modelName))
	{
	case Camera3DExposure::Exposure43D:
		// Laser Camera
		testInvalidDoubleArrayValue(camera, scanning3d_setting::ExposureSequence::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;

	case Camera3DExposure::Exposure83D:
		// LSR Camera
		testInvalidDoubleArrayValue(camera, scanning3d_setting::ExposureSequence::name, setValue,  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;

	case Camera3DExposure::Exposure453D:
		// Pro L Enhanced
		testInvalidDoubleArrayValue(camera, scanning3d_setting::ExposureSequence::name, setValue,  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;

	case Camera3DExposure::Exposure3DOther:
		// Other Camera
		testInvalidDoubleArrayValue(camera, scanning3d_setting::ExposureSequence::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
	default:
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan3DExposureSequence,
	::testing::Values(std::vector<double>{0},
		std::vector<double>{0, 0},
		std::vector<double>{0, 0, 0},
		std::vector<double>{999.1},
		std::vector<double>{999.1, 999.1},
		std::vector<double>{999.1, 999.1, 999.1}
));


TEST_P(CameraInvalidParametersScan3DGain, ParametersScan3DGain) {
	const double  setValue = GetParam();
	testInvalidDoubleValue(camera, scanning3d_setting::Gain::name, setValue,  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan3DGain, ::testing::Values(-0.1, 16.1));






TEST_P(CameraInvalidParametersScan3DDepthRange, DepthRange) {

	const Range<int> setRange = GetParam();

	if (setRange.max > 5000) {
		testInvalidRangeValue(camera, scanning3d_setting::DepthRange::name, setRange, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
	}
	else
	{
		//std::cout << setRange.min << setRange.max << std::endl;
		testInvalidRangeValue(camera, scanning3d_setting::DepthRange::name, setRange, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan3DDepthRange,
	::testing::ValuesIn(CameraInvalidParametersScan3DDepthRange::invalidRangeGenerator()));






TEST_F(CameraInvalidParametersScan3DROI, Scan3DROI) {

	mmind::eye::ROI roi1{0, 0, static_cast<size_t>(depthWidthResolution) + 1,static_cast<size_t>(depthHeightResolution)},
		            roi2{0, 0, static_cast<size_t>(depthWidthResolution),static_cast<size_t>(depthHeightResolution) + 1},
		            roi3{1, 0, static_cast<size_t>(depthWidthResolution) + 1,static_cast<size_t>(depthHeightResolution)},
		            roi4{1, 0, static_cast<size_t>(depthWidthResolution),static_cast<size_t>(depthHeightResolution) + 1};


	testInvalidROIValue(camera, scanning3d_setting::ROI::name,roi1, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

	testInvalidROIValue(camera, scanning3d_setting::ROI::name,roi2,  ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

	testInvalidROIValue(camera, scanning3d_setting::ROI::name,roi3, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

	testInvalidROIValue(camera, scanning3d_setting::ROI::name,roi4, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
}    
