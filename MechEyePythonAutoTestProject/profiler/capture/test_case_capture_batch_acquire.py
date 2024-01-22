from mecheye.profiler_utils import *
import cv2
from time import sleep
from multiprocessing import Lock
from common import *
from base_test_case import BaseTestCase


class TestCaseCaptureAcquire(BaseTestCase):
    def test_case_capture_acquire(self):
        pass
    #     source_status = self.user_set.set_enum_value(DataAcquisitionTriggerSource.name, DataAcquisitionTriggerSource.Value_Software)
    #     line_status = self.user_set.set_enum_value(LineScanTriggerSource.name, LineScanTriggerSource.Value_FixedRate)
    #
    #     stop_status = self.profiler.stop_acquisition()
    #     start_status = self.profiler.start_acquisition()
    #     trigger_status = self.profiler.trigger_software()
    #
    #     data_width = 4096
    #     capture_line_count = 200
    #     self.total_batch = ProfileBatch(data_width)
    #     if start_status.is_ok() and trigger_status.is_ok():
    #         self.total_batch.reserve(capture_line_count)
    #
    #         while self.total_batch.height() < capture_line_count:
    #             batch = ProfileBatch(data_width)
    #             status = self.profiler.retrieve_batch_data(batch)
    #             if status.is_ok():
    #                 self.total_batch.append(batch)
    #                 sleep(0.2)
    #             else:
    #                 show_error(status)
    #                 break
    #
    #     self.assertTrue(show_status(source_status))
    #     self.assertTrue(show_status(line_status))
    #     self.assertTrue(show_status(stop_status))
    #     self.assertTrue(show_status(start_status))
    #     self.assertTrue(show_status(trigger_status))
