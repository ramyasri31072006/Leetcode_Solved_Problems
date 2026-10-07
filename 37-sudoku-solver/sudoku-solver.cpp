class Solution {
private:
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char k = '1'; k <= '9'; k++) {
                        if (is_valid(board, k, i, j)) {
                            board[i][j] = k;
                            if (solve(board) == false) {
                                board[i][j] = '.';
                            } 
                            else {
                                return true;
                            }
                        }
                        
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool is_valid(vector<vector<char>>& board, char c, int i, int j) {
        for (int k = 0; k < 9; k++) {
            if (board[i][k] == c)
                return false;
            if (board[k][j] == c)
                return false;

            if (board[3 * (i / 3) + k / 3][3 * (j / 3) + k % 3]== c)
                return false;
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};