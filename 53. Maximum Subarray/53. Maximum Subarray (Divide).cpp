class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		// Divide and conquer

		return getMax(nums, 0, nums.size() - 1);
	}

private:
	int getMax(vector<int>& nums, int leftPosi, int rightPosi) {
		if (leftPosi > rightPosi) {
			return INT_MIN;     // Because there will be negative numbers.
		}

		if (leftPosi == rightPosi) {
			return nums[leftPosi];
		}

		int mid = (leftPosi + rightPosi) / 2;
		int maxLeftPartSum = getMax(nums, leftPosi, mid - 1);
		int maxRightPartSum = getMax(nums, mid + 1, rightPosi);

		// Merge middle number.
		int maxMidPartSum = nums[mid];
		int tempSum = nums[mid];
		for (int leftItr = mid - 1; leftItr >= leftPosi; leftItr--) {
			tempSum += nums[leftItr];
			maxMidPartSum = max(tempSum, maxMidPartSum);
		}
		tempSum = maxMidPartSum;
		for (int rightItr = mid + 1; rightItr <= rightPosi; rightItr++) {
			tempSum += nums[rightItr];
			maxMidPartSum = max(tempSum, maxMidPartSum);
		}

		return max(max(maxLeftPartSum, maxMidPartSum), maxRightPartSum);
	}
};