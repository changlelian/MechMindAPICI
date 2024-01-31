from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValidProjectorParameter(BaseTestCase):
    @data((ProjectorPowerLevel.Value_High, "High"),
          (ProjectorPowerLevel.Value_Normal, "Normal"),
          (ProjectorPowerLevel.Value_Low, "Low"))
    @unpack
    def test_case_projector_power_level(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["projector_power_level_camera"]:
            set_mode_status = self.user_set.set_enum_value(ProjectorPowerLevel.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(ProjectorPowerLevel.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)

    def set_and_get_mode(self, mode_enum):
        set_mode_status = self.user_set.set_enum_value(ProjectorFringeCodingMode.name, mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(ProjectorFringeCodingMode.name)
        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertEqual(mode_enum, get_mode_enum)


    @data((ProjectorFringeCodingMode.Value_Fast, "Fast"),
          (ProjectorFringeCodingMode.Value_Accurate, "Accurate"),
          (ProjectorFringeCodingMode.Value_Translucent, "Translucent"),
          (ProjectorFringeCodingMode.Value_Reflective, "Reflective"))
    @unpack
    def test_case_projector_fringe_coding_mode(self, set_mode_enum, set_mode_string):
        if self.camera_info.model not in self.config_file["projector_coding_mode_camera"]:
            return

        if set_mode_enum == ProjectorFringeCodingMode.Value_Fast or \
                set_mode_enum == ProjectorFringeCodingMode.Value_Accurate:
            self.set_and_get_mode(set_mode_enum)

        if self.camera_info.model in self.config_file["frange_coding_mode"]["translucent"] and \
                set_mode_enum != ProjectorFringeCodingMode.Value_Reflective:
            self.set_and_get_mode(set_mode_enum)

        if self.camera_info.model in self.config_file["frange_coding_mode"]["reflective"] and \
                set_mode_enum != ProjectorFringeCodingMode.Value_Translucent:
            self.set_and_get_mode(set_mode_enum)

    @data((AntiFlickerMode.Value_Off, "Off"),
          (AntiFlickerMode.Value_AC50Hz, "AC50Hz"),
          (AntiFlickerMode.Value_AC60Hz, "AC60Hz")
          )
    @unpack
    def test_case_projector_Anti_flicker(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["projector_anti_flicker_camera"]:
            set_mode_status = self.user_set.set_enum_value(AntiFlickerMode.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(AntiFlickerMode.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)