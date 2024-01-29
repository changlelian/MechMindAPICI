#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning2D.h"

using namespace mmind::eye;


TEST_P(CameraInvalidParametersScan2DExposureMode, Scan2DExposureMode) {
	std::pair<std::string, int> modeMap = GetParam();
	switch (get2DExposureModeCamera(CameraSDKFixture::modelName))
	{
	case Camera2DExposureMode::Exposure2DModeNoFlash:
			testInvalidEnumValue(camera, scanning2d_setting::ExposureMode::name, modeMap, mmind::eye::ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;

	default:
		if (modeMap.second != 3) {
			testInvalidEnumValue(camera, scanning2d_setting::ExposureMode::name, modeMap, mmind::eye::ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		}
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DExposureMode,
	::testing::Values(std::make_pair("Flash", 3), std::make_pair("", 3) , std::make_pair("Test", 4)));





TEST_P(CameraInvalidParametersScan2DExposureTime, Scan2DExposureTimeDouble) {
	const double setValue = GetParam();

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("Timed", 0));

	switch (get2DExposureCameraType(CameraSDKFixture::modelName))
	{
	case Camera2DExposure::Exposure42D:
		// Laser Camera
		testInvalidDoubleValue(camera, scanning2d_setting::ExposureTime::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

		break;
	case Camera2DExposure::Exposure2DOther:
		// Other Camera
		testInvalidDoubleValue(camera, scanning2d_setting::ExposureTime::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
	default:
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DExposureTime, ::testing::Values(0, 999.1));







TEST_P(CameraInvalidParametersScan2DSharpenFactor, Scan2DSharpenFactorouble) {

	double  setValue = GetParam();
	testInvalidDoubleValue(camera, scanning2d_setting::SharpenFactor::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DSharpenFactor, ::testing::Values(-0.1, 16.1));








TEST_P(CameraInvalidParametersScan2DExpectedGrayValue, Scan2DExpectedGrayValue) {

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("Auto", 1));

	int  setValue = GetParam();
	testInvalidIntValue(camera, scanning2d_setting::ExpectedGrayValue::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DExpectedGrayValue, ::testing::Values(-1, 256));








TEST_F(CameraInvalidParametersScan2DROI, Scan2DROI) {

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("Auto", 1));

	mmind::eye::ROI roi1{0, 0, static_cast<size_t>(colorWidthResolution) + 1,static_cast<size_t>(colorHeightResolution)},
		            roi2{0, 0, static_cast<size_t>(colorWidthResolution),static_cast<size_t>(colorHeightResolution) + 1},
		            roi3{1, 0, static_cast<size_t>(colorWidthResolution) + 1,static_cast<size_t>(colorHeightResolution)},
		            roi4{1, 0, static_cast<size_t>(colorWidthResolution),static_cast<size_t>(colorHeightResolution) + 1};


	testInvalidROIValue(camera, scanning2d_setting::AutoExposureROI::name,roi1, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

	testInvalidROIValue(camera, scanning2d_setting::AutoExposureROI::name,roi2, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
							  
	testInvalidROIValue(camera, scanning2d_setting::AutoExposureROI::name,roi3, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

	testInvalidROIValue(camera, scanning2d_setting::AutoExposureROI::name,roi4, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
}    







TEST_P(CameraInvalidParametersScan2DHDRExposureSequence, Scan2DHDRExposureSequence) {

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("HDR", 2));

	const std::vector<double>  setValue = GetParam();
	switch (getScanHDRExposureTypeCameraType(CameraSDKFixture::modelName))
	{
	case CameraScanHDRExposureType::HDR_01_999:
		// Invalid2DHDRExposureSequence
		testInvalidDoubleArrayValue(camera, scanning2d_setting::HDRExposureSequence::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;
	case CameraScanHDRExposureType::HDR_4_996:
		// InvalidLaser2DHDRExposureSequence
		testInvalidDoubleArrayValue(camera, scanning2d_setting::HDRExposureSequence::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
	default:
		break;
	}

}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidParametersScan2DHDRExposureSequence,
	::testing::Values(std::vector<double>{0},
		std::vector<double>{0, 0},
		std::vector<double>{0, 0, 0},
		std::vector<double>{0, 0, 0, 0},
		std::vector<double>{0, 0, 0, 0, 0},
		std::vector<double>{999.1},
		std::vector<double>{999.1, 999.1},
		std::vector<double>{999.1, 999.1, 999.1},
		std::vector<double>{999.1, 999.1, 999.1, 999.1},
		std::vector<double>{999.1, 999.1, 999.1, 999.1, 999.1}

));








TEST_P(CameraInvalidDepthSourceExposureMode, DepthSourceExposureMode) {
	const std::pair<std::string, int> modeMap = GetParam();

	switch (getDepthSourceExposureCameraType(CameraSDKFixture::modelName))
	{
	case CameraDepthSourceExposure::DepthSourceExposureCamera:
		testInvalidEnumValue(camera, scanning2d_setting::DepthSourceExposureMode::name, modeMap, 
			mmind::eye::ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);

		break;

	default:
		std::cout << "The camera is not depth source series. Current camera is " << CameraSDKFixture::modelName << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidDepthSourceExposureMode,
	::testing::Values(std::make_pair("", 4)));








TEST_P(CameraInvalidDepthSourceExposureTime, DepthSourceExposureTime) {

	const double setValue = GetParam();

	switch (getDepthSourceExposureCameraType(CameraSDKFixture::modelName))
	{
	case CameraDepthSourceExposure::DepthSourceExposureCamera:
		testEnumValue(camera, scanning2d_setting::DepthSourceExposureMode::name, std::make_pair("Timed", 0));
		testInvalidDoubleValue(camera, scanning2d_setting::DepthSourceExposureTime::name, setValue, ErrorStatus::MMIND_STATUS_OUT_OF_RANGE_ERROR);
		break;

	default:
		std::cout << "The camera is not depth source series. Current camera is " << CameraSDKFixture::modelName <<  std::endl;
		break;
	}
}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraInvalidDepthSourceExposureTime, ::testing::Values(0, 999.1));