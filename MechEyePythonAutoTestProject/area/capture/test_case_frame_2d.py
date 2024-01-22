from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


class TestCaseCaptureFrame2D(BaseTestCase):

    def test_case_capture_frame_2d(self):
        frame_status = self.camera.capture_2d(self.frame_2d)
        self.assertTrue(show_status(frame_status))

    def test_case_capture_get_gray_scale_image(self):
        self.camera.capture_2d(self.frame_2d)
        gray_2d = self.frame_2d.get_gray_scale_image()

        self.assertFalse(gray_2d.is_empty())
        self.assertEquals(gray_2d.width(), self.camera_resolution.texture.width)
        self.assertEquals(gray_2d.height(), self.camera_resolution.texture.height)

    def test_case_capture_get_color_scale_image(self):
        self.camera.capture_2d(self.frame_2d)
        color_2d = self.frame_2d.get_color_image()

        self.assertFalse(color_2d.is_empty())
        self.assertEquals(color_2d.width(), self.camera_resolution.texture.width)
        self.assertEquals(color_2d.height(), self.camera_resolution.texture.height)

    def test_case_capture_normal_get_image_type(self):
        self.camera.capture_2d(self.frame_2d)
        if self.camera_info.model in self.config_file["camera_image_type"]["color_type"]:
            self.assertTrue(self.frame_2d.color_type() == ColorTypeOf2DCamera_Color)
        elif self.camera_info.model in self.config_file["camera_image_type"]["monochrome_type"]:
            self.assertTrue(self.frame_2d.color_type() == ColorTypeOf2DCamera_Monochrome)
        else:
            self.fail("Camera type is undefined")

    def test_case_capture_abnormal_get_image_type(self):
        self.assertTrue(self.frame_2d.color_type() == ColorTypeOf2DCamera_Undefined)

    def test_case_capture_get_image_size(self):
        self.camera.capture_2d(self.frame_2d)
        get_image_size = self.frame_2d.image_size()

        self.assertEquals(get_image_size.width, self.camera_resolution.texture.width)
        self.assertEquals(get_image_size.height, self.camera_resolution.texture.height)

    def test_case_capture_clear_image_data(self):
        self.camera.capture_2d(self.frame_2d)
        self.frame_2d.clear()
        get_image_size = self.frame_2d.image_size()
        image_is_empty = self.frame_2d.is_empty()

        self.assertTrue(image_is_empty)
        self.assertEquals(get_image_size.width, 0)
        self.assertEquals(get_image_size.height, 0)


class TestCaseFrame2D(BaseTestCase):
    def test_case_frame_is_empty(self):
        frame_2d = Frame2D()
        color_2d = frame_2d.get_color_image()
        gray_2d = frame_2d.get_gray_scale_image()

        self.assertTrue(color_2d.is_empty())
        self.assertTrue(gray_2d.is_empty())

    def test_case_frame_image_size(self):
        frame_2d = Frame2D()
        image_size = frame_2d.image_size()

        self.assertEquals(image_size.width, 0)
        self.assertEquals(image_size.height, 0)

    def test_case_image_resize(self):
        gray_1 = 0
        gray_2 = 255
        resize_width = 1
        resize_height = 2

        frame_2d = Frame2D()
        color_2d = frame_2d.get_gray_scale_image()
        color_2d.resize(resize_width, resize_height)

        color_2d.at(0, 0).gray = gray_1
        color_2d.at(1, 0).gray = gray_2

        self.assertFalse(color_2d.is_empty())
        self.assertEqual(color_2d.width(), resize_width)
        self.assertEqual(color_2d.height(), resize_height)

        self.assertEqual(color_2d.data()[0], gray_1)
        self.assertEqual(color_2d.data()[1], gray_2)