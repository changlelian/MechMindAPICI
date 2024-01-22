from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.profiler import *
from multiprocessing import Lock

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


class TestCaseProfilerTrigger(BaseTestCase):
    def test_case_retrieve_batch_data(self):
        batch = ProfileBatch(4096)
        retrieve_data = self.profiler.retrieve_batch_data(batch)
        show_status(retrieve_data)

    def test_case_trigger_software(self):
        acquisition_start_status = self.profiler.start_acquisition()
        trigger_status = self.profiler.trigger_software()
        self.assertTrue(show_status(acquisition_start_status))
        self.assertTrue(show_status(trigger_status))

    def test_case_start_acquisition(self):
        acquisition_start_status = self.profiler.start_acquisition()
        acquisition_stop_status = self.profiler.stop_acquisition()

        self.assertTrue(show_status(acquisition_start_status))
        self.assertTrue(show_status(acquisition_stop_status))

    def test_case_stop_acquisition(self):
        acquisition_status = self.profiler.stop_acquisition()
        self.assertTrue(show_status(acquisition_status))

    def test_case_register_acquisition_call_back(self):
        self.callback = CustomAcquisitionCallback(4096).__disown__()
        status = self.profiler.register_acquisition_callback(self.callback)
        self.assertTrue(show_status(status))
