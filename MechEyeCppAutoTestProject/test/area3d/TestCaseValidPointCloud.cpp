#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"
#include "area_scan_3d_camera/parameters/PointCloudProcessing.h"

using namespace mmind::eye;


TEST_P(CameraParametersPointCloudSurfaceSmoothing, PointCloudSurfaceSmoothing) {

	std::pair<std::string, int> modeMap = GetParam();
	testEnumValue(camera, pointcloud_processing_setting::SurfaceSmoothing::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudSurfaceSmoothing,
	::testing::Values(std::make_pair("Off", 0), std::make_pair("Weak", 1), std::make_pair("Normal", 2), std::make_pair("Strong", 3)));



TEST_P(CameraParametersPointCloudNoiseRemoval, PointCloudNoiseRemoval) {

	std::pair<std::string, int> modeMap = GetParam();
	testEnumValue(camera, pointcloud_processing_setting::NoiseRemoval::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudNoiseRemoval,
	::testing::Values(std::make_pair("Off", 0), std::make_pair("Weak", 1), std::make_pair("Normal", 2), std::make_pair("Strong", 3)));



TEST_P(CameraParametersPointCloudOutlierRemoval, PointCloudOutlierRemoval) {

	std::pair<std::string, int> modeMap = GetParam();
	testEnumValue(camera, pointcloud_processing_setting::OutlierRemoval::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudOutlierRemoval,
	::testing::Values(std::make_pair("Off", 0), std::make_pair("Weak", 1), std::make_pair("Normal", 2),std::make_pair("Strong", 3)));



TEST_P(CameraParametersPointCloudEdgePreservation, PointCloudEdgePreservation) {

	std::pair<std::string, int> modeMap = GetParam();
	testEnumValue(camera, pointcloud_processing_setting::EdgePreservation::name, modeMap);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudEdgePreservation,
	::testing::Values(std::make_pair("Sharp", 0), std::make_pair("Normal", 1), std::make_pair("Smooth", 2)));



TEST_P(CameraParametersPointCloudGapFilling, PointCloudGapFilling) {

	std::pair<std::string, int> modeMap = GetParam();

	switch (getProjectorCodingTranslucentModeCameraType(modelName))
	{
	case CameraProjectorCodingTranslucentMode::TranslucentModeCamera:
		testEnumValue(camera, pointcloud_processing_setting::GapFilling::name, modeMap);
		break;
	default:
		std::cout << "The camera is not PRO series" << std::endl;
		break;
	}
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudGapFilling,
	::testing::Values(std::make_pair("Off", 0), std::make_pair("Weak", 1), std::make_pair("Normal", 2), std::make_pair("Strong", 3)));




TEST_P(CameraParametersPointCloudFringeContrastThreshold, FringeContrastThreshold) {
	const int setValue = GetParam();
	testIntValue(camera, pointcloud_processing_setting::FringeContrastThreshold::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudFringeContrastThreshold, ::testing::Range(1, 101));



TEST_P(CameraParametersPointCloudFringeMinThreshold, FringeMinThreshold) {
	const int setValue = GetParam();
	testIntValue(camera, pointcloud_processing_setting::FringeMinThreshold::name, setValue);
}
INSTANTIATE_TEST_SUITE_P(CameraParametersTest, CameraParametersPointCloudFringeMinThreshold, ::testing::Range(1, 101));
