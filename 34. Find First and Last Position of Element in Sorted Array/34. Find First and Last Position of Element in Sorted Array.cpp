class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> ANS = { -1, -1 };

		if (nums.size() == 0) {
			return ANS;
		}

		int start = 0;
		int end = nums.size() - 1;
		for (; start <= end;) {
			int mid = (start + end) / 2;
			if (nums[mid] == target) {
				ANS.clear();

				int left = mid;
				while (true) {
					if (left < start) {
						left++;
						break;
					}
					else {
						if (nums[left] == target) {
							left--;
						}
						else {
							left++;
							break;
						}
					}
				}
				ANS.push_back(left);

				int right = mid;
				while (true) {
					if (right > end) {
						right--;
						break;
					}
					else {
						if (nums[right] == target) {
							right++;
						}
						else {
							right--;
							break;
						}
					}
				}
				ANS.push_back(right);

				break;
			}
			else if (nums[mid] < target) {
				start = mid + 1;
				continue;
			}
			else if (nums[mid] > target) {
				end = mid - 1;
				continue;
			}
		}

		return ANS;
	}
};