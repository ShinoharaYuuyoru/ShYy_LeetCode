class Solution {
public:
	void sortColors(vector<int>& nums) {
		int globalPtr = 0;
		int assign0ptr = 0;
		int assign2ptr = nums.size() - 1;

		for (globalPtr = 0; globalPtr <= assign2ptr;)
		{
			if (nums[globalPtr] == 0) {
				// Paste 0
				swap(nums[assign0ptr], nums[globalPtr]);
				assign0ptr++;
				globalPtr++;
			}
			else if (nums[globalPtr] == 2) {
				// Paste 2
				swap(nums[assign2ptr], nums[globalPtr]);
				assign2ptr--;
			}
			else {
				globalPtr++;
			}
		}

		return;
	}
};