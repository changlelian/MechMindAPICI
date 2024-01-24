import os
import time

import cv2
from base_test_case import *
from multiprocessing import RLock

mutex = RLock()


class CustomAcquisitionCallback(AcquisitionCallbackBase):
    def __init__(self, width):
        AcquisitionCallbackBase.__init__(self)
        self.total_batch = ProfileBatch(width)

    def run(self, batch):
        mutex.acquire()
        self.total_batch.append(batch)
        mutex.release()


class TestCapture(unittest.TestCase):

    @classmethod
    def setUpClass(cls) -> None:
        cls.current_cwd = os.getcwd()

    def setUp(self) -> None:
        self.json_content = read_device_type_json_file()
        self.mraw_path = self.json_content['mraw'][0]['mraw_path']
        self.virtual_profiler = VirtualProfiler(self.mraw_path)
        self.user_set = self.virtual_profiler.current_user_set()

    def mech_mind_status(self, status):
        self.assertEqual(status.error_code, 0)
        self.assertEqual(status.error_description, '')

    def test_case_capture_without_call_back(self):
        data_status, data_width = self.user_set.get_int_value(DataPointsPerProfile.name)
        line_status, line_count = self.user_set.get_int_value(ScanLineCount.name)

        total_batch = ProfileBatch(data_width)
        total_batch.reserve(line_count)

        start_status = self.virtual_profiler.start_acquisition()

        while total_batch.height() < line_count:
            batch = ProfileBatch(data_width)
            retrieve_status = self.virtual_profiler.retrieve_batch_data(batch)
            self.mech_mind_status(retrieve_status)
            append_status = total_batch.append(batch)
            self.assertTrue(append_status)

        cv2.imwrite(os.path.join(self.current_cwd, "files/depth.tiff"), total_batch.get_depth_map().data())
        cv2.imwrite(os.path.join(self.current_cwd, "files/IntensityImage.tiff"), total_batch.get_intensity_image().data())
        stop_status = self.virtual_profiler.stop_acquisition()

        self.mech_mind_status(start_status)
        self.mech_mind_status(stop_status)
        self.mech_mind_status(data_status)
        self.mech_mind_status(line_status)
        self.assertEqual(data_width, 4096)
        self.assertGreaterEqual(line_count, 16)
        self.assertLessEqual(line_count, 20000)

    # def test_case_capture_with_call_back(self):
    #     time.sleep(40)
    #     data_status, data_width = self.user_set.get_int_value(DataPointsPerProfile.name)
    #     line_status, line_count = self.user_set.get_int_value(ScanLineCount.name)
    #     total_batch = ProfileBatch(data_width)
    #     callback = CustomAcquisitionCallback(data_width)
    #     call_back_status = self.virtual_profiler.register_acquisition_callback(callback)
    #
    #     stop_status = self.virtual_profiler.stop_acquisition()
    #     start_status = self.virtual_profiler.start_acquisition()
    #
    #     while True:
    #         with mutex:
    #             if not callback.total_batch.is_empty():
    #                 break
    #
    #     cv2.imwrite(os.path.join(self.current_cwd, "files/DepthMapUsingCallback.tiff"), callback.total_batch.get_depth_map().data())
    #     cv2.imwrite(os.path.join(self.current_cwd, "files/IntensityImageUsingCallback.tiff"), callback.total_batch.get_intensity_image().data())
    #
    #     print(callback.total_batch.height())
    #     self.mech_mind_status(start_status)
    #     self.mech_mind_status(stop_status)
    #     self.mech_mind_status(call_back_status)
    #     self.mech_mind_status(data_status)
    #     self.mech_mind_status(line_status)
    #     self.assertEqual(data_width, 4096)
    #     self.assertGreaterEqual(line_count, 16)
    #     self.assertLessEqual(line_count, 20000)
    #     self.assertGreaterEqual(callback.total_batch.height(), 16)
    #     self.assertLessEqual(callback.total_batch.height(), 20000)