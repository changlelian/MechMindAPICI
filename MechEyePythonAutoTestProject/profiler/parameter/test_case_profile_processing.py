from mecheye.profiler_utils import *
from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase

@ddt
class TestCaseScanParameter(BaseTestCase):
    @data((Filter.Value__None, "None"),
          (Filter.Value_Mean, "Mean"),
          (Filter.Value_Median, "Median"))
    @unpack
    def test_case_filter(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(Filter.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(Filter.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(Filter.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((Filter.Value__None, "None"),
          (Filter.Value_Mean, "Mean"),
          (Filter.Value_Median, "Median"))
    @unpack
    def test_case_filter(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(Filter.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(Filter.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(Filter.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((MeanFilterWindowSize.Value_WindowSize_2, "WindowSize_2"),
          (MeanFilterWindowSize.Value_WindowSize_4, "WindowSize_4"),
          (MeanFilterWindowSize.Value_WindowSize_8, "WindowSize_8"),
          (MeanFilterWindowSize.Value_WindowSize_16, "WindowSize_16"),
          (MeanFilterWindowSize.Value_WindowSize_32, "WindowSize_32"))
    @unpack
    def test_case_mean_filter_window_size(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(MeanFilterWindowSize.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(MeanFilterWindowSize.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(MeanFilterWindowSize.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((MedianFilterWindowSize.Value_WindowSize_3, "WindowSize_3"),
          (MedianFilterWindowSize.Value_WindowSize_5, "WindowSize_5"),
          (MedianFilterWindowSize.Value_WindowSize_7, "WindowSize_7"),
          (MedianFilterWindowSize.Value_WindowSize_9, "WindowSize_9"))
    @unpack
    def test_case_median_filter_window_size(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(MedianFilterWindowSize.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(MedianFilterWindowSize.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(MedianFilterWindowSize.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data(*range(0, 17))
    def test_case_gap_filling(self, set_value):
        set_status = self.user_set.set_int_value(GapFilling.name, set_value)
        get_status, get_value = self.user_set.get_int_value(GapFilling.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

    @data(*range(0, 17))
    def test_case_gap_filling_edge_preservation(self, set_value):
        set_status = self.user_set.set_int_value(GapFilling.name, set_value)
        get_status, get_value = self.user_set.get_int_value(GapFilling.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)