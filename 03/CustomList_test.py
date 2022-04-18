import unittest
from CustomList import CustomList


class TestCustomList(unittest.TestCase):
    def setUp(self):
        self.custom = CustomList()

    def tearDown(self):
        print("TD")

    def test_successful_creation(self):
        self.assertEqual(self.custom, [])

        self.custom = CustomList([1, 2, 3])
        self.assertEqual(self.custom, [1, 2, 3])

    def test_lt_eq_gt(self):
        a = CustomList([1, 1, 2])
        b = CustomList([2, 1])
        c = CustomList()

        self.assertTrue(a > b)
        self.assertFalse(a == b)
        self.assertFalse(a < b)

        self.assertTrue(a > c)
        self.assertFalse(a == c)
        self.assertFalse(a < c)

    def test_add(self):
        a = CustomList([5, 1, 3, 7])
        b = CustomList([1, 2, 7])
        lst = [1, 2, 7]
        check = CustomList([6, 3, 10, 7])

        self.assertTrue(isinstance(a + b, CustomList))
        self.assertTrue(isinstance(a + lst, CustomList))
        self.assertTrue(isinstance(lst + a, CustomList))

        self.assertEqual(a+b, check)
        self.assertEqual(a + lst, check)
        self.assertEqual(lst + a, check)

    def test_sub(self):
        a = CustomList([5, 1, 3, 7])
        b = CustomList([1, 2, 7])
        lst = CustomList([1, 2, 7])
        check = CustomList([4, -1, -4, 7])
        check2 = CustomList([-4, 1, 4, -7])

        self.assertTrue(isinstance(a - b, CustomList))
        self.assertTrue(isinstance(a - lst, CustomList))
        self.assertTrue(isinstance(lst - a, CustomList))

        self.assertEqual(a - b, check)
        self.assertEqual(a - lst, check)
        self.assertEqual(lst - a, check2)

    def test_corner_cases(self):
        empty = CustomList()
        empty_lst = []
        a = CustomList([1, 2, 3])

        self.assertEqual(a + empty, a)
        self.assertEqual(a - empty, a)

        self.assertEqual(a + empty_lst, a)
        self.assertEqual(a - empty_lst, a)

    def test_Custom_constancy(self):
        start_val = CustomList([1, 2, 3])
        a = CustomList([1, 2, 3])
        c = CustomList()
        lst = [1, 2]
        c = a + a
        c = a - lst
        c = lst + a
        self.assertEqual(a, start_val)

    def test__str__method(self):
        x = CustomList([1, 2])
        y = CustomList([])
        self.assertEqual(x.__str__(), '[1, 2], sum = 3.00')
        self.assertEqual(y.__str__(), '[], sum = 0.00')


if __name__ == "__main__":
    unittest.main()
