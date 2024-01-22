from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.profiler import *


class CustomCallback(EventCallbackBase):
    def __init__(self):
        super().__init__()

    def run(self, event):
        print("A camera event has occurred. The event ID is {0}.".format(event))

@ddt
class TestCaseValidProfilerEvent(BaseTestCase):
    @data(*range(1000, 3601))
    def test_case_set_heartbeat_interval(self, set_value):
        heartbeat_status = self.profiler.set_heartbeat_interval(set_value)
        self.assertTrue(show_status(heartbeat_status))

    def test_case_camera_event(self):
        device_event = ProfilerEvent()
        callback = CustomCallback()
        callback_status_disconnect = device_event.register_profiler_event_callback(self.profiler, callback,
                                                                                   ProfilerEvent.PROFILER_EVENT_DISCONNECTED)
        callback_status_all = device_event.register_profiler_event_callback(self.profiler, callback,
                                                                            ProfilerEvent.PROFILER_EVENT_ALL)
        self.assertTrue(show_status(callback_status_all))
        self.assertTrue(show_status(callback_status_disconnect))