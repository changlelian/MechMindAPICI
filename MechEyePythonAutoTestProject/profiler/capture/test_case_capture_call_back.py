from mecheye.profiler_utils import *
import cv2
from time import sleep
from multiprocessing import Lock
from common import *
from base_test_case import BaseTestCase

mutex = Lock()


class CustomAcquisitionCallback(AcquisitionCallbackBase):
    def __init__(self, width):
        AcquisitionCallbackBase.__init__(self)
        self.total_batch = ProfileBatch(width)

    def run(self, batch):
        mutex.acquire()
        print("callback called")
        self.total_batch.append(batch)
        mutex.release()


class TestCaseCallBack(BaseTestCase):
    # def test_case_call_back_capture_map(self):
    #     source_status = self.user_set.set_enum_value(DataAcquisitionTriggerSource.name, DataAcquisitionTriggerSource.Value_Software)
    #     line_status = self.user_set.set_enum_value(LineScanTriggerSource.name, LineScanTriggerSource.Value_FixedRate)
    #
    #     self.callback = CustomAcquisitionCallback(4096).__disown__()
    #     call_back_status = self.profiler.register_acquisition_callback(self.callback)
    #
    #     stop_status = self.profiler.stop_acquisition()
    #     start_status = self.profiler.start_acquisition()
    #     trigger_status = self.profiler.trigger_software()
    #
    #     n = 0
    #     while n <= 10:
    #         mutex.acquire()
    #         if self.callback.total_batch.is_empty():
    #             mutex.release()
    #             # print("empty")
    #             sleep(0.5)
    #             n += 1
    #         else:
    #             break
    #     self.profiler.stop_acquisition()
    #
    #     self.save("files/depth.tiff", "files/intensity.tiff")
    #     self.assertTrue(show_status(source_status))
    #     self.assertTrue(show_status(line_status))
    #     self.assertTrue(show_status(call_back_status))
    #     self.assertTrue(show_status(stop_status))
    #     self.assertTrue(show_status(start_status))
    #     self.assertTrue(show_status(trigger_status))

    def save(self, depth_file_name, intensity_file_name):
        cv2.imwrite(depth_file_name,
                    self.callback.total_batch.get_depth_map().data())
        cv2.imwrite(intensity_file_name,
                    self.callback.total_batch.get_intensity_image().data())