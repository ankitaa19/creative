init(autoreset=True)  # Initialize colorama

# Function to display the game board
def display_board(board):
    for row in board:
        row_str = ""
        for cell in row:
            if cell == 'X':
                row_str += Fore.RED + 'X' + Style.RESET_ALL
            elif cell == 'O':
                row_str += 'O'
            else:
                row_str += '-'
            row_str += " | "
        print(row_str[:-2])  # Remove the trailing " | "
        print("-" * (len(row) * 4 - 1))  # Separator line

# Function to check for a win
def check_win(board, player):
    size = len(board)
    
    # Check rows and columns
    for i in range(size):
        if all(cell == player for cell in board[i]) or all(row[i] == player for row in board):
            return True

    # Check diagonals
    if all(board[i][i] == player for i in range(size)) or all(board[i][size - 1 - i] == player for i in range(size)):
        return True

    return False

# Main game loop
def tic_tac_toe():
    size = 5  # Size of the board (rows and columns)
    board = [[' ' for _ in range(size)] for _ in range(size)]
    current_player = 'X'
    
    while True:
        display_board(board)
        
        row = int(input(f"Player {current_player}, enter row (0-{size-1}): "))
        col = int(input(f"Player {current_player}, enter column (0-{size-1}): "))
        
        if board[row][col] == ' ':
            board[row][col] = current_player
            if check_win(board, current_player):
                display_board(board)
                print(f"Player {current_player} wins!")
                break
            elif all(cell != ' ' for row in board for cell in row):
                display_board(board)
                print("It's a tie!")
                break
            current_player = 'O' if current_player == 'X' else 'X'
        else:
            print("That cell is already taken. Try again.")

if _name_ == "_main_":
    tic_tac_toe()
