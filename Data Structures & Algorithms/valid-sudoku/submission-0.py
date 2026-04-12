class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows_table = [{} for _ in range(len(board))]
        cols_table = [{} for _ in range(len(board[0]))]
        square_table = [[{} for _ in range(3)] for _ in range(3)]

        # board[row][col]
        for row in range(len(board)):
            for col in range(len(board[0])):
                digit = board[row][col]
                if digit == ".":
                    continue
                elif digit in rows_table[row]:
                    #print(f"{digit} already in {row}-th row")
                    #print(rows_table[row])
                    return False
                elif digit in cols_table[col]:
                    #print(f"{digit} already in {col}-th col")
                    #print(cols_table[col])
                    return False
                elif digit in square_table[row//3][col//3]:
                    return False
                else:
                    rows_table[row][digit] = True
                    cols_table[col][digit] = True
                    square_table[row//3][col//3][digit] = True
        
        return True