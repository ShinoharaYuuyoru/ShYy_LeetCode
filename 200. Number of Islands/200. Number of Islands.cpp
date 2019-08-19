class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int landNum = 0;
		if (grid.size() == 0)
		{
			return 0;
		}

		int X = grid.size();
		int Y = grid[0].size();

		vector<vector<bool>> gridSign(X, vector<bool>(Y));
		for (int itrX = 0; itrX < X; itrX++)
		{
			for (int itrY = 0; itrY < Y; itrY++)
			{
				gridSign[itrX][itrY] = false;
			}
		}

		for (int itrX = 0; itrX < X; itrX++)
		{
			for (int itrY = 0; itrY < Y; itrY++)
			{
				if (grid[itrX][itrY] == '0')
				{
					continue;
				}
				else
				{
					if (gridSign[itrX][itrY] == true)
					{
						continue;
					}
					else
					{
						queue<pair<int, int>> Q;
						gridSign[itrX][itrY] = true;
						Q.push(pair<int, int>(itrX, itrY));

						while (!Q.empty())
						{
							pair<int, int> nowPosition = Q.front();
							Q.pop();
							int nowX = nowPosition.first;
							int nowY = nowPosition.second;

							// Add queue
							pushUnsignedLand(Q, grid, gridSign, nowX - 1, nowY);
							pushUnsignedLand(Q, grid, gridSign, nowX + 1, nowY);
							pushUnsignedLand(Q, grid, gridSign, nowX, nowY - 1);
							pushUnsignedLand(Q, grid, gridSign, nowX, nowY + 1);
						}

						landNum++;
					}
				}
			}
		}

		return landNum;
	}

	void pushUnsignedLand(queue<pair<int, int>>& Q, vector<vector<char>>& grid, vector<vector<bool>>& gridSign, int x, int y)
	{
		if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
		{
			if (grid[x][y] == '1' && gridSign[x][y] == false)
			{
				gridSign[x][y] = true;
				Q.push(pair<int, int>(x, y));
			}
		}
	}
};