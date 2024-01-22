from mecheye.profiler_utils import *
from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase



@ddt
class TestCaseScanParameter(BaseTestCase):
    @data((DataAcquisitionTriggerSource.Value_Software, "Software"),
          (DataAcquisitionTriggerSource.Value_External, "External"))
    @unpack
    def test_case_data_acquisition_trigger_source(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(DataAcquisitionTriggerSource.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(DataAcquisitionTriggerSource.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(DataAcquisitionTriggerSource.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((LineScanTriggerSource.Value_FixedRate, "FixedRate"),
          (LineScanTriggerSource.Value_Encoder, "Encoder"))
    @unpack
    def test_case_line_scan_trigger_source(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(LineScanTriggerSource.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(LineScanTriggerSource.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(LineScanTriggerSource.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((EncoderTriggerDirection.Value_ChannelALeading, "ChannelALeading"),
          (EncoderTriggerDirection.Value_ChannelBLeading, "ChannelBLeading"),
          (EncoderTriggerDirection.Value_Both, "Both"))
    @unpack
    def test_case_encoder_trigger_direction(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(EncoderTriggerDirection.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(EncoderTriggerDirection.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(EncoderTriggerDirection.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    @data((EncoderTriggerSignalCountingMode.Value_Multiple_1, "Multiple_1"),
          (EncoderTriggerSignalCountingMode.Value_Multiple_2, "Multiple_2"),
          (EncoderTriggerSignalCountingMode.Value_Multiple_4, "Multiple_4"))
    @unpack
    def test_case_encoder_trigger_direction(self, set_mode_enum, set_mode_string):
        set_mode_status = self.user_set.set_enum_value(EncoderTriggerSignalCountingMode.name, set_mode_enum)
        get_mode_status, get_mode_enum = self.user_set.get_enum_value(EncoderTriggerSignalCountingMode.name)
        get_string_status, get_mode_string = self.user_set.get_enum_value_string(EncoderTriggerSignalCountingMode.name)

        self.assertTrue(show_status(set_mode_status))
        self.assertTrue(show_status(get_mode_status))
        self.assertTrue(show_status(get_string_status))
        self.assertEquals(set_mode_enum, get_mode_enum)
        self.assertEquals(set_mode_string, get_mode_string)

    def test_case_software_trigger_rate(self):
        parameter_pointer = self.user_set.get_parameter(SoftwareTriggerRate.name)
        para = FloatParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        set_min_status = self.user_set.set_float_value(SoftwareTriggerRate.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_float_value(SoftwareTriggerRate.name)
        set_max_status = self.user_set.set_float_value(SoftwareTriggerRate.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_float_value(SoftwareTriggerRate.name)

        self.assertEquals(unit, 'Hz')
        self.assertEquals(get_min_value, set_min_value)
        self.assertEquals(get_max_value, set_max_value)
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertTrue(show_status(get_min_status))
        self.assertTrue(show_status(get_max_status))
        self.assertTrue(show_status(set_min_status))
        self.assertTrue(show_status(set_max_status))

    # read only
    def test_case_max_scan_rate(self):
        parameter_pointer = self.user_set.get_parameter(MaxScanRate.name)
        para = FloatParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        get_status, get_value = self.user_set.get_float_value(MaxScanRate.name)

        set_min_status = self.user_set.set_float_value(MaxScanRate.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_float_value(MaxScanRate.name)
        set_max_status = self.user_set.set_float_value(MaxScanRate.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_float_value(MaxScanRate.name)

        self.assertEquals(unit, 'Hz')
        self.assertEquals(get_min_value, get_value)
        self.assertEquals(get_max_value, get_value)
        self.assertTrue(show_status(get_status))
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertFalse(show_status(set_min_status))
        self.assertFalse(show_status(set_max_status))

    @data(*range(1, 65536, 65534))
    def test_case_encoder_trigger_interval(self, set_value):
        set_status = self.user_set.set_int_value(EncoderTriggerInterval.name, set_value)
        get_status, get_value = self.user_set.get_int_value(EncoderTriggerInterval.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

    @data(*range(16, 20001, 19999))
    def test_case_scan_line_count(self, set_value):
        set_status = self.user_set.set_int_value(ScanLineCount.name, set_value)
        get_status, get_value = self.user_set.get_int_value(ScanLineCount.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

    # read only
    def test_case_data_points_per_profile(self):
        parameter_pointer = self.user_set.get_parameter(DataPointsPerProfile.name)
        para = IntParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        get_status, get_value = self.user_set.get_int_value(DataPointsPerProfile.name)

        set_min_status = self.user_set.set_int_value(DataPointsPerProfile.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_int_value(DataPointsPerProfile.name)
        set_max_status = self.user_set.set_int_value(DataPointsPerProfile.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_int_value(DataPointsPerProfile.name)

        self.assertEquals(unit, '')
        self.assertEquals(get_min_value, get_value)
        self.assertEquals(get_max_value, get_value)
        self.assertTrue(show_status(get_status))
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertFalse(show_status(set_min_status))
        self.assertFalse(show_status(set_max_status))

    @data(*range(16, 60002, 59986))
    def test_case_exposure_delay(self, set_value):
        set_status = self.user_set.set_int_value(ScanLineCount.name, set_value)
        get_status, get_value = self.user_set.get_int_value(ScanLineCount.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

    @data(*range(-1, 60001, 60000))
    def test_case_call_back_retrieval_timeout(self, set_value):
        set_status = self.user_set.set_int_value(CallbackRetrievalTimeout.name, set_value)
        get_status, get_value = self.user_set.get_int_value(CallbackRetrievalTimeout.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

    # read only
    def test_case_x_axis_resolution(self):
        parameter_pointer = self.user_set.get_parameter(XAxisResolution.name)
        para = FloatParameter.convert_from_parameter(parameter_pointer)
        unit_status, unit = para.get_unit()
        min_status, set_min_value = para.get_min()
        max_status, set_max_value = para.get_max()

        get_status, get_value = self.user_set.get_float_value(XAxisResolution.name)

        set_min_status = self.user_set.set_float_value(XAxisResolution.name, set_min_value)
        get_min_status, get_min_value = self.user_set.get_float_value(XAxisResolution.name)
        set_max_status = self.user_set.set_float_value(XAxisResolution.name, set_max_value)
        get_max_status, get_max_value = self.user_set.get_float_value(XAxisResolution.name)

        self.assertEquals(unit, 'um')
        self.assertEquals(get_min_value, get_value)
        self.assertEquals(get_max_value, get_value)
        self.assertTrue(show_status(get_status))
        self.assertTrue(show_status(unit_status))
        self.assertTrue(show_status(min_status))
        self.assertTrue(show_status(max_status))
        self.assertFalse(show_status(set_min_status))
        self.assertFalse(show_status(set_max_status))

    @data(*range(-90, 91, 1))
    def test_case_tilt_correction_angle(self, set_value):
        set_status = self.user_set.set_float_value(TiltCorrectionAngle.name, set_value)
        get_status, get_value = self.user_set.get_float_value(TiltCorrectionAngle.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)

    @data(*range(1, 80, 1))
    def test_case_height_correction_ratio(self, set_value):
        set_value *= 0.1
        set_status = self.user_set.set_float_value(HeightCorrectionRatio.name, set_value)
        get_status, get_value = self.user_set.get_float_value(HeightCorrectionRatio.name)

        self.assertTrue(show_status(set_status))
        self.assertTrue(show_status(get_status))
        self.assertEquals(set_value, get_value)