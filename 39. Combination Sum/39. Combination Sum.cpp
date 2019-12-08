class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end(), greater<int>());       // Descending.

		vector<int> currentComb;
		dfs(candidates, target, currentComb, 0);

		return ANS;
	}

private:
	vector<vector<int>> ANS;

	void dfs(vector<int>& candidates, int target, vector<int> currentComb, int position) {
		// Return condition.
		if (target == 0) {
			ANS.push_back(currentComb);

			return;
		}
		else {
			for (int itr = position; itr < candidates.size(); itr++) {
				if (candidates[itr] <= target) {
					currentComb.push_back(candidates[itr]);
					dfs(candidates, target - candidates[itr], currentComb, itr);
					currentComb.pop_back();
				}
			}
		}
	}
};