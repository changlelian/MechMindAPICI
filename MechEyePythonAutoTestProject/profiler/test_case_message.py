from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.profiler import *


@ddt
class TestCaseValidMessageParameter(BaseTestCase):

    def test_case_get_all_camera(self):
        profiler_infos = Profiler.discover_profilers()
        self.assertGreater(len(profiler_infos), 0)

    def test_case_get_camera_info(self):
        self.profiler_infos = ProfilerInfo()
        self.profiler.get_profiler_info(self.profiler_infos)

        self.assertTrue(self.profiler_infos.model)
        self.assertTrue(self.profiler_infos.ip_address)
        self.assertTrue(self.profiler_infos.subnet_mask)
        self.assertEqual(int(self.profiler_infos.port), 5577)
        self.assertTrue(self.profiler_infos.sensor_sn)
        self.assertTrue(self.profiler_infos.controller_sn)
        self.assertTrue(self.profiler_infos.hardware_version.to_string())
        self.assertTrue(self.profiler_infos.firmware_version.to_string())