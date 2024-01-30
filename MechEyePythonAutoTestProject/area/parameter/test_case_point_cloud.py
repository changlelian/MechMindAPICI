from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValidPointCloudParameter(BaseTestCase):
    @data((PointCloudSurfaceSmoothing.Value_Off, "Off"),
          (PointCloudSurfaceSmoothing.Value_Weak, "Weak"),
          (PointCloudSurfaceSmoothing.Value_Normal, "Normal"),
          (PointCloudSurfaceSmoothing.Value_Strong, "Strong"))
    @unpack
    def test_case_point_cloud_surface_smoothing(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(PointCloudSurfaceSmoothing.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(PointCloudSurfaceSmoothing.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertEquals(set_mode_enum, get_mode_enum)

    @data((PointCloudNoiseRemoval.Value_Off, "Off"),
          (PointCloudNoiseRemoval.Value_Weak, "Weak"),
          (PointCloudNoiseRemoval.Value_Normal, "Normal"),
          (PointCloudNoiseRemoval.Value_Strong, "Strong"))
    @unpack
    def test_case_point_cloud_noise_removal(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(PointCloudNoiseRemoval.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(PointCloudNoiseRemoval.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertEquals(set_mode_enum, get_mode_enum)

    @data((PointCloudOutlierRemoval.Value_Off, "Off"),
          (PointCloudOutlierRemoval.Value_Weak, "Weak"),
          (PointCloudOutlierRemoval.Value_Normal, "Normal"),
          (PointCloudOutlierRemoval.Value_Strong, "Strong"))
    @unpack
    def test_case_point_cloud_outlier_removal(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(PointCloudOutlierRemoval.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(PointCloudOutlierRemoval.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertEquals(set_mode_enum, get_mode_enum)

    @data((GapFilling.Value_Off, "Off"),
          (GapFilling.Value_Weak, "Weak"),
          (GapFilling.Value_Normal, "Normal"),
          (GapFilling.Value_Strong, "Strong"))
    @unpack
    def test_case_point_cloud_gap_filling(self, set_mode_enum, set_mode_string):
        if self.camera_info.model in self.config_file["frange_coding_mode"]["translucent"]:
            self.user_set.set_enum_value(ProjectorFringeCodingMode.name, ProjectorFringeCodingMode.Value_Translucent)

            set_mode_status = self.user_set.set_enum_value(GapFilling.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(GapFilling.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)

    @data((PointCloudEdgePreservation.Value_Normal, "Normal"),
          (PointCloudEdgePreservation.Value_Sharp, "Sharp"),
          (PointCloudEdgePreservation.Value_Smooth, "Smooth"))
    @unpack
    def test_case_point_cloud_edge_preservation(self, set_mode_enum, set_mode_string):
        if self.camera_info.model not in self.config_file["frange_coding_mode"]["translucent"]:
            self.user_set.set_enum_value(ProjectorFringeCodingMode.name, ProjectorFringeCodingMode.Value_Fast)

            set_mode_status = self.user_set.set_enum_value(PointCloudEdgePreservation.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(PointCloudEdgePreservation.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertEquals(set_mode_enum, get_mode_enum)

    @data(*range(1, 101))
    def test_case_point_cloud_fringe_contrast_threshold(self, set_value):
        self.user_set.set_enum_value(ProjectorFringeCodingMode.name, ProjectorFringeCodingMode.Value_Fast)

        set_contrast_status = self.user_set.set_int_value(PointCloudFringeContrastThreshold.name, set_value)
        get_contrast_status, get_value = self.user_set.get_int_value(PointCloudFringeContrastThreshold.name)

        self.assertTrue(show_status(set_contrast_status))
        self.assertTrue(show_status(get_contrast_status))
        self.assertEquals(set_value, get_value)

    @data(*range(1, 101))
    def test_case_point_cloud_fringe_min_threshold(self, set_value):
        self.user_set.set_enum_value(ProjectorFringeCodingMode.name, ProjectorFringeCodingMode.Value_Fast)

        set_contrast_status = self.user_set.set_int_value(PointCloudFringeMinThreshold.name, set_value)
        get_contrast_status, get_value = self.user_set.get_int_value(PointCloudFringeMinThreshold.name)

        self.assertTrue(show_status(set_contrast_status))
        self.assertTrue(show_status(get_contrast_status))
        self.assertEquals(set_value, get_value)


