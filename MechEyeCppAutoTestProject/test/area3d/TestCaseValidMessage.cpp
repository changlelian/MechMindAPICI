#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"

using namespace mmind::eye;




/**
*  CameraInfo
*/

TEST_F(CameraMessage, CameraInfo) {
	CameraInfo info;
	testStautsSuccessful(camera.getCameraInfo(info));

	EXPECT_EQ(info.model, modelName);
	EXPECT_NE(info.serialNumber, "");
	EXPECT_NE(info.ipAddress, "");
	EXPECT_NE(info.subnetMask, "");
	EXPECT_EQ(info.port, 5577);
	EXPECT_NE(info.firmwareVersion.toString(), "");
	EXPECT_NE(info.hardwareVersion.toString(), "");

	switch (info.ipAssignmentMethod)
	{
	case mmind::eye::IpAssignmentMethod::Unknown:
		FAIL();
	case mmind::eye::IpAssignmentMethod::DHCP:
		break;
	case mmind::eye::IpAssignmentMethod::Static:
		break;
	case mmind::eye::IpAssignmentMethod::LLA:
		break;
	default:
		break;
	}
}



/**
*  CameraStatus
*/

TEST_F(CameraMessage, CameraStatus) {
	CameraStatus camStatus;
	testStautsSuccessful(camera.getCameraStatus(camStatus));
	EXPECT_NE(camStatus.temperature.projectorTemperature, 0);
	EXPECT_NE(camStatus.temperature.cpuTemperature, 0);

	}

/**
*  CameraResolution
*/
TEST_F(CameraMessage, CameraResolution) {
	CameraResolutions camResolution;
	testStautsSuccessful(camera.getCameraResolutions(camResolution));

	EXPECT_NE(camResolution.depth.height, 0);
	EXPECT_NE(camResolution.depth.width, 0);
	EXPECT_NE(camResolution.texture.height, 0);
	EXPECT_NE(camResolution.texture.width, 0);
}