class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int noneZeroPtr = 0;
        int travPtr = 0;
        for (travPtr = 0; travPtr < nums.size(); travPtr++) {
            if (nums[travPtr] != 0) {
                nums[noneZeroPtr] = nums[travPtr];
                noneZeroPtr++;
            }
        }
        for (; noneZeroPtr < nums.size(); noneZeroPtr++) {
            nums[noneZeroPtr] = 0;
        }
    }
};