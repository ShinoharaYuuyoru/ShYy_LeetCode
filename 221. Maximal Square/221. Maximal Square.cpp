// Sliding window
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int matrixHeight = matrix.size();
        int matrixLength = 0;
        if (matrixHeight == 0) {
            return 0;
        }
        else {
            matrixLength = matrix[0].size();
            if (matrixLength == 0) {
                return 0;
            }
        }

        int maxSquareSize = (matrixLength < matrixHeight) ? matrixLength : matrixHeight;

        for (int squareSize = maxSquareSize; squareSize >= 1; squareSize--) {
            for (int j = 0; j <= matrixHeight - squareSize; j++) {
                for (int i = 0; i <= matrixLength - squareSize; i++) {
                    if (checkFilled(matrix, i, j, squareSize) == true) {
                        return squareSize * squareSize;
                    }
                }
            }
        }

        // If there is no square, even the square size is 1, return 0.
        return 0;
    }

private:
    bool checkFilled(vector<vector<char>>& matrix, int i, int j, int squareSize) {
        for (int y = j; y < j + squareSize; y++) {
            for (int x = i; x < i + squareSize; x++) {
                if (matrix[y][x] == '0') {
                    return false;
                }
            }
        }

        return true;
    }
};