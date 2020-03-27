class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        int duplNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) == hash.end()) {
                hash.insert(nums[i]);
            }
            else {
                duplNum = nums[i];
                break;
            }
        }

        return duplNum;
    }
};