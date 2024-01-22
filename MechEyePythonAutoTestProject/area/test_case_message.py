from common import *
from mecheye.shared import *
from ddt import ddt, data, unpack
from base_test_case import BaseTestCase
from mecheye.area_scan_3d_camera import *


@ddt
class TestCaseValidMessageParameter(BaseTestCase):

    def test_case_get_all_camera(self):
        camera_infos = Camera.discover_cameras()
        self.assertNotEquals(len(camera_infos), 0)

    def test_case_get_camera_info(self):
        self.camera_info = CameraInfo()
        self.camera.get_camera_info(self.camera_info)

        self.assertTrue(self.camera_info.model)
        self.assertTrue(self.camera_info.ip_address)
        self.assertTrue(self.camera_info.subnet_mask)
        self.assertTrue(self.camera_info.serial_number)
        self.assertEqual(int(self.camera_info.port), 5577)
        self.assertTrue(self.camera_info.hardware_version.to_string())
        self.assertTrue(self.camera_info.firmware_version.to_string())

    def test_case_get_camera_temperature(self):
        self.camera_status = CameraStatus()
        self.camera.get_camera_status(self.camera_status)

        self.assertNotEquals(0, self.camera_status.temperature.cpu_temperature)
        self.assertNotEquals(0, self.camera_status.temperature.projector_temperature)

    def test_case_get_camera_resolution(self):
        self.camera_resolution = CameraResolutions()
        self.camera.get_camera_resolutions(self.camera_resolution)

        self.assertNotEquals(0, self.camera_resolution.depth.width)
        self.assertNotEquals(0, self.camera_resolution.depth.height)
        self.assertNotEquals(0, self.camera_resolution.texture.width)
        self.assertNotEquals(0, self.camera_resolution.texture.height)

    def test_case_get_camera_intrinsics(self):
        self.camera_intrinsics = CameraIntrinsics()
        self.camera.get_camera_intrinsics(self.camera_intrinsics)

        # Texture Camera Distortion Coefficients
        self.assertEquals(0, self.camera_intrinsics.texture.camera_distortion.k1)
        self.assertEquals(0, self.camera_intrinsics.texture.camera_distortion.k2)
        self.assertEquals(0, self.camera_intrinsics.texture.camera_distortion.p1)
        self.assertEquals(0, self.camera_intrinsics.texture.camera_distortion.p2)
        self.assertEquals(0, self.camera_intrinsics.texture.camera_distortion.k3)

        # Depth Camera Distortion Coefficients
        self.assertEquals(0, self.camera_intrinsics.depth.camera_distortion.k1)
        self.assertEquals(0, self.camera_intrinsics.depth.camera_distortion.k2)
        self.assertEquals(0, self.camera_intrinsics.depth.camera_distortion.p1)
        self.assertEquals(0, self.camera_intrinsics.depth.camera_distortion.p2)
        self.assertEquals(0, self.camera_intrinsics.depth.camera_distortion.k3)

        # Texture Camera Matrix
        print(self.camera_intrinsics.texture.camera_matrix.fx)
        print(self.camera_intrinsics.texture.camera_matrix.cx)
        print(self.camera_intrinsics.texture.camera_matrix.fy)
        print(self.camera_intrinsics.texture.camera_matrix.cy)

        # Depth Camera Matrix
        print(self.camera_intrinsics.depth.camera_matrix.fx)
        print(self.camera_intrinsics.depth.camera_matrix.cx)
        print(self.camera_intrinsics.depth.camera_matrix.fy)
        print(self.camera_intrinsics.depth.camera_matrix.cy)

        # Depth Camera to Texture Camera Rotation
        print(self.camera_intrinsics.depth_to_texture.rotation[0][0])
        print(self.camera_intrinsics.depth_to_texture.rotation[1][0])
        print(self.camera_intrinsics.depth_to_texture.rotation[2][0])

        # Depth Camera to Texture Camera Translation
        print(self.camera_intrinsics.depth_to_texture.translation[0])
        print(self.camera_intrinsics.depth_to_texture.translation[1])
        print(self.camera_intrinsics.depth_to_texture.translation[2])
