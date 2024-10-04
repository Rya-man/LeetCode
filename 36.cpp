class Solution {
public:
    bool isValidRow(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> st;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                if (st.count(board[i][j]))
                    return false;
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidColumn(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            unordered_set<char> st;
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.')
                    continue;
                if (st.count(board[j][i]))
                    return false;
                st.insert(board[j][i]);
            }
        }
        return true;
    }
    bool isValidBox(vector<vector<char>>& board) {
        for (int i = 1; i < 9; i += 3) {

            for (int j = 1; j < 9; j += 3) {
                char arr[9] = {
                    board[i - 1][j - 1], board[i - 1][j],
                    board[i][j - 1],     board[i][j],
                    board[i + 1][j - 1], board[i - 1][j + 1],
                    board[i][j + 1],     board[i + 1][j],
                    board[i + 1][j + 1],
                };
                unordered_set<char> st;
                for (int it = 0; it < 9; ++it) {
                    if (arr[it] == '.')
                        continue;
                    if (st.count(arr[it]))
                        return false;
                    st.insert(arr[it]);
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        return isValidRow(board) && isValidColumn(board) && isValidBox(board);
    }
};
