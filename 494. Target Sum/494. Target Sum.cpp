// 1. Recursion with Memoization
// 16ms 76.86%, 35.4MB 30.77%.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> memo(nums.size(), vector<int>(2001, INT_MIN));

        return calculate(nums, 0, 0, S, memo);
    }

private:
    int calculate(vector<int>& nums, int i, int sum, int S, vector<vector<int>>& memo) {
        if (i == nums.size()) {
            if (sum == S) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            if (memo[i][sum + 1000] != INT_MIN) {
                return memo[i][sum + 1000];
            }
            else {
                int add = calculate(nums, i + 1, sum + nums[i], S, memo);
                int subtract = calculate(nums, i + 1, sum - nums[i], S, memo);
                memo[i][sum + 1000] = add + subtract;

                return memo[i][sum + 1000];
            }
        }
    }
};


// 2. 2D DP
// 44ms 59.34%, 35.2MB 30.77%.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>> dp(nums.size(), vector<int>(2001, 0));
        dp[0][nums[0] + 1000]++;
        dp[0][-nums[0] + 1000]++;

        for (int i = 1; i < nums.size(); i++) {
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[i - 1][sum + 1000] > 0) {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }

        return S > 1000 ? 0 : dp[nums.size() - 1][S + 1000];
    }
};


// 3. 1D DP
// 32ms 63.40%, 33.5MB 30.77%.
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> dp(2001, 0);
        dp[nums[0] + 1000]++;
        dp[-nums[0] + 1000]++;

        for (int i = 1; i < nums.size(); i++) {
            vector<int> next(2001);
            for (int sum = -1000; sum <= 1000; sum++) {
                if (dp[sum + 1000] > 0) {
                    next[sum + nums[i] + 1000] += dp[sum + 1000];
                    next[sum - nums[i] + 1000] += dp[sum + 1000];
                }
            }

            dp = next;
        }

        return S > 1000 ? 0 : dp[S + 1000];
    }
};