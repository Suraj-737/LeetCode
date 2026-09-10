class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            unordered_map<int, int> mp1;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                mp1[board[i][j]]++;
                if (mp1[board[i][j]] > 1)
                    return false;
            }
        }
        for (int i = 0; i < 9; i++) {

            unordered_map<int, int> mp1;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.')
                    continue;
                mp1[board[j][i]]++;
                if (mp1[board[j][i]] > 1)
                    return false;
            }
        }
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {

                unordered_map<char, int> mp;

                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {

                        if (board[i][j] == '.')
                            continue;

                        mp[board[i][j]]++;

                        if (mp[board[i][j]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};