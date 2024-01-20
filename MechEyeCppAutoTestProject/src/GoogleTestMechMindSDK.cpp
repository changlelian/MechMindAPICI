#include <iostream>
#include "gtest/gtest.h"
#include "TestFixture.h"
#include "ReadConfigFile.h"


int main(int argc, char** argv) {
	ParseCommandLine(argc, argv);  // read from console

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}