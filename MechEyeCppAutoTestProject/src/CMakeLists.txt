cmake_minimum_required(VERSION 3.10) 

project(MechEyeCppAutoTestProject)

set(MIN_EYE_VERSION 2.2.0)

get_filename_component(PROJECT_DIR "${CMAKE_SOURCE_DIR}" DIRECTORY)


add_executable(MechEyeCppAutoTestProject
    jsoncpp.cpp
    ReadConfigFile.cpp
    GoogleTestMechMindSDK.cpp
    ProfilerVirtualFunction.cpp
    
    ${PROJECT_DIR}/test/TestFixture.cpp
    ${PROJECT_DIR}/test/CameraFunction.cpp
    ${PROJECT_DIR}/test/ProfilerFunction.cpp

    ${PROJECT_DIR}/test/area3d/TestCaseValid2d.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValid3d.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidUHP.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidLaser.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidMessage.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidUserSet.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidProjector.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidPointCloud.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidParameterAttribute.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseValidCouplingParameters.cpp

    ${PROJECT_DIR}/test/area3d/TestCaseInvalidUserSet.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseInvalid2d.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseInvalid3d.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseInvalidLaser.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseInvalidPointCloud.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseInvalidProjector.cpp
    ${PROJECT_DIR}/test/area3d/TestCaseInvalidUHP.cpp

    ${PROJECT_DIR}/test/profiler/virtual/TestCaseProfilerVirtual.cpp
    ${PROJECT_DIR}/test/profiler/virtual/TestCaseProfilerVirtualCapture.cpp

    ${PROJECT_DIR}/test/profiler/TestCaseValidScan.cpp
    ${PROJECT_DIR}/test/profiler/TestCaseValidRawImageParameters.cpp
    ${PROJECT_DIR}/test/profiler/TestCaseValidProfileProcessingParameters.cpp
    ${PROJECT_DIR}/test/profiler/TestCaseValidProfileExtractionParameters.cpp
    ${PROJECT_DIR}/test/profiler/TestCaseValidProfilerCouplingParameters.cpp



    # test_case/area/CameraFunction.cpp
    # test_case/profiler/ProfilerFunction.cpp

    # test_case/area/invalid/TestCaseInvalidUserSet.cpp
    # test_case/area/invalid/parameter/TestCaseInvalid2d.cpp
    # test_case/area/invalid/parameter/TestCaseInvalid3d.cpp
    # test_case/area/invalid/parameter/TestCaseInvalidPointCloud.cpp
    # test_case/area/invalid/parameter/TestCaseInvalidLaser.cpp
    # test_case/area/invalid/parameter/TestCaseInvalidProjector.cpp
    # test_case/area/invalid/parameter/TestCaseInvalidUHP.cpp

    # test_case/area/valid/TestCaseUserSet.cpp
    # test_case/area/valid/TestCaseMessage.cpp
    # test_case/area/valid/parameter/TestCase2d.cpp
    # test_case/area/valid/parameter/TestCase3d.cpp
    # test_case/area/valid/parameter/TestCasePointCloud.cpp
    # test_case/area/valid/parameter/TestCaseLaser.cpp
    # test_case/area/valid/parameter/TestCaseUHP.cpp
    # test_case/area/valid/parameter/TestCaseProjector.cpp
    # test_case/area/valid/parameter/TestParameterAttribute.cpp

    # test_case/profiler/valid/parameter/TestCaseScan.cpp
    # test_case/profiler/valid/parameter/TestCaseRawImageParameters.cpp
    # test_case/profiler/valid/parameter/TestCaseProfileExtractionParameters.cpp
    # test_case/profiler/valid/parameter/TestCaseProfileProcessingParameters.cpp
)


target_include_directories(MechEyeCppAutoTestProject PRIVATE 
    ${PROJECT_DIR}/include
    ${PROJECT_DIR}/test
)

set(RESOURCE_DIR ${PROJECT_DIR}/resource)
set(DEBUG_LIB_DIR ${PROJECT_DIR}/lib/debug)
set(RELEASE_LIB_DIR ${PROJECT_DIR}/lib/release)

message(${RESOURCE_DIR})
file(COPY ${RESOURCE_DIR} DESTINATION ${CMAKE_BINARY_DIR})


if(CMAKE_BUILD_TYPE MATCHES Debug)
    target_link_directories(MechEyeCppAutoTestProject PRIVATE ${DEBUG_LIB_DIR})
    target_compile_definitions(MechEyeCppAutoTestProject PRIVATE _ITERATOR_DEBUG_LEVEL=2)

    if (WIN32)
        target_compile_options(MechEyeCppAutoTestProject PRIVATE "/MDd")
        find_package(MechEyeApi ${MIN_EYE_VERSION} REQUIRED CONFIG PATHS "$ENV{MECHEYE_DIR}/API")
        if(NOT MechEyeApi_FOUND)
            message(FATAL_ERROR "MechEyeApi not found. Please install MechEyeApi with version ${MIN_EYE_VERSION} or higher.")
        endif()

        # 添加mecheye lib_debug文件的搜索路径
        target_link_directories(MechEyeCppAutoTestProject PRIVATE "$ENV{MECHEYE_DIR}/API/lib_debug")
        target_link_libraries(MechEyeCppAutoTestProject PRIVATE MechEyeApid)
    
    else()
        find_package(Threads REQUIRED)
        target_link_libraries(MechEyeCppAutoTestProject PRIVATE Threads::Threads)
        target_compile_options(MechEyeCppAutoTestProject PRIVATE -g)
    endif()
else()
    target_link_directories(MechEyeCppAutoTestProject PRIVATE ${RELEASE_LIB_DIR})
    target_compile_definitions(MechEyeCppAutoTestProject PRIVATE _ITERATOR_DEBUG_LEVEL=0)

    if (WIN32)
        target_compile_options(MechEyeCppAutoTestProject PRIVATE "/MD")
        find_package(MechEyeApi ${MIN_EYE_VERSION} REQUIRED CONFIG PATHS "$ENV{MECHEYE_DIR}/API")
        if(NOT MechEyeApi_FOUND)
            message(FATAL_ERROR "MechEyeApi not found. Please install MechEyeApi with version ${MIN_EYE_VERSION} or higher.")
        endif()
        target_compile_options(MechEyeCppAutoTestProject PRIVATE /MD)

        target_link_directories(MechEyeCppAutoTestProject PRIVATE "$ENV{MECHEYE_DIR}/API/lib")
        target_link_libraries(MechEyeCppAutoTestProject PRIVATE MechEyeApi)
    else()
        find_package(Threads REQUIRED)
        target_link_libraries(MechEyeCppAutoTestProject PRIVATE Threads::Threads)
        target_compile_options(MechEyeCppAutoTestProject PRIVATE -O3)

        # ubuntu下查找MechEye库
        find_package(PkgConfig)
        if(NOT PkgConfig_FOUND)
            message(FATAL_ERROR "PkgConfig not found.")
        else()
            pkg_check_modules(MECHEYEAPI REQUIRED MechEyeApi)
            if(NOT MECHEYEAPI_FOUND)
                message(FATAL_ERROR "MechEyeApi not found. Please install MechEyeApi first.")
            endif()
        endif()
    endif()
endif()

include_directories(${MECHEYEAPI_INCLUDE_DIRS})
link_directories(${MECHEYEAPI_LIBRARY_DIRS})
target_link_libraries(MechEyeCppAutoTestProject PRIVATE MechEyeApi gtest gmock)