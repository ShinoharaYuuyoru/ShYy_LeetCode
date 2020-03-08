class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (adjacentSearch(board, word, i, j, 0) == true) {
                    return true;
                }
            }
        }

        return false;
    }

private:
    bool adjacentSearch(vector<vector<char>>& board, string word, int i, int j, int index) {
        // Exist. Check over
        if (index == word.size()) {
            return true;
        }

        // Out of boundary
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) {
            return false;
        }

        // Visited point
        if (word[index] == '*') {
            return false;
        }

        // Incorrect point
        if (board[i][j] != word[index]) {w
            return false;
        }

        // Else
        board[i][j] = '*';      // Mark as visited.
        bool isCorrectPoint =
            adjacentSearch(board, word, i, j + 1, index + 1) ||
            adjacentSearch(board, word, i, j - 1, index + 1) ||
            adjacentSearch(board, word, i + 1, j, index + 1) ||
            adjacentSearch(board, word, i - 1, j, index + 1);

        // Restore
        board[i][j] = word[index];

        return isCorrectPoint;
    }
};