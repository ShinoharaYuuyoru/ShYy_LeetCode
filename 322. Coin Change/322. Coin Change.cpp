// 1. Top down DP
// 104ms 20.99%, 11.4MB 94.12%.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        else {
            vector<int> memo(amount);
            return doChange(coins, amount, memo);
        }
    }

private:
    int doChange(vector<int>& coins, int target, vector<int>& memo) {
        if (target < 0) {
            return -1;
        }
        else if (target == 0) {
            return 0;
        }
        else {
            if (memo[target - 1] != 0) {
                return memo[target - 1];
            }
            else {
                int min = INT_MAX;
                for (auto coin : coins) {
                    int res = doChange(coins, target - coin, memo);
                    if (res >= 0 && res < min) {
                        min = res + 1;
                    }
                }
                memo[target - 1] = (min == INT_MAX) ? -1 : min;

                return memo[target - 1];
            }
        }
    }
};


// 2. Bottom up DP
// 60ms 43.13%, 14.1MB 27.45%.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<double> dp(amount + 1, DBL_MAX);     // We cannot use INT because INT_MAX+1 overflowed the INT type.
        dp[0] = 0;

        for (auto coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] != DBL_MAX ? dp[amount] : -1;
    }
};