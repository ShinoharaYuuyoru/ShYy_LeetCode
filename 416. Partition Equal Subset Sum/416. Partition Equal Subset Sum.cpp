// DP
// https://leetcode.com/problems/partition-equal-subset-sum/discuss/90592/01-knapsack-detailed-explanation
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        if (sum % 2 == 0) {
            int partSum = sum / 2;

            vector<bool> dp(partSum + 1, false);
            dp[0] = true;

            for (auto num : nums) {
                for (int i = partSum; i >= num; i--) {
                    dp[i] = dp[i - num] || dp[i];       // Pick or not pick.
                }
            }

            return dp[partSum];
        }
        else {
            return false;
        }
    }
};