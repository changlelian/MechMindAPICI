#include <iostream>
#include <cmath>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/Scanning3D.h"

using namespace mmind::eye;



// [Scan3DExposureSequence]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan3DExposureSequence, Scan3DExposureSequenceDoubleArray) {
	const double setValue = GetParam();
	const double result = fmod(setValue, 4.0);

	switch (getCamera3DExposureType(modelName))
	{
	// Normal
	case Camera3DExposure::Exposure3DOther:
		testDoubleValue(camera, scanning3d_setting::ExposureSequence::name, setValue *  0.1, 3);
		break;
	// Laser
	case Camera3DExposure::Exposure43D:
		if (setValue < 99 && result == 0.0) {
			testDoubleValue(camera, scanning3d_setting::ExposureSequence::name, setValue, 3);
		}
		break;
	// LSR
	case Camera3DExposure::Exposure83D:
		if (setValue >= 8 && setValue <= 96 && result == 0.0) {
			testDoubleValue(camera, scanning3d_setting::ExposureSequence::name, setValue, 3);
		}
		break;
	// Pro L Enhanecd
	case Camera3DExposure::Exposure453D:
		if (setValue <= 450){
			testDoubleValue(camera, scanning3d_setting::ExposureSequence::name, setValue * 0.1, 3);
		}		
		break;
	default:
		FAIL();
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan3DExposureSequence, ::testing::Range(1, 991));



// [DepthRange]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraDepthRange, CameraCameraDepthRangeDouble) {
	const int setValue = GetParam();
	// by namespace
	testRangeValue(camera, scanning3d_setting::DepthRange::name, setValue, 4000);  //window width=4000
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraDepthRange, ::testing::Range(1, 5000));




// [Scan3DGain]: Testing the [set/getIntValue] Interface with Normal Values
TEST_P(CameraScan3DGain, CameraScan3DGainDouble) {
	const double setValue = GetParam() * 0.1;
	// by namespace
	testDoubleValue(camera, scanning3d_setting::Gain::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraScan3DGain, ::testing::Range(0, 161));




// [Scan3DROI]: Testing the [set/getIntValue] Interface with Normal Values
TEST_F(CameraScan3DROI, Scan3DROIRoi) {

	// height < width
	for (int roiHeight = 0; roiHeight <= depthHeightResolution; roiHeight++)
	{
		ROI setRoi(0, 0, roiHeight, roiHeight);
		testROIValue(camera, scanning3d_setting::ROI::name, setRoi);
	}

	ROI setRoi1(0, 0, depthWidthResolution, depthHeightResolution);
	testROIValue(camera, scanning3d_setting::ROI::name, setRoi1);

	// height < width
	for (int roiHeight = 0; roiHeight <= depthHeightResolution/2; roiHeight++)
	{
		ROI setRoi(depthWidthResolution / 2, depthHeightResolution/2, roiHeight, roiHeight);
		testROIValue(camera, scanning3d_setting::ROI::name, setRoi);
	}

	ROI setRoi2(depthWidthResolution / 2, depthHeightResolution / 2, depthWidthResolution/2, depthHeightResolution/2);
	testROIValue(camera, scanning3d_setting::ROI::name, setRoi2);

	ROI setRoi3(depthWidthResolution, depthHeightResolution, 0, 0);
	testROIValue(camera, scanning3d_setting::ROI::name, setRoi3);
}


