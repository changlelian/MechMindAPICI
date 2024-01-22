from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValid3DParameter(BaseTestCase):

    @data(*([[4] * i for i in range(1, 4)] + [[96] * i for i in range(1, 4)]))
    @unpack
    def test_case_2D_HDR_exposure_sequence_4_96(self, *set_value):
        if self.camera_info.model in self.config_file["exposure_3d"]["exposure_4_to_96"]:
            set_sequence_status = self.user_set.set_float_array_value(Scanning3DExposureSequence.name, set_value)
            get_sequence_status, get_value = self.user_set.get_float_array_value(Scanning3DExposureSequence.name)

            self.assertTrue(show_status(set_sequence_status))
            self.assertTrue(show_status(get_sequence_status))
            self.assertEquals(list(set_value), get_value)

    @data(*([[8] * i for i in range(1, 4)] + [[96] * i for i in range(1, 4)]))
    @unpack
    def test_case_2D_HDR_exposure_sequence_8_96(self, *set_value):
        if self.camera_info.model in self.config_file["exposure_3d"]["exposure_8_to_96"]:
            set_sequence_status = self.user_set.set_float_array_value(Scanning3DExposureSequence.name, set_value)
            get_sequence_status, get_value = self.user_set.get_float_array_value(Scanning3DExposureSequence.name)

            self.assertTrue(show_status(set_sequence_status))
            self.assertTrue(show_status(get_sequence_status))
            self.assertEquals(list(set_value), get_value)

    @data(*([[0.1] * i for i in range(1, 4)] + [[45] * i for i in range(1, 4)]))
    @unpack
    def test_case_2D_HDR_exposure_sequence_0_1_45(self, *set_value):
        if self.camera_info.model in self.config_file["exposure_3d"]["exposure_0_1_to_45"]:
            set_sequence_status = self.user_set.set_float_array_value(Scanning3DExposureSequence.name, set_value)
            get_sequence_status, get_value = self.user_set.get_float_array_value(Scanning3DExposureSequence.name)

            self.assertTrue(show_status(set_sequence_status))
            self.assertTrue(show_status(get_sequence_status))
            self.assertEquals(list(set_value), get_value)

    @data(*([[0.1] * i for i in range(1, 4)] + [[99] * i for i in range(1, 4)]))
    @unpack
    def test_case_2D_HDR_exposure_sequence(self, *set_value):
        if self.camera_info.model not in self.config_file["exposure_3d"]["exposure_0_1_to_45"] and \
           self.camera_info.model not in self.config_file["exposure_3d"]["exposure_4_to_96"] and \
           self.camera_info.model not in self.config_file["exposure_3d"]["exposure_8_to_96"]:

            set_sequence_status = self.user_set.set_float_array_value(Scanning3DExposureSequence.name, set_value)
            get_sequence_status, get_value = self.user_set.get_float_array_value(Scanning3DExposureSequence.name)

            self.assertTrue(show_status(set_sequence_status))
            self.assertTrue(show_status(get_sequence_status))
            self.assertEquals(list(set_value), get_value)

    @data(*range(0, 161))
    def test_case_scan_3D_gain(self, set_value):
        set_value *= 0.1
        set_gain_status = self.user_set.set_float_value(Scanning3DGain.name, set_value)
        get_gain_status, get_value = self.user_set.get_float_value(Scanning3DGain.name)

        self.assertTrue(show_status(set_gain_status))
        self.assertTrue(show_status(get_gain_status))
        self.assertAlmostEquals(set_value, get_value, places=5)

    def test_case_scan_3D_roi(self):
        width = int(self.camera_resolution.depth.width)
        height = int(self.camera_resolution.depth.height)
        test_position_list = [[0, 0, width, height]] + \
                              [[0, 0, i, i] for i in range(int(height/2))] + \
                              [[width/2, height/2, i, i] for i in range(int(height/2))]

        for left, top, width, height in test_position_list:
            set_roi = ROI(int(left), int(top), int(width), int(height))

            set_roi_status = self.user_set.set_roi_value(Scanning3DROI.name, set_roi)
            get_roi_status, get_roi = self.user_set.get_roi_value(Scanning3DROI.name)

            self.assertTrue(show_status(set_roi_status))
            self.assertTrue(show_status(get_roi_status))
            self.assertEquals(set_roi.width, get_roi.width)
            self.assertEquals(set_roi.height, get_roi.height)
            self.assertEquals(set_roi.upper_left_x, get_roi.upper_left_x)
            self.assertEquals(set_roi.upper_left_y, get_roi.upper_left_y)