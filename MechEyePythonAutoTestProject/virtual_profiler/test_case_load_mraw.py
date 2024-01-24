from base_test_case import *


class TestLoadFile(unittest.TestCase):

    def setUp(self) -> None:
        self.json_content = read_device_type_json_file()
        self.mraw_path = self.json_content['mraw'][0]['mraw_path']

    def mech_mind_status(self, status):
        self.assertEqual(status.error_code, 0)
        self.assertEqual(status.error_description, '')

    def test_case_load_file_not_available_mraw(self):
        try:
            VirtualProfiler(r"")
        except Exception as e:
            print(e)

    def test_case_load_file_available_mraw(self):
        json_content = read_device_type_json_file()
        mraw_path = json_content['mraw'][0]['mraw_path']
        VirtualProfiler(mraw_path)

    def test_case_get_profiler_info(self):
        json_content = read_device_type_json_file()
        info = ProfilerInfo()

        virtual_profiler = VirtualProfiler(self.mraw_path)
        info_status = virtual_profiler.get_profiler_info(info)

        self.mech_mind_status(info_status)
        self.assertEqual(info.model, self.json_content['mraw'][1]['model_name'])
        self.assertEqual(info.ip_address, self.json_content['mraw'][6]['ip_address'])
        self.assertEqual(info.port, int(self.json_content['mraw'][8]['port']))
        self.assertEqual(info.sensor_sn, self.json_content['mraw'][3]['sensor_sn'])
        self.assertEqual(info.controller_sn, self.json_content['mraw'][2]['controller_sn'])
        self.assertEqual(info.hardware_version.to_string(), self.json_content['mraw'][4]['hardware_version'])
        self.assertEqual(info.firmware_version.to_string(), self.json_content['mraw'][5]['firmware_version'])
        self.assertEqual(info.subnet_mask, self.json_content['mraw'][9]['subnet_mask'])

    def test_case_user_set(self):

        virtual_profiler = VirtualProfiler(self.mraw_path)
        user_set = virtual_profiler.current_user_set()
        status, user_set_name = user_set.get_name()

        self.mech_mind_status(status)
        self.assertEqual(user_set_name, self.json_content['mraw'][10]['user_set_name'])

    def test_case_get_available_name(self):
        virtual_profiler = VirtualProfiler(self.mraw_path)
        user_set = virtual_profiler.current_user_set()
        status, parameter_name = user_set.get_available_parameter_names()

        self.mech_mind_status(status)
        self.assertNotEqual(len(parameter_name), 0)

    def test_case_get_available_parameters(self):
        virtual_profiler = VirtualProfiler(self.mraw_path)
        user_set = virtual_profiler.current_user_set()
        parameters = user_set.get_available_parameters()
        print(parameters)
        # for param in parameters:
        #     print(param.name())

    def test_case_get_parameter(self):
        virtual_profiler = VirtualProfiler(self.mraw_path)
        user_set = virtual_profiler.current_user_set()
        status, parameter_name = user_set.get_available_parameter_names()
        for parameter in parameter_name:
            param = user_set.get_parameter(parameter)
            self.assertNotEqual(param.name(), "")
            self.assertNotEqual(param.description(), "")
            self.assertFalse(param.is_writable())
            self.assertTrue(param.is_readable())

