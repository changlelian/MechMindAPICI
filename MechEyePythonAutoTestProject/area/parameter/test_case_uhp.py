from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValidUhpParameter(BaseTestCase):
    @data((UhpCaptureMode.Value_Camera1, "Camera1"),
          (UhpCaptureMode.Value_Camera2, "Camera2"),
          (UhpCaptureMode.Value_Merge, "Merge"))
    @unpack
    def test_case_2D_exposure_mode(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["uhp_camera"]:
            set_mode_status = self.user_set.set_enum_value(Scanning2DExposureMode.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(Scanning2DExposureMode.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)