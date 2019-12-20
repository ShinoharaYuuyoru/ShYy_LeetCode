class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// DP
		int maxGlobal = nums[0];
		int maxLocal = nums[0];

		for (int numsItr = 1; numsItr < nums.size(); numsItr++) {
			maxLocal = max(nums[numsItr], maxLocal + nums[numsItr]);
			maxGlobal = max(maxLocal, maxGlobal);
		}

		return maxGlobal;
	}
};