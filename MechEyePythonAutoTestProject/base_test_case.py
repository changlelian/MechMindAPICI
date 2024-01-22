import json
import os
import sys
import unittest
from mecheye.shared import *
from mecheye.area_scan_3d_camera import *
from mecheye.profiler_utils import *

work_space = os.path.dirname(__file__)

def read_json_file():
    json_path = os.path.join(work_space,"config.json")
    with open(json_path, "r", encoding="utf-8") as f:
        return dict(json.load(f))


class BaseTestCase(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.camera = Camera()
        cls.profiler = Profiler()

        ip_info = os.environ.get('IP_INFO')
        print(f"Current test ip: {ip_info}")
        cls.config_file = read_json_file()
        print(get_api_version_info())

        camera_connect_status = cls.camera.connect(ip_info, 1000000)
        profiler_connect_status = cls.profiler.connect(ip_info, 1000000)

        if not camera_connect_status.is_ok() and not profiler_connect_status.is_ok():
            print(camera_connect_status.error_description)
            print("MechEye-API connect deviced fail, program exit unormal!")
            os._exit(1)

        elif camera_connect_status.is_ok():
            cls.user_set_manager = cls.camera.user_set_manager()
            cls.user_set = cls.camera.current_user_set()
            cls.user_set.reset_all_parameters_to_default_values()

            cls.camera_info = CameraInfo()
            cls.camera.get_camera_info(cls.camera_info)

            cls.camera_resolution = CameraResolutions()
            cls.camera.get_camera_resolutions(cls.camera_resolution)

            cls.frame_2d = Frame2D()
            cls.frame_3d = Frame3D()
            cls.frame_2d_and_3d = Frame2DAnd3D()

        elif profiler_connect_status.is_ok():
            cls.user_set_manager = cls.profiler.user_set_manager()
            cls.user_set = cls.profiler.current_user_set()
            cls.user_set.reset_all_parameters_to_default_values()

            cls.profiler_info = ProfilerInfo()
            cls.profiler.get_profiler_info(cls.profiler_info)

    @classmethod
    def tearDownClass(cls):
        print("Test case execute over, disconnect!")
        cls.camera.disconnect()

