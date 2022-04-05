##Player_0 with "x" marks(He/she also starts the game)
##Player_1 with "o" marks

##names for marks position are:
#|0| |1| |2|
#+-+-+-+-+-+
#|3| |4| |5|
#+-+-+-+-+-+
#|6| |7| |8|

##EXAMPLE:
##Player_0>>>>>1
##Player_1>>>>>2
##Player_0>>>>>3

#| | |x| |o|
#+-+-+-+-+-+
#|x| | | | |
#+-+-+-+-+-+
#| | | | | |

##Have fun!

class TicTacGame(object):

    def __init__(self):
        self.table = [' ' for i in range(9)]
        self.active_player = 0
    def validate_input(self,fill):
        if len(fill) != 1:
            print("one turn must be number from 0 to 8, error code = -1")
            return False
        valid_symbols = set('012345678')
        if fill not in valid_symbols:
            print("one turn must be number from 0 to 8, eroor code = -2")
            return False
        if  self.table[int(fill)] != ' ':
            print("illegal_move")
            return False
        return True

    def check_winner(self):
        mark = 'xo'[self.active_player]
        for k in range(0,7,3):
            if (self.table[k] == mark) and (self.table[k + 1] == mark) and (self.table[k + 2] == mark):
                return self.active_player
        for i in range(0,3):
            if (self.table[i] == mark) and (self.table[i + 3] == mark) and (self.table[i + 6] == mark):
                return self.active_player
        if (self.table[0] == mark) and (self.table[4] == mark) and (self.table[8] == mark):
                return self.active_player
        if (self.table[2] == mark) and (self.table[4] == mark) and (self.table[6] == mark):
                return self.active_player
        #print(set(self.table))
        if ' ' not in set(self.table):
            return -1 #If Draw

        self.active_player = (self.active_player + 1) % 2

    def one_move(self,command):
        self.table[command] = 'xo'[self.active_player]

    def start_game(self):
        playing = True
        self.show_board()
        while playing:
            print('Player_{0:d}>>>>>'.format(self.active_player))
            fill = input()
            if not self.validate_input(fill):
                continue
            command = int(fill)
            self.one_move(command)
            self.show_board()
            one_turn_res = self.check_winner()
            if one_turn_res == 0:
                print("Player with_marks \"x\" has won")
                playing = False
                return 0
            if one_turn_res == 1:
                print("Player with_marks \"o\" has won")
                playing = False
                return 1
            if one_turn_res == -1:
                print("DRAW!")
                playing = False
                return -1

    def show_board(self):
        for i in range(3):
            if i > 0:
                print("+-+-+-+-+-+")
            for j in range(3):
                print('|{0:s}| '.format(self.table[3 * i + j]), end='')
            print()

    def clean_table(self):
        self.table = [' ' for i in range(9)]
        self.active_player = 0


if __name__ == "__main__":
    game = TicTacGame()
    game.start_game()