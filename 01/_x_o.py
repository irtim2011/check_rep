import unittest
from x_o_PLAY import TicTacGame


class TestTicTacGame(unittest.TestCase):
    def setUp(self):
        self.game = TicTacGame()

    def tearDown(self):
        self.game.clean_table()
        print("TD")
    def Prepare_win_tables(self, mark):
        lst = [[mark, mark, mark, ' ', ' ', ' ', ' ', ' ', ' '],
               [' ', ' ', ' ', mark, mark, mark, ' ', ' ', ' '],
               [' ', ' ', ' ', ' ', ' ', ' ', mark, mark, mark],
               [mark, ' ', ' ', mark, ' ', ' ', mark, ' ', ' '],
               [' ', mark, ' ', ' ', mark, ' ', ' ', mark, ' '],
               [' ', ' ', mark, ' ', ' ', mark, ' ', ' ', mark],
               [mark, ' ', ' ', ' ', mark, ' ', ' ', ' ', mark],
               [' ', ' ', mark, ' ', mark, ' ', mark, ' ', ' ']
               ]
        return lst


    def test_invalid_input(self):
        self.assertFalse(self.game.validate_input("я дракон"))
        self.assertFalse(self.game.validate_input("100"))
        self.assertFalse(self.game.validate_input("*"))

        self.game.table[0] = 'x'
        self.assertFalse(self.game.validate_input("0"))

    def test_valid_input(self):
        commands = ['0','1','2','3','4','5','6','7','8']
        for fill in commands:
            self.assertTrue(self.game.validate_input(fill))

    def test_boarder_conditions(self):
        self.assertFalse(self.game.validate_input("-1"))
        self.assertFalse(self.game.validate_input("9"))

    def test_one_move(self):
        self.game.active_player = 0
        self.game.one_move(0)
        self.assertEqual(self.game.table[0], "x")

        self.game.active_player = 1
        self.game.one_move(1)
        self.assertEqual(self.game.table[1], "o")

    def test_check_winner(self):
        control = 0
        for mark in 'o':
            if mark == 'o':
                control = 1
                self.game.active_player = 1
            lst = self.Prepare_win_tables(mark)
            for element in lst:
                self.game.table = element
                self.assertEqual(self.game.check_winner(), control)

    def test_check_winner_DRAW(self):
        self.game.table = ['o', 'o', 'x', 'x', 'x', 'o', 'o', 'x', 'x']
        self.assertEqual(self.game.check_winner(), -1)

if __name__ == "__main__":
    unittest.main()
