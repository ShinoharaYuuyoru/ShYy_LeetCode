class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();        // row num
		int m = grid[0].size();     // column num

		vector<vector<int>> dpGraph(n, vector<int>(m, 0));

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				if (j == 0)
				{
					if (i == 0)
					{
						// At [0][0]
						dpGraph[j][i] = grid[j][i];
					}
					else
					{
						// At [0][x]
						dpGraph[j][i] = dpGraph[j][i - 1] + grid[j][i];
					}
				}
				else
				{
					if (i == 0)
					{
						// At [x][0]
						dpGraph[j][i] = dpGraph[j - 1][i] + grid[j][i];
					}
					else
					{
						// At [x][y], normal situation.
						dpGraph[j][i] = min(dpGraph[j - 1][i], dpGraph[j][i - 1]) + grid[j][i];
					}
				}
			}
		}

		return dpGraph[n - 1][m - 1];
	}
};