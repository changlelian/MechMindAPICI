from mecheye.profiler_utils import *
from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase

@ddt
class TestCaseScanParameter(BaseTestCase):
    @data((SpotSelection.Value_Strongest, "Strongest"),
          (SpotSelection.Value_Nearest, "Nearest"),
          (SpotSelection.Value_Farthest, "Farthest"),
          (SpotSelection.Value_Invalid, "Invalid"))
    @unpack
    def test_case_spot_selection(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(SpotSelection.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(SpotSelection.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(SpotSelection.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    def test_case_min_spot_intensity(self):
        parameter_pointer = self.user_set.get_parameter(MinSpotIntensity.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_int_value(MinSpotIntensity.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(MinSpotIntensity.name)
        set_max_status = self.user_set.set_int_value(MinSpotIntensity.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(MinSpotIntensity.name)

        self.assertEquals(unit, '')
        self.assertEquals(get_min_value, set_min_value)
        self.assertEquals(get_max_value, set_max_value)
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertTrue(show_status(get_min_status))
        self.assertTrue(show_status(get_max_status))
        self.assertTrue(show_status(set_min_status))
        self.assertTrue(show_status(set_max_status))

    def test_case_max_spot_intensity(self):
        parameter_pointer = self.user_set.get_parameter(MaxSpotIntensity.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_int_value(MaxSpotIntensity.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(MaxSpotIntensity.name)
        set_max_status = self.user_set.set_int_value(MaxSpotIntensity.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(MaxSpotIntensity.name)

        self.assertEquals(unit, '')
        self.assertEquals(get_min_value, set_min_value)
        self.assertEquals(get_max_value, set_max_value)
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertTrue(show_status(get_min_status))
        self.assertTrue(show_status(get_max_status))
        self.assertTrue(show_status(set_min_status))
        self.assertTrue(show_status(set_max_status))

    def test_case_min_gray_scale_value(self):
        parameter_pointer = self.user_set.get_parameter(MinGrayscaleValue.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_int_value(MinGrayscaleValue.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(MinGrayscaleValue.name)
        set_max_status = self.user_set.set_int_value(MinGrayscaleValue.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(MinGrayscaleValue.name)

        self.assertEquals(unit, '')
        self.assertEquals(get_min_value, set_min_value)
        self.assertEquals(get_max_value, set_max_value)
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertTrue(show_status(get_min_status))
        self.assertTrue(show_status(get_max_status))
        self.assertTrue(show_status(set_min_status))
        self.assertTrue(show_status(set_max_status))

    def test_case_min_laser_line_width(self):
        parameter_pointer = self.user_set.get_parameter(MinLaserLineWidth.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_int_value(MinLaserLineWidth.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(MinLaserLineWidth.name)
        set_max_status = self.user_set.set_int_value(MinLaserLineWidth.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(MinLaserLineWidth.name)

        self.assertEquals(unit, '')
        self.assertEquals(get_min_value, set_min_value)
        self.assertEquals(get_max_value, set_max_value)
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertTrue(show_status(get_min_status))
        self.assertTrue(show_status(get_max_status))
        self.assertTrue(show_status(set_min_status))
        self.assertTrue(show_status(set_max_status))

    def test_case_max_laser_line_width(self):
        parameter_pointer = self.user_set.get_parameter(MaxLaserLineWidth.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_int_value(MaxLaserLineWidth.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(MaxLaserLineWidth.name)
        set_max_status = self.user_set.set_int_value(MaxLaserLineWidth.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(MaxLaserLineWidth.name)

        self.assertEquals(unit, '')
        self.assertEquals(get_min_value, set_min_value)
        self.assertEquals(get_max_value, set_max_value)
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertTrue(show_status(get_min_status))
        self.assertTrue(show_status(get_max_status))
        self.assertTrue(show_status(set_min_status))
        self.assertTrue(show_status(set_max_status))