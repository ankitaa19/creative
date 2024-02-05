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