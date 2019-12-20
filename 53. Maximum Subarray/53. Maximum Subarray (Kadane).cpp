class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int maxSum = nums[0];

		int tempSum = 0;
		for (auto num : nums) {
			tempSum += num;
			if (maxSum < tempSum) {
				maxSum = tempSum;
			}
			if (tempSum < 0) {
				tempSum = 0;
			}
		}

		return maxSum;
	}
};