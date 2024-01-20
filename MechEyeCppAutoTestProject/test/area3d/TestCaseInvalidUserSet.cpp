#include <iostream>
#include "area3d/CameraFixture.h"
#include "area3d/CameraFunction.h"

using namespace mmind::eye;

/**
*  Invalid SelectUserSet
*/

// Select not exist name
TEST_F(CameraInvalidUserSetsManager, SelectExistUserSet) {
	std::string testDescription = "Failed to set config name.";

	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.selectUserSet("GoogleTestMechMindNotExist"), -11, testDescription);
}


/**
*  Invalid AddUserSet
*/

// Add default name
TEST_F(CameraInvalidUserSetsManager, AddDefaultUserSet) {
	const std::string testDescription = "Failed to add config name.";

	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.addUserSet("default"), -11, testDescription);
}

// Add space name
TEST_F(CameraInvalidUserSetsManager, AddSpaceUserSet) {
	const std::string testDescription = "Input user set name is empty.";
	const std::string addName = "   ";

	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.addUserSet(addName),-7, testDescription);
	isIncludeUserSet(usm, addName, true);
}





/**
*  DeleteUserSet
*/

// Delete default
TEST_F(CameraInvalidUserSetsManager, DeleteDefaultUserSet) {
	const std::string testDescription = "Failed to delete config name.";
	const std::string name = "default";

	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.deleteUserSet(name), -11, testDescription);
	isIncludeUserSet(usm, name, false);

}

// Delete not exist
TEST_F(CameraInvalidUserSetsManager, DeleteNotExistUserSet) {
	std::string testDescription = "Failed to delete config name.";
	const std::string name = "GoogleTestMechMindNotExist";

	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.deleteUserSet(name), -11, testDescription);
}



/**
*  ReNameUserSet
*/

// Rename default name
TEST_F(CameraInvalidUserSetsManager, RenameDefaultUserSet) {
	std::string testDescription = "Failed to rename config group";
	const std::string name = "default";
	const std::string name1 = "RenameSDKNotExist";

	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.selectUserSet(name));
	testStautsSuccessful(usm.currentUserSet().rename(name1), -11, testDescription);
	isIncludeUserSet(usm, name, false);
	isIncludeUserSet(usm, name1, true);
}

// Rename name to space
TEST_F(CameraInvalidUserSetsManager, RenameNotExistUserSet) {
	const std::string name1 = " ";
	const std::string testDescription = "Input user set name is empty.";

	auto  usm = camera.userSetManager();
	const std::string name = "K" + CurrentTimeToString();
	testStautsSuccessful(usm.addUserSet(name));
	testStautsSuccessful(usm.selectUserSet(name));
	testStautsSuccessful(usm.currentUserSet().rename(name1), -7, testDescription);
	usm.deleteUserSet(name);
	isIncludeUserSet(usm, name1, true);
}

// Rename name to default
TEST_F(CameraInvalidUserSetsManager, RenameToExistUserSet) {
	const std::string testDescription = "Failed to rename config group";
	const std::string name1 = "default";

	auto  usm = camera.userSetManager();

	const std::string name = "T" + CurrentTimeToString();
	testStautsSuccessful(usm.addUserSet(name));
	testStautsSuccessful(usm.selectUserSet(name));
	testStautsSuccessful(usm.currentUserSet().rename("default"), -11, testDescription);
	usm.deleteUserSet(name);

	isIncludeUserSet(usm, name1, false);
}


TEST_F(CameraInvalidLoadSaveUserSets, loadUserSet) {
	const std::string testDescription = "Wrong file name passed.";
	const std::string testBlank = "";
	auto  usm = camera.userSetManager();
	testStautsSuccessful(usm.loadFromFile(testBlank), -8, testDescription);
}