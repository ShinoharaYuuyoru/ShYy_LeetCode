// 1. Brute Force, O(2^n), O(n^2)
// TLE
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return getLIS(nums, INT_MIN, 0);
    }

private:
    int getLIS(vector<int>& nums, int prev, int curPos) {
        if (curPos == nums.size()) {
            return 0;
        }

        int taken = 0;
        if (nums[curPos] > prev) {
            taken = getLIS(nums, nums[curPos], curPos + 1) + 1;
        }

        int notTaken = getLIS(nums, prev, curPos + 1);

        return max(taken, notTaken);
    }
};


// 2. Recursion with Memorization
// 416ms 5.32%, 109.2MB 6.25%.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(nums.size(), -1));

        return getLIS(nums, -1, 0, memo);
    }

private:
    int getLIS(vector<int>& nums, int preIdx, int curPos, vector<vector<int>>& memo) {
        if (curPos == nums.size()) {
            return 0;
        }

        if (memo[preIdx + 1][curPos] >= 0) {
            return memo[preIdx + 1][curPos];
        }

        int taken = 0;
        if (preIdx < 0 || nums[curPos] > nums[preIdx]) {
            taken = getLIS(nums, curPos, curPos + 1, memo) + 1;
        }

        int notTaken = getLIS(nums, preIdx, curPos + 1, memo);

        memo[preIdx + 1][curPos] = max(taken, notTaken);

        return memo[preIdx + 1][curPos];
    }
};


// 3. DP
// 56ms 17.17%, 6.5MB 100.00%.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        vector<int> dp(nums.size());
        dp[0] = 1;

        int maxLISLength = 1;

        for (int i = 1; i < nums.size(); i++) {
            int maxVal = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] > maxVal) {
                        maxVal = dp[j];
                    }
                }
            }
            dp[i] = maxVal + 1;
            if (dp[i] > maxLISLength) {
                maxLISLength = dp[i];
            }
        }

        return maxLISLength;
    }
};


// 4. DP with Binary Search
// 0ms 100.00%, 6.3MB 100.00%.
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for (auto num : nums) {
            if (dp.size() == 0) {
                dp.push_back(num);
            }
            else {
                vector<int>::iterator BSearch = binarySearch(dp, num);
                if (BSearch == dp.end()) {
                    dp.insert(BSearch, num);
                }
                else {
                    // *Bsearch cannot <= num after the binarySearch.
                    *BSearch = num;
                }
            }
        }

        return dp.size();
    }

private:
    vector<int>::iterator binarySearch(vector<int>& dp, int num) {
        vector<int>::iterator left = dp.begin();
        vector<int>::iterator right = dp.end() - 1;
        while (left < right) {
            vector<int>::iterator mid = left + (right - left) / 2;
            if (*mid == num) {
                return mid;
            }
            else if (*mid > num) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        if (left != right) {
            cout << "Error: left != right" << endl;

            exit(1);
        }
        else {
            if (*left < num) {
                return left + 1;
            }
            else {
                return left;
            }
        }
    }
};