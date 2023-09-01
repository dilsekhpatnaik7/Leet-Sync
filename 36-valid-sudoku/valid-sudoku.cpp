class Solution {
public:
    bool isValid(vector<vector<char>> &board, char ch, int row, int col) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch) return false;
            
            if (board[row][i] == ch) return false;
        
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    board[i][j] = '.';
                    if (!isValid(board, ch, i, j)) return false;
                    board[i][j] = ch;
                }
            }
        }
        return true;
    }
};