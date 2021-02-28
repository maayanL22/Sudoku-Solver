# no imports

def main():
    # board = enter_board()
    board1 = [[0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0],
              [0, 0, 0, 0, 0, 0, 0, 0, 0]]
    print_board(board1)
    solve(board1)
    print("\n\n")
    print_board(board1)


def solve(board):
    """
    Solves a sudoku board using backtracking
    :parameter board: 2d list of ints
    :return: solution
    """
    find = find_empty(board)
    if find is not None:  # if there's an empty place on the board
        row, col = find
    else:  # the board is full which means the solution was found
        return True

    for i in range(1, 10):
        if valid(board, (row, col), i):
            board[row][col] = i

            if solve(board):
                return True

            board[row][col] = 0

    return False


def valid(board, pos, num):
    """
    Returns if the attempted move is valid
    :parameter board: 2d list of ints
    :parameter pos: (row, col)
    :parameter num: int
    :return: bool
    """

    # Check row
    for i in range(0, len(board)):
        if board[pos[0]][i] == num and pos[1] != i:
            return False

    # Check Col
    for i in range(0, len(board)):
        if board[i][pos[1]] == num and pos[0] != i:
            return False

    # Check box

    box_x = pos[1]//3
    box_y = pos[0]//3

    for i in range(box_y*3, box_y*3 + 3):
        for j in range(box_x*3, box_x*3 + 3):
            if board[i][j] == num and (i, j) != pos:
                return False

    return True


def find_empty(board):
    """
    Returns an empty place on the board
     :parameter board: game board
     :return: (int,int) - (row,col)
     if there's no empty place on the board, returns None
    """
    for i in range(len(board)):
        for j in range(len(board[0])):
            if board[i][j] == 0:
                return i, j

    return None


def print_board(board):
    """
    Prints the game board
     parameter board: game board
     return: nothing
    """

    for i in range(len(board)):
        if i % 3 == 0 and i != 0:
            print('- - - - - - - - - - - - - -')
        for j in range(len(board[0])):
            if j % 3 == 0:
                print(" | ", end="")

            if j == 8:
                print(board[i][j], end='\n')
            else:
                print(str(board[i][j]) + " ", end="")


def enter_board():
    """
    Gets the sudoku board from the user
     :param: None
     :return: board
    """

    print("Hello, please enter the board you would like to solve, enter 0 for empty places")
    board = []
    for i in range(0, 9):
        board.append([])

    for i in range(len(board)):
        for j in range(0, 9):
            board[i].append(input("Please enter the number for row: {}, and column: {}\n".format(i, j)))

    return board


main()
