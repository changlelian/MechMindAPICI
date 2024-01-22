from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


class TestCaseCaptureFrame2D(BaseTestCase):

    def test_case_capture_frame_3d(self):
        frame_status = self.camera.capture_3d(self.frame_3d)
        self.assertTrue(show_status(frame_status))

    def test_case_get_depth_map(self):
        depth_map = self.frame_3d.get_depth_map()
        self.assertFalse(depth_map.is_empty())
        self.assertEquals(depth_map.width(), self.camera_resolution.depth.width)
        self.assertEquals(depth_map.height(), self.camera_resolution.depth.height)

    def test_case_get_untextured_point_cloud(self):
        point_cloud = self.frame_3d.get_untextured_point_cloud()

        self.assertFalse(point_cloud.is_empty())
        self.assertEquals(point_cloud.width(), self.camera_resolution.depth.width)
        self.assertEquals(point_cloud.height(), self.camera_resolution.depth.height)

    def test_case_get_untextured_point_cloud_with_normals(self):
        untextured_point_cloud = self.frame_3d.get_untextured_point_cloud_with_normals()

        self.assertFalse(untextured_point_cloud.is_empty())
        self.assertEquals(untextured_point_cloud.width(), self.camera_resolution.depth.width)
        self.assertEquals(untextured_point_cloud.height(), self.camera_resolution.depth.height)

    def test_case_get_orthogonal_depth_map(self):
        depth_map, x_scale, y_scale, x_offset, y_offset = self.frame_3d.get_orthogonal_depth_map()

        self.assertNotEquals(x_scale, 0)
        self.assertNotEquals(y_scale, 0)
        self.assertNotEquals(x_offset, 0)
        self.assertNotEquals(y_offset, 0)
        self.assertFalse(depth_map.is_empty())
        self.assertEquals(depth_map.width(), self.camera_resolution.depth.width)
        self.assertEquals(depth_map.height(), self.camera_resolution.depth.height)

    def test_case_capture_clear_image_data(self):
        pass

    def test_case_save_point_cloud(self):
        disorder_ply_untextured_point_cloud = self.frame_3d.save_untextured_point_cloud(FileFormat_PLY, "files/disorder_untextured_point_cloud.ply")
        disorder_pcd_untextured_point_cloud = self.frame_3d.save_untextured_point_cloud(FileFormat_PCD, "files/disorder_untextured_point_cloud.pcd")
        disorder_csv_untextured_point_cloud = self.frame_3d.save_untextured_point_cloud(FileFormat_CSV, "files/disorder_untextured_point_cloud.csv")

        order_ply_untextured_point_cloud = self.frame_3d.save_untextured_point_cloud(FileFormat_PLY, "files/order_untextured_point_cloud.ply", True)
        order_pcd_untextured_point_cloud = self.frame_3d.save_untextured_point_cloud(FileFormat_PCD, "files/order_untextured_point_cloud.pcd", True)
        order_csv_untextured_point_cloud = self.frame_3d.save_untextured_point_cloud(FileFormat_CSV, "files/order_untextured_point_cloud.csv", True)

        self.assertTrue(show_status(disorder_ply_untextured_point_cloud))
        self.assertTrue(show_status(disorder_pcd_untextured_point_cloud))
        self.assertTrue(show_status(disorder_csv_untextured_point_cloud))

        self.assertTrue(show_status(order_ply_untextured_point_cloud))
        self.assertTrue(show_status(order_pcd_untextured_point_cloud))
        self.assertTrue(show_status(order_csv_untextured_point_cloud))

    def test_case_save_point_cloud_with_normals(self):
        disorder_ply_untextured_normal_point_cloud = self.frame_3d.save_untextured_point_cloud_with_normals(FileFormat_PLY, "files/disorder_untextured_normal_point_cloud.ply")
        disorder_pcd_untextured_normal_point_cloud = self.frame_3d.save_untextured_point_cloud_with_normals(FileFormat_PCD, "files/disorder_untextured_normal_point_cloud.pcd")
        disorder_csv_untextured_normal_point_cloud = self.frame_3d.save_untextured_point_cloud_with_normals(FileFormat_CSV, "files/disorder_untextured_normal_point_cloud.csv")

        order_ply_untextured_normal_point_cloud = self.frame_3d.save_untextured_point_cloud_with_normals(FileFormat_PLY, "files/order_untextured_normal_point_cloud.ply", True)
        order_pcd_untextured_normal_point_cloud = self.frame_3d.save_untextured_point_cloud_with_normals(FileFormat_PCD, "files/order_untextured_normal_point_cloud.pcd", True)
        order_csv_untextured_normal_point_cloud = self.frame_3d.save_untextured_point_cloud_with_normals(FileFormat_CSV, "files/order_untextured_normal_point_cloud.csv", True)

        self.assertTrue(show_status(disorder_ply_untextured_normal_point_cloud))
        self.assertTrue(show_status(disorder_pcd_untextured_normal_point_cloud))
        self.assertTrue(show_status(disorder_csv_untextured_normal_point_cloud))

        self.assertTrue(show_status(order_ply_untextured_normal_point_cloud))
        self.assertTrue(show_status(order_pcd_untextured_normal_point_cloud))
        self.assertTrue(show_status(order_csv_untextured_normal_point_cloud))


class TestCaseFrame3D(BaseTestCase):
    def test_case_frame_is_empty(self):
        frame_3d = Frame3D()
        depth_map = frame_3d.get_depth_map()
        untextured_point_cloud = frame_3d.get_untextured_point_cloud()
        untextured_point_cloud_normals = frame_3d.get_untextured_point_cloud_with_normals()

        self.assertTrue(depth_map.is_empty())
        self.assertTrue(untextured_point_cloud.is_empty())
        self.assertTrue(untextured_point_cloud_normals.is_empty())

    def test_case_frame_image_size(self):
        frame_3d = Frame3D()
        image_size = frame_3d.image_size()

        self.assertEquals(image_size.width, 0)
        self.assertEquals(image_size.height, 0)

    def test_case_image_resize(self):
        x_value = 10
        y_value = 255
        z_value = 254
        resize_width = 1
        resize_height = 2

        frame_3d = Frame3D()
        point_cloud = frame_3d.get_untextured_point_cloud()
        point_cloud.resize(resize_width, resize_height)

        point_cloud.at(0, 0).x = x_value
        point_cloud.at(0, 0).y = y_value
        point_cloud.at(0, 0).z = z_value

        point_cloud.at(1, 0).x = x_value
        point_cloud.at(1, 0).y = y_value
        point_cloud.at(1, 0).z = z_value

        self.assertFalse(point_cloud.is_empty())
        self.assertEqual(point_cloud.width(), resize_width)
        self.assertEqual(point_cloud.height(), resize_height)

        self.assertEqual(point_cloud.data()[0][0][0], x_value)
        self.assertEqual(point_cloud.data()[0][0][1], y_value)
        self.assertEqual(point_cloud.data()[0][0][2], z_value)

        self.assertEqual(point_cloud.data()[1][0][0], x_value)
        self.assertEqual(point_cloud.data()[1][0][1], y_value)
        self.assertEqual(point_cloud.data()[1][0][2], z_value)