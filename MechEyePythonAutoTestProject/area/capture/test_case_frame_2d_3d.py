import os
from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *

work_space = os.path.dirname(__file__)

class TestCaseCaptureFrame2D(BaseTestCase):

    def test_case_capture_frame_2d_and_3d(self):
        frame_status = self.camera.capture_2d_and_3d(self.frame_2d_and_3d)
        self.assertTrue(show_status(frame_status))

    def test_case_get_textured_point_cloud(self):
        textured_point_cloud = self.frame_2d_and_3d.get_textured_point_cloud()
        self.assertFalse(textured_point_cloud.is_empty())
        self.assertEquals(textured_point_cloud.width(), self.camera_resolution.depth.width)
        self.assertEquals(textured_point_cloud.height(), self.camera_resolution.depth.height)

    def test_case_get_textured_point_cloud_with_normals(self):
        textured_point_cloud = self.frame_2d_and_3d.get_textured_point_cloud_with_normals()

        self.assertFalse(textured_point_cloud.is_empty())
        self.assertEquals(textured_point_cloud.width(), self.camera_resolution.depth.width)
        self.assertEquals(textured_point_cloud.height(), self.camera_resolution.depth.height)

    def test_case_get_untextured_point_cloud_with_normals(self):
        untextured_point_cloud = self.frame_2d_and_3d.get_textured_point_cloud_with_normals()

        self.assertFalse(untextured_point_cloud.is_empty())
        self.assertEquals(untextured_point_cloud.width(), self.camera_resolution.depth.width)
        self.assertEquals(untextured_point_cloud.height(), self.camera_resolution.depth.height)

    def test_case_textured_save_point_cloud(self):
        disorder_ply_textured_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud(FileFormat_PLY, "files/disorder_textured_point_cloud.ply")
        disorder_pcd_textured_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud(FileFormat_PCD, "files/disorder_textured_point_cloud.pcd")
        disorder_csv_textured_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud(FileFormat_CSV, "files/disorder_textured_point_cloud.csv")

        order_ply_textured_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud(FileFormat_PLY, "files/order_textured_point_cloud.ply", True)
        order_pcd_textured_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud(FileFormat_PCD, "files/order_textured_point_cloud.pcd", True)
        order_csv_textured_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud(FileFormat_CSV, "files/order_textured_point_cloud.csv", True)

        self.assertTrue(show_status(disorder_ply_textured_point_cloud))
        self.assertTrue(show_status(disorder_pcd_textured_point_cloud))
        self.assertTrue(show_status(disorder_csv_textured_point_cloud))

        self.assertTrue(show_status(order_ply_textured_point_cloud))
        self.assertTrue(show_status(order_pcd_textured_point_cloud))
        self.assertTrue(show_status(order_csv_textured_point_cloud))

    def test_case_save_textured_point_cloud_with_normals(self):
        disorder_ply_textured_normal_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud_with_normals(FileFormat_PLY, os.path.join(work_space, 'files', 'disorder_textured_normal_point_cloud.ply'))
        disorder_pcd_textured_normal_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud_with_normals(FileFormat_PCD, os.path.join(work_space, 'files', 'disorder_textured_normal_point_cloud.pcd'))
        disorder_csv_textured_normal_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud_with_normals(FileFormat_CSV, os.path.join(work_space, 'files', 'disorder_textured_normal_point_cloud.csv'))

        order_ply_textured_normal_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud_with_normals(FileFormat_PLY, os.path.join(work_space, 'files', 'order_textured_normal_point_cloud.ply'), True)
        order_pcd_textured_normal_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud_with_normals(FileFormat_PCD, os.path.join(work_space, 'files', 'order_textured_normal_point_cloud.pcd'), True)
        order_csv_textured_normal_point_cloud = self.frame_2d_and_3d.save_textured_point_cloud_with_normals(FileFormat_CSV, os.path.join(work_space, 'files', 'order_textured_normal_point_cloud.csv'), True)

        self.assertTrue(show_status(disorder_ply_textured_normal_point_cloud))
        self.assertTrue(show_status(disorder_pcd_textured_normal_point_cloud))
        self.assertTrue(show_status(disorder_csv_textured_normal_point_cloud))

        self.assertTrue(show_status(order_ply_textured_normal_point_cloud))
        self.assertTrue(show_status(order_pcd_textured_normal_point_cloud))
        self.assertTrue(show_status(order_csv_textured_normal_point_cloud))


class TestCaseFrame2DAnd3D(BaseTestCase):
    def test_case_frame_is_empty(self):
        frame_2d_3d = Frame2DAnd3D()
        textured_point_cloud = frame_2d_3d.get_textured_point_cloud()
        textured_point_cloud_with_normals = frame_2d_3d.get_textured_point_cloud_with_normals()

        self.assertTrue(textured_point_cloud.is_empty())
        self.assertTrue(textured_point_cloud_with_normals.is_empty())

    def test_case_frame_image_size(self):
        frame_2d_3d = Frame2DAnd3D()
        image_size_2d = frame_2d_3d.frame_2d().image_size()
        image_size_3d = frame_2d_3d.frame_3d().image_size()

        self.assertEquals(image_size_2d.width, 0)
        self.assertEquals(image_size_3d.height, 0)

    def test_case_image_resize(self):
        x_value = 10
        y_value = 255
        z_value = 254
        r_value = 255
        g_value = 1
        b_value = 0
        resize_width = 1
        resize_height = 2

        frame_2d_3d = Frame2DAnd3D()
        textured_point_cloud = frame_2d_3d.get_textured_point_cloud()
        textured_point_cloud.resize(resize_width, resize_height)

        textured_point_cloud.at(0, 0).x = x_value
        textured_point_cloud.at(0, 0).y = y_value
        textured_point_cloud.at(0, 0).z = z_value
        textured_point_cloud.at(0, 0).r = r_value
        textured_point_cloud.at(0, 0).g = g_value
        textured_point_cloud.at(0, 0).b = b_value

        textured_point_cloud.at(1, 0).x = x_value
        textured_point_cloud.at(1, 0).y = y_value
        textured_point_cloud.at(1, 0).z = z_value
        textured_point_cloud.at(1, 0).r = r_value
        textured_point_cloud.at(1, 0).g = g_value
        textured_point_cloud.at(1, 0).b = b_value

        self.assertFalse(textured_point_cloud.is_empty())
        self.assertEqual(textured_point_cloud.width(), resize_width)
        self.assertEqual(textured_point_cloud.height(), resize_height)

        self.assertEqual(textured_point_cloud.vertices()[0][0][0], x_value)
        self.assertEqual(textured_point_cloud.vertices()[0][0][1], y_value)
        self.assertEqual(textured_point_cloud.vertices()[0][0][2], z_value)

        self.assertEqual(textured_point_cloud.colors()[0][0][0], b_value)
        self.assertEqual(textured_point_cloud.colors()[0][0][1], g_value)
        self.assertEqual(textured_point_cloud.colors()[0][0][2], r_value)