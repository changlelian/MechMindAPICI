import os
import sys
import time
import shutil
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

    if os.path.exists(report_path):
        shutil.rmtree(report_path)

    if os.path.exists(files_path):
        shutil.rmtree(files_path)

    os.makedirs(report_path)
    os.makedirs(files_path)

    camera = Camera()
    profiler = Profiler()
    test_loader = unittest.TestLoader()

    camera_connect_status = camera.connect(ip_info, 1000000)
    profiler_connect_status = profiler.connect(ip_info, 1000000)


    test_case_vector = []
    if camera_connect_status.is_ok():
        test_case_vector.append(os.path.join(run_path, 'area'))

    elif profiler_connect_status.is_ok():
        test_case_vector.append(os.path.join(run_path, 'profiler'))

    elif ip_info == "127.0.0.1":
        test_case_vector.append(os.path.join(run_path, 'virtual_profiler'))

    allure_results_dir = os.path.join(run_path, 'report')
    pytest_args = []
    for test_dir in test_case_vector:
        pytest_args.append(test_dir)
    pytest_args += ['--alluredir', allure_results_dir, '-v']

    sys.exit(pytest.main(pytest_args))