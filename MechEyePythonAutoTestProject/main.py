import os
import sys
import time
import unittest
import pytest
from area import *
from BeautifulReport import BeautifulReport
from mecheye.area_scan_3d_camera import *
from mecheye.profiler_utils import *


if __name__ == '__main__':
    if len(sys.argv) != 2:
        raise Exception("Error: please input correct run commond, such as: python [main.py] [device IP]")
    os.environ['IP_INFO'] = sys.argv.pop(1)
    ip_info = os.environ.get('IP_INFO')
    run_path = os.path.dirname(__file__)
    report_path = os.path.join(run_path, 'report')
    files_path = os.path.join(run_path, 'files')

    if not os.path.exists(report_path):
        os.makedirs(report_path)

    if not os.path.exists(files_path):
        os.makedirs(files_path)

    camera = Camera()
    profiler = Profiler()
    test_loader = unittest.TestLoader()

    camera_connect_status = camera.connect(ip_info, 1000000)
    profiler_connect_status = profiler.connect(ip_info, 1000000)


    test_case_vector = []
    if camera_connect_status.is_ok():
        test_suite1 = test_loader.discover(os.path.join(run_path, 'area'), pattern='test_case*.py')
        # test_suite2 = test_loader.discover('area/capture', pattern='test_case*.py')
        # test_suite3 = test_loader.discover(os.path.join(run_path, 'area', 'parameter'), pattern='test_case*.py')
        # test_case_vector.append(test_suite1)
        # test_case_vector.append(test_suite2)
        #test_case_vector.append(test_suite3)

        test_case_vector.append(os.path.join(run_path, 'area'))
        test_case_vector.append(os.path.join(run_path, 'area', 'parameter'))

    elif profiler_connect_status.is_ok():
        # test_suite1 = test_loader.discover(os.path.join(run_path, 'profiler'), pattern='test_case*.py')
        # test_suite2 = test_loader.discover(os.path.join(run_path, 'profiler', 'capture'), pattern='test_case*.py')
        # test_suite3 = test_loader.discover(os.path.join(run_path, 'profiler', 'parameter'), pattern='test_case*.py')
        # test_case_vector.append(test_suite1)
        # test_case_vector.append(test_suite2)
        # test_case_vector.append(test_suite3)

        test_case_vector.append(os.path.join(run_path, 'profiler'))
        test_case_vector.append(os.path.join(run_path, 'profiler', 'capture'))
        test_case_vector.append(os.path.join(run_path, 'profiler', 'parameter'))

    # combined_test_suite = unittest.TestSuite(test_case_vector)
    # runner = unittest.TextTestRunner()
    # result = runner.run(combined_test_suite)

    # cur_time = time.strftime('%Y-%m-%d_%H-%M-%S', time.localtime(time.time()))
    # file_name = 'MechEyeAPI_{}_自动化测试报告{}'.format(str(ip_info), str(cur_time))

    # result = BeautifulReport(combined_test_suite)
    # result.report(filename=file_name,
    #               description='MechEyeAPI结构光相机自动化测试报告',
    #               report_dir='./report', theme='theme_default')

    allure_results_dir = os.path.join(run_path, 'report')
    pytest_args = []
    for test_dir in test_case_vector:
        pytest_args.append(test_dir)
    pytest_args += ['--alluredir', allure_results_dir, '-v']

    sys.exit(pytest.main(pytest_args))