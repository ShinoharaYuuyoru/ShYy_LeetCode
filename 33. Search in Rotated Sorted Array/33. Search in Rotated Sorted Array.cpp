class Solution {
public:
	int search(vector<int>& nums, int target) {

		if (nums.empty() == true) {
			return -1;
		}
		else {
			int start = 0;
			int end = nums.size() - 1;

			for (; start <= end;) {
				if (nums[start] < target) {
					start++;
					continue;
				}
				else if (nums[start] == target) {
					return start;
				}

				if (nums[end] > target) {
					end--;
					continue;
				}
				else if (nums[end] == target) {
					return end;
				}

				break;
			}

			return -1;
		}
	}
};