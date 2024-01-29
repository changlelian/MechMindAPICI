#include <iostream>
#include <cmath>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning2D.h"

using namespace mmind::eye;


// [Scan2DExposureMode]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DExposureMode, Scan2DExposureMode) {
	const std::pair<std::string, int> modeMap = GetParam();

	switch (get2DExposureModeCamera(CameraSDKFixture::modelName))
	{
	case Camera2DExposureMode::Exposure2DModeNoFlash:
	if (modeMap.first != "Flash"){
		testEnumValue(camera, scanning2d_setting::ExposureMode::name, modeMap);
	}
		break;
	
	default:
		testEnumValue(camera, scanning2d_setting::ExposureMode::name, modeMap);

		break;
	}
}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DExposureMode,
	::testing::Values(std::make_pair("Timed", 0), std::make_pair("Auto", 1), std::make_pair("HDR", 2), std::make_pair("Flash", 3)));






// [Scan2DExposureTime]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DExposureTime, Scan2DExposureTimeDouble) {
	const double MAX_EXPOSURE_VALUE = 999;
	const double SCALE_FACTOR = 0.1;

	const double setValue = GetParam();
	const double result = fmod(setValue, 4.0);


	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("Timed", 0));

	switch (get2DExposureCameraType(CameraSDKFixture::modelName))
	{
		case Camera2DExposure::Exposure2DOther:
			testDoubleValue(camera, scanning2d_setting::ExposureTime::name, setValue * SCALE_FACTOR);
			break;

		case Camera2DExposure::Exposure42D:
			if (setValue <= MAX_EXPOSURE_VALUE && result == 0.0) {
				testDoubleValue(camera, scanning2d_setting::ExposureTime::name, setValue);
			}
			break;
		default:
			FAIL();
			break;
	}
}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DExposureTime, ::testing::Range(1, 9991, 1427));






// [Scan2DSharpenFactor]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DSharpenFactor, Scan2DSharpenFactorouble) {
	const double setValue = GetParam() * 0.1;
	// by namespace
	testDoubleValue(camera, scanning2d_setting::SharpenFactor::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DSharpenFactor, ::testing::Range(0, 51));






// [ExpectedGrayValue]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DExpectedGrayValue, Scan2DExpectedGrayValueInt) {
	const int setValue = GetParam();
	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("Auto", 1));

	// by namespace
	testIntValue(camera, scanning2d_setting::ExpectedGrayValue::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DExpectedGrayValue, ::testing::Range(0, 256));







// [Scan2DToneMappingEnable]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan2DToneMappingEnable, Scan2DToneMappingEnable) {
	const bool setValue = GetParam();

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("HDR", 2));

	// by namespace
	testBoolValue(camera, scanning2d_setting::ToneMappingEnable::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan2DToneMappingEnable, ::testing::Bool());





// [Scan2DROI]: Testing the [set/getIntValue] Interface with Normal Values
TEST_F(CameraScan2DROI, Scan2DROI) {

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("Auto", 1));


	// height < width
	for (int roiHeight = 0; roiHeight <= colorHeightResolution; roiHeight++)
	{
		ROI setRoi(0, 0, roiHeight, roiHeight);
		testROIValue(camera, scanning2d_setting::AutoExposureROI::name, setRoi);
	}

	ROI setRoi1(0, 0, colorWidthResolution, colorHeightResolution);
	testROIValue(camera, scanning2d_setting::AutoExposureROI::name, setRoi1);

	// height < width
	for (int roiHeight = 0; roiHeight <= colorHeightResolution / 2; roiHeight++)
	{
		ROI setRoi(colorWidthResolution/2, colorHeightResolution/2, roiHeight, roiHeight);
		testROIValue(camera, scanning2d_setting::AutoExposureROI::name, setRoi);
	}

	ROI setRoi2(colorWidthResolution / 2, colorHeightResolution / 2, colorWidthResolution / 2, colorHeightResolution / 2);
	testROIValue(camera, scanning2d_setting::AutoExposureROI::name, setRoi2);

	ROI setRoi3(colorWidthResolution, colorHeightResolution, 0, 0);
	testROIValue(camera, scanning2d_setting::AutoExposureROI::name, setRoi3);
}







// [Scan2DHDRExposureSequence]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraHDRExposureSequence, Scan2DHDRExposureSequenceFloatArray) {
	const double setValue = GetParam();
	const double result = fmod(setValue, 4.0);

	testEnumValue(camera, scanning2d_setting::ExposureMode::name, std::make_pair("HDR", 2));

	switch (getScanHDRExposureTypeCameraType(CameraSDKFixture::modelName))
	{
	case CameraScanHDRExposureType::HDR_01_999:
		testDoubleValue(camera, scanning2d_setting::HDRExposureSequence::name, setValue* 0.1, 5);
		break;

	case CameraScanHDRExposureType::HDR_4_996:
		if (setValue <= 996 && result == 0.0){
			testDoubleValue(camera, scanning2d_setting::HDRExposureSequence::name, setValue, 5);
		}
		break;
	default:
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraHDRExposureSequence, ::testing::Range(1, 9991));








TEST_P(CameraDepthSourceExposureMode, DepthSourceExposureMode) {
	const std::pair<std::string, int> modeMap = GetParam();

	switch (getDepthSourceExposureCameraType(CameraSDKFixture::modelName))
	{
	case CameraDepthSourceExposure::DepthSourceExposureCamera:
		testEnumValue(camera, scanning2d_setting::DepthSourceExposureMode::name, modeMap);
		break;

	default:
		std::cout << "The camera is not depth source series. Current camera is " << CameraSDKFixture::modelName << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraDepthSourceExposureMode,
	::testing::Values(std::make_pair("Timed", 0), std::make_pair("Flash", 1)));







TEST_P(CameraDepthSourceExposureTime, DepthSourceExposureTime) {
	const double MAX_EXPOSURE_VALUE = 999;
	const double SCALE_FACTOR = 0.1;

	const double setValue = GetParam();
	const double result = fmod(setValue, 4.0);

	switch (getDepthSourceExposureCameraType(CameraSDKFixture::modelName))
	{
	case CameraDepthSourceExposure::DepthSourceExposureCamera:
		testEnumValue(camera, scanning2d_setting::DepthSourceExposureMode::name, std::make_pair("Timed", 0));
		testDoubleValue(camera, scanning2d_setting::DepthSourceExposureTime::name, setValue * SCALE_FACTOR);
		break;

	default:
		std::cout << "The camera is not depth source series. Current camera is " << CameraSDKFixture::modelName << std::endl;
		break;
	}
}

INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraDepthSourceExposureTime, ::testing::Range(1, 9991, 1427));