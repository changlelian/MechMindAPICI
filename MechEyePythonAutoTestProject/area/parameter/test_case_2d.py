from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValid2DParameter(BaseTestCase):
    @data((Scanning2DExposureMode.Value_Timed, "Timed"),
          (Scanning2DExposureMode.Value_Auto, "Auto"),
          (Scanning2DExposureMode.Value_HDR, "HDR"),
          (Scanning2DExposureMode.Value_Flash, "Flash"))
    @unpack
    def test_case_2D_exposure_mode(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["no_flash_camera"] and \
                set_mode_enum != Scanning2DExposureMode.Value_Flash:

            set_mode_status = self.user_set.set_enum_value(Scanning2DExposureMode.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(Scanning2DExposureMode.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)

    @data(*range(1, 9991, 9989))
    def test_case_2D_exposure_time(self, set_value):
        if self.camera_info.model not in self.config_file["exposure_2d_timed"]["exposure_4_to_996"]:
            set_value *= 0.1
            set_exposure_status = self.user_set.set_float_value(Scanning2DExposureTime.name, set_value)
            get_exposure_status, get_value = self.user_set.get_float_value(Scanning2DExposureTime.name)

            self.assertTrue(show_status(set_exposure_status))
            self.assertTrue(show_status(get_exposure_status))
            self.assertAlmostEquals(set_value, get_value, places=5)

    @data(*range(4, 997, 4))
    def test_case_2D_exposure_time_4_to_996(self, set_value):
        if self.camera_info.model in self.config_file["exposure_2d_timed"]["exposure_4_to_996"]:
            set_exposure_status = self.user_set.set_float_value(Scanning2DExposureTime.name, set_value)
            get_exposure_status, get_value = self.user_set.get_float_value(Scanning2DExposureTime.name)

            self.assertTrue(show_status(set_exposure_status))
            self.assertTrue(show_status(get_exposure_status))
            self.assertAlmostEquals(set_value, get_value, places=5)

    @data(*([[0.1] * i for i in range(1, 6)] + [[999] * i for i in range(1, 6)]))
    @unpack
    def test_case_2D_HDR_exposure_sequence(self, *set_value):
        if self.camera_info.model not in self.config_file["exposure_2d_HDR"]["exposure_4_to_996"]:
            set_sequence_status = self.user_set.set_float_array_value(Scanning2DHDRExposureSequence.name, set_value)
            get_sequence_status, get_value = self.user_set.get_float_array_value(Scanning2DHDRExposureSequence.name)

            self.assertTrue(show_status(set_sequence_status))
            self.assertTrue(show_status(get_sequence_status))
            self.assertEquals(list(set_value), get_value)

    @data(*([[4] * i for i in range(1, 6)] + [[996] * i for i in range(1, 6)]))
    @unpack
    def test_case_2D_HDR_exposure_sequence_special(self, *set_value):
        if self.camera_info.model in self.config_file["exposure_2d_HDR"]["exposure_4_to_996"]:
            set_sequence_status = self.user_set.set_float_array_value(Scanning2DHDRExposureSequence.name, set_value)
            get_sequence_status, get_value = self.user_set.get_float_array_value(Scanning2DHDRExposureSequence.name)

            self.assertTrue(show_status(set_sequence_status))
            self.assertTrue(show_status(get_sequence_status))
            self.assertEquals(list(set_value), get_value)

    @data(False, True)
    def test_case_scan_2D_tone_mapping_enable(self, set_value):
        set_mapping_status = self.user_set.set_bool_value(Scanning2DToneMappingEnable.name, set_value)
        get_mapping_status, get_value = self.user_set.get_bool_value(Scanning2DToneMappingEnable.name)

        self.assertTrue(show_status(set_mapping_status))
        self.assertTrue(show_status(get_mapping_status))
        self.assertEquals(set_value, get_value)

    @data(*range(0, 256))
    def test_case_scan_2D_expected_gray_value(self, set_value):
        set_gray_status = self.user_set.set_int_value(Scanning2DExpectedGrayValue.name, set_value)
        get_gray_status, get_value = self.user_set.get_int_value(Scanning2DExpectedGrayValue.name)

        self.assertTrue(show_status(set_gray_status))
        self.assertTrue(show_status(get_gray_status))
        self.assertEquals(set_value, get_value)

    @data(*range(0, 50))
    def test_case_scan_2D_sharpen_factor(self, set_value):
        set_value *= 0.1
        set_factor_status = self.user_set.set_float_value(Scanning2DSharpenFactor.name, set_value)
        get_factor_status, get_value = self.user_set.get_float_value(Scanning2DSharpenFactor.name)

        self.assertTrue(show_status(set_factor_status))
        self.assertTrue(show_status(get_factor_status))
        self.assertAlmostEquals(set_value, get_value, places=5)

    @data((Scanning2DDepthSourceExposureMode.Value_Timed, "Timed"),
          (Scanning2DDepthSourceExposureMode.Value_Flash, "Flash"))
    @unpack
    def test_case_scan_2D_depth_source_exposure_mode(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["pattern_role_camera"]:
            set_mode_status = self.user_set.set_enum_value(Scanning2DDepthSourceExposureMode.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(Scanning2DDepthSourceExposureMode.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)

    @data(*range(1, 9991, 9989))
    def test_case_scan_2D_depth_exposure_time(self, set_value):
        if self.camera_info.model in self.config_file["pattern_role_camera"]:
            set_exposure_status = self.user_set.set_float_value(Scanning2DDepthSourceExposureTime.name, set_value * 0.1)
            get_exposure_status, get_value = self.user_set.get_float_value(Scanning2DDepthSourceExposureTime.name)

            self.assertTrue(show_status(set_exposure_status))
            self.assertTrue(show_status(get_exposure_status))
            self.assertEquals(set_value * 0.1, get_value)

    def test_case_scan_2D_roi(self):
        width = int(self.camera_resolution.texture.width)
        height = int(self.camera_resolution.texture.height)
        test_position_list = [[0, 0, width, height]] + \
                              [[0, 0, i, i] for i in range(int(height/2))] + \
                              [[width/2, height/2, i, i] for i in range(int(height/2))]

        for left, top, width, height in test_position_list:
            set_roi = ROI(int(left), int(top), int(width), int(height))

            set_roi_status = self.user_set.set_roi_value(Scanning2DAutoExposureROI.name, set_roi)
            get_roi_status, get_roi = self.user_set.get_roi_value(Scanning2DAutoExposureROI.name)

            self.assertTrue(show_status(set_roi_status))
            self.assertTrue(show_status(get_roi_status))
            self.assertEquals(set_roi.width, get_roi.width)
            self.assertEquals(set_roi.height, get_roi.height)
            self.assertEquals(set_roi.upper_left_x, get_roi.upper_left_x)
            self.assertEquals(set_roi.upper_left_y, get_roi.upper_left_y)


