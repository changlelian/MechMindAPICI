from mecheye.profiler_utils import *
from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase

@ddt
class TestCaseScanParameter(BaseTestCase):
    @data((ExposureMode.Value_HDR, "HDR"),
          (ExposureMode.Value_Timed, "Timed"))
    @unpack
    def test_case_exposure_mode(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(ExposureMode.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(ExposureMode.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(ExposureMode.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((AnalogGain.Value_Gain_1_0, "Gain_1_0"),
          (AnalogGain.Value_Gain_1_3, "Gain_1_3"),
          (AnalogGain.Value_Gain_1_9, "Gain_1_9"),
          (AnalogGain.Value_Gain_2_8, "Gain_2_8"),
          (AnalogGain.Value_Gain_5_5, "Gain_5_5"))
    @unpack
    def test_case_analog_gain(self, set_mode_enum, set_mode_string):
        if self.profiler_info.model not in self.config_file["analog_gain"]["gain_for_8030"][0]:
            print(self.config_file["analog_gain"]["gain_for_8030"][0], self.profiler_info.model)
            set_mode_status = self.user_set.set_enum_value(AnalogGain.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(AnalogGain.name)
            get_string_status, get_mode_string = self.user_set.get_enum_value_string(AnalogGain.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertTrue(show_status(get_string_status))
            self.assertEquals(set_mode_enum, get_mode_enum)
            self.assertEquals(set_mode_string, get_mode_string)

    @data((AnalogGainFor8030.Value_Gain_1_0, "Gain_1_0"),
          (AnalogGainFor8030.Value_Gain_1_3, "Gain_1_3"),
          (AnalogGainFor8030.Value_Gain_2_0, "Gain_2_0"),
          (AnalogGainFor8030.Value_Gain_3_0, "Gain_3_0"))
    @unpack
    def test_case_analog_gain_for_8030(self, set_mode_enum, set_mode_string):
        if self.profiler_info.model in self.config_file["analog_gain"]["gain_for_8030"][0]:
            set_mode_status = self.user_set.set_enum_value(AnalogGainFor8030.name, set_mode_enum)
            get_mode_status, get_mode_enum = self.user_set.get_enum_value(AnalogGainFor8030.name)
            get_string_status, get_mode_string = self.user_set.get_enum_value_string(AnalogGainFor8030.name)

            self.assertTrue(show_status(set_mode_status))
            self.assertTrue(show_status(get_mode_status))
            self.assertTrue(show_status(get_string_status))
            self.assertEquals(set_mode_enum, get_mode_enum)
            self.assertEquals(set_mode_string, get_mode_string)

    @data((ZDirectionRoi.Value_ImageHeight_1_1, "ImageHeight_1_1"),
          (ZDirectionRoi.Value_ImageHeight_1_2, "ImageHeight_1_2"),
          (ZDirectionRoi.Value_ImageHeight_1_4, "ImageHeight_1_4"),
          (ZDirectionRoi.Value_ImageHeight_1_8, "ImageHeight_1_8"),
          (ZDirectionRoi.Value_ImageHeight_1_16, "ImageHeight_1_16"))
    @unpack
    def test_case_z_direction_roi(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(ZDirectionRoi.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(ZDirectionRoi.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(ZDirectionRoi.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    def test_case_digital_gain(self):
        parameter_pointer = self.user_set.get_parameter(DigitalGain.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_int_value(DigitalGain.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(DigitalGain.name)
        set_max_status = self.user_set.set_int_value(DigitalGain.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(DigitalGain.name)

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

    @data(*range(40, 101, 1))
    def test_case_laser_power(self, set_value):
        set_status = self.user_set.set_int_value(LaserPower.name, set_value)
        get_status, get_value = self.user_set.get_int_value(LaserPower.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

