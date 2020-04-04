// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/discuss/92958/c%2B%2B-solution-O(1)-space
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? (-nums[m]) : nums[m];
        }

        vector<int> ANS;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ANS.push_back(i + 1);
            }
        }

        return ANS;
    }
};