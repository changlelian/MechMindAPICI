from common import *
from base_test_case import BaseTestCase


class TestCaseValidCameraUserSets(BaseTestCase):
    default_user_set = "default"
    calib_user_set = "calib"
    new_user_set = "PyUnittest"
    rename_user_set = "PyUnittestRename"

    def test_case_print_all_user_sets(self):
        """ Test get all user sets """
        error, user_sets = self.user_set_manager.get_all_user_set_names()

        self.assertTrue(show_status(error))
        self.assertGreaterEqual(len(user_sets), 2)
        self.assertIn(self.default_user_set, user_sets)
        self.assertIn(self.calib_user_set, user_sets)

    def test_case_add_user_sets(self):
        """ Test get all user sets """
        add_error = self.user_set_manager.add_user_set(self.new_user_set)
        self.assertTrue(show_status(add_error))

        error, user_sets = self.user_set_manager.get_all_user_set_names()
        self.assertTrue(show_status(error))
        self.assertIn(self.new_user_set, user_sets)

        self.assertTrue(self.user_set_manager.delete_user_set(self.new_user_set))

    def test_case_select_user_sets(self):
        """ Test select user sets """

        # set default user sets
        select_error = self.user_set_manager.select_user_set(self.default_user_set)
        self.assertTrue(show_status(select_error))

        status, getname = self.user_set_manager.current_user_set().get_name()
        self.assertTrue(show_status(status))
        self.assertEquals(getname, self.default_user_set)

        # set new_user_set user sets
        add_error = self.user_set_manager.add_user_set(self.new_user_set)
        self.assertTrue(show_status(add_error))

        select_error = self.user_set_manager.select_user_set(self.new_user_set)
        self.assertTrue(show_status(select_error))

        status, user_set_name = self.user_set_manager.current_user_set().get_name()
        self.assertTrue(show_status(status))
        self.assertEquals(user_set_name, self.new_user_set)

        self.assertTrue(self.user_set_manager.delete_user_set(self.new_user_set))

    def test_case_rename_user_sets(self):
        """ Test rename user sets """
        add_error = self.user_set_manager.add_user_set(self.new_user_set)
        self.assertTrue(show_status(add_error))

        status, user_set_name = self.user_set_manager.current_user_set().get_name()
        print(user_set_name)

        rename_error = self.user_set_manager.current_user_set().rename(self.rename_user_set)
        self.assertTrue(show_status(rename_error))

        error, user_sets = self.user_set_manager.get_all_user_set_names()
        self.assertTrue(show_status(error))
        self.assertIn(self.rename_user_set, user_sets)

        self.assertTrue(self.user_set_manager.delete_user_set(self.rename_user_set))

    def test_case_delete_user_sets(self):
        """ Test delete user sets """
        add_error = self.user_set_manager.add_user_set(self.new_user_set)
        self.assertTrue(show_status(add_error))

        delete_error = self.user_set_manager.delete_user_set(self.new_user_set)
        self.assertTrue(show_status(delete_error))

        error, user_sets = self.user_set_manager.get_all_user_set_names()
        self.assertTrue(show_status(error))
        self.assertNotIn(self.new_user_set, user_sets)


class TestCaseValidSaveLoadFile(BaseTestCase):
    file_name = "files/test.json"

    def test_case_a_save_file(self):
        save_status = self.user_set_manager.save_to_file(self.file_name)
        self.assertTrue(show_status(save_status))

    def test_case_b_load_file(self):
        load_status = self.user_set_manager.load_from_file(self.file_name)
        self.assertTrue(show_status(load_status))