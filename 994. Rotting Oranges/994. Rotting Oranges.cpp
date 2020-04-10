class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> sign(grid.size(), vector<bool>(grid[0].size(), false));
        queue<vector<int>> rottenQ;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    sign[i][j] = true;
                    vector<int> nowPos{ i, j, 0 };
                    rottenQ.push(nowPos);
                }
            }
        }

        int ANS = 0;
        while (rottenQ.empty() == false) {
            vector<int> nowPos = rottenQ.front();
            int i = nowPos[0];
            int j = nowPos[1];
            int nowMin = nowPos[2];

            // left
            int left = j - 1;
            if (left >= 0 && grid[i][left] == 1 && sign[i][left] == false) {
                sign[i][left] = true;
                vector<int> nowPos{ i, left, nowMin + 1 };
                rottenQ.push(nowPos);
            }

            // right
            int right = j + 1;
            if (right < grid[0].size() && grid[i][right] == 1 && sign[i][right] == false) {
                sign[i][right] = true;
                vector<int> nowPos{ i, right, nowMin + 1 };
                rottenQ.push(nowPos);
            }

            // up
            int up = i - 1;
            if (up >= 0 && grid[up][j] == 1 && sign[up][j] == false) {
                sign[up][j] = true;
                vector<int> nowPos{ up, j, nowMin + 1 };
                rottenQ.push(nowPos);
            }

            // down
            int down = i + 1;
            if (down < grid.size() && grid[down][j] == 1 && sign[down][j] == false) {
                sign[down][j] = true;
                vector<int> nowPos{ down, j, nowMin + 1 };
                rottenQ.push(nowPos);
            }

            rottenQ.pop();

            ANS = nowMin;
        }

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (sign[i][j] == false && grid[i][j] != 0) {
                    return -1;
                }
            }
        }

        return ANS;
    }
};