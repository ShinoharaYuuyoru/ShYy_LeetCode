class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());     // Ascending.

		vector<int> currentComb;
		dfs(nums, currentComb);

		return ANS;
	}

private:
	vector<vector<int>> ANS;

	void dfs(vector<int> nums, vector<int> currentComb) {
		// Exit condition.
		if (nums.size() == 0) {
			ANS.push_back(currentComb);

			return;
		}
		else {
			for (auto itr = nums.begin(); itr != nums.end(); itr++) {
				int nowNum = *itr;

				currentComb.push_back(nowNum);
				itr = nums.erase(itr);      // Pointing to the next num.

				dfs(nums, currentComb);

				itr = nums.insert(itr, nowNum);      // Redirected to the current num.
				currentComb.pop_back();
			}
		}
	}
};