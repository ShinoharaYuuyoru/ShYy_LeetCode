class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> g(n, vector<int>(m, 1));

		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				g[i][j] = g[i - 1][j] + g[i][j - 1];
			}
		}

		return g[n - 1][m - 1];
	}
};