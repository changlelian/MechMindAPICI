from base_test_case import *


class TestLoadFileParameter(unittest.TestCase):

    def setUp(self) -> None:
        self.json_content = read_device_type_json_file()
        self.mraw_path = self.json_content['mraw'][0]['mraw_path']
        self.virtual_profiler = VirtualProfiler(self.mraw_path)
        self.user_set = self.virtual_profiler.current_user_set()

    def mech_mind_status(self, status, code=0, description=""):
        self.assertEqual(status.error_code, code)
        self.assertEqual(status.error_description, description)

    def test_case_get_int_value(self):
        status, value = self.user_set.get_int_value("CallbackRetrievalTimeout")
        self.mech_mind_status(status)
        self.assertNotEquals(value, 0)

    def test_case_get_float_value(self):
        status, value = self.user_set.get_float_value("SoftwareTriggerRate")
        self.mech_mind_status(status)
        self.assertNotEquals(value, 0)

    def test_case_get_enum_value(self):
        status, value = self.user_set.get_enum_value("DataAcquisitionTriggerSource")
        self.mech_mind_status(status)
        self.assertNotEquals(value, -1)

    def test_case_get_enum_string_value(self):
        status, value = self.user_set.get_enum_value_string("DataAcquisitionTriggerSource")
        self.mech_mind_status(status)
        self.assertNotEquals(value, "")

    def test_case_int_value(self):
        param = self.user_set.get_parameter("CallbackRetrievalTimeout")
        p = IntParameter.convert_from_parameter(param)
        get_status, get_value = p.get_value()
        set_status = p.set_value(5)
        max_status, get_max = p.get_max()
        min_status, get_min = p.get_min()
        step_status, get_step = p.get_step()
        unit_status, get_step = p.get_unit()

        self.mech_mind_status(get_status)
        self.mech_mind_status(max_status)
        self.mech_mind_status(min_status)
        self.mech_mind_status(step_status)
        self.mech_mind_status(unit_status)

        self.assertNotEquals(get_value, "")
        self.mech_mind_status(set_status, code=-3, description="Operation is not supported on a virtual device.")

    def test_case_float_value(self):
        param = self.user_set.get_parameter("SoftwareTriggerRate")
        p = FloatParameter.convert_from_parameter(param)
        get_status, get_value = p.get_value()
        set_status = p.set_value(5)
        max_status, get_max = p.get_max()
        min_status, get_min = p.get_min()
        step_status, get_step = p.get_step()
        unit_status, get_step = p.get_unit()

        self.mech_mind_status(get_status)
        self.mech_mind_status(max_status)
        self.mech_mind_status(min_status)
        self.mech_mind_status(step_status)
        self.mech_mind_status(unit_status)

        self.assertNotEquals(get_value, "")
        self.mech_mind_status(set_status, code=-3, description="Operation is not supported on a virtual device.")


    def test_case_enum_value(self):
        param = self.user_set.get_parameter("DataAcquisitionTriggerSource")
        p = EnumParameter.convert_from_parameter(param)
        get_status, get_value = p.get_value()
        string_status, get_string = p.get_value_string()

        set_status = p.set_value(5)
        status, get_values = p.get_values()
        set_string_status = p.set_value("SoftWare")

        self.mech_mind_status(status)
        self.mech_mind_status(get_status)
        self.mech_mind_status(string_status)
        self.assertNotEquals(len(get_values), 0)
        self.mech_mind_status(set_status, code=-3, description="Operation is not supported on a virtual device.")
        self.mech_mind_status(set_string_status, code=-3, description="Operation is not supported on a virtual device.")
