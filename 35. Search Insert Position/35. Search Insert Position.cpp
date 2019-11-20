class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		bool findFlag = false;
		int ANS = 0;

		// Binary search.
		int left = 0;
		int right = nums.size() - 1;
		while (left < right) {
			int middle = (left + right) / 2;
			if (nums[middle] < target) {
				left = middle + 1;
				continue;
			}
			if (nums[middle] > target) {
				right = middle - 1;
				continue;
			}
			if (nums[middle] == target) {
				findFlag = true;
				ANS = middle;
				break;
			}
		}

		// Final.
		if (findFlag == true) {
			return ANS;
		}
		else {
			// Must happen: left == right
			if (nums[left] < target) {
				ANS = left + 1;
			}
			else {
				// If nums[left] > target.
				// This means the target should be inserted at [left] position.
				ANS = left;
			}

			return ANS;
		}
	}
};