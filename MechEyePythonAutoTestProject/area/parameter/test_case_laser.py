from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValidLaserParameter(BaseTestCase):
    @data((LaserFringeCodingMode.Value_Fast, "Fast"),
          (LaserFringeCodingMode.Value_Accurate, "Accurate"))
    @unpack
    def test_case_laser_fringe_coding_mode(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["laser_camera"]:
            set_mode_status = self.user_set.set_enum_value(LaserFringeCodingMode.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(LaserFringeCodingMode.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)
        else:
            print(f"The camera is not Laser series. Current {self.camera_info.model}")

    @data(*range(50, 101))
    def test_case_laser_power_level(self, set_value):
        if self.camera_info.model in self.config_file["laser_camera"]:
            set_laser_status = self.user_set.set_int_value(LaserPowerLevel.name, set_value)
            get_laser_status, get_value = self.user_set.get_int_value(LaserPowerLevel.name)

            self.assertTrue(show_status(set_laser_status))
            self.assertTrue(show_status(get_laser_status))
            self.assertEquals(set_value, get_value)
        else:
            print(f"The camera is not Laser series. Current {self.camera_info.model}")

    @data(*range(1, 5))
    def test_case_laser_frame_partition_count(self, set_value):
        if self.camera_info.model in self.config_file["laser_camera"]:
            set_laser_status = self.user_set.set_int_value(LaserFramePartitionCount.name, set_value)
            get_laser_status, get_value = self.user_set.get_int_value(LaserFramePartitionCount.name)

            self.assertTrue(show_status(set_laser_status))
            self.assertTrue(show_status(get_laser_status))
            self.assertEquals(set_value, get_value)
        else:
            print(f"The camera is not Laser series. Current {self.camera_info.model}")

    @data(*([[0, i] for i in range(25, 101)] + [[i, 25 + i] for i in range(0, 76)]))
    def test_case_laser_frame_range(self, set_value):
        if self.camera_info.model in self.config_file["laser_camera"]:
            set_range = RangeInt(set_value[0], set_value[1])
            set_laser_status = self.user_set.set_range_value(LaserFrameRange.name, set_range)
            get_laser_status, get_range = self.user_set.get_range_value(LaserFrameRange.name)

            self.assertTrue(show_status(set_laser_status))
            self.assertTrue(show_status(get_laser_status))
            self.assertEquals(set_range.min, get_range.min)
            self.assertEquals(set_range.max, get_range.max)
        else:
            print(f"The camera is not Laser series. Current {self.camera_info.model}")