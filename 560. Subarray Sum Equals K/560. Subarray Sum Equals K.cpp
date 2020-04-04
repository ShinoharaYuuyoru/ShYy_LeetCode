// 1. Without space
// 1236ms 5.48%, 7.6MB 100.00%.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ANS = 0;

        for (int start = 0; start < nums.size(); start++) {
            int sum = 0;
            for (int end = start; end < nums.size(); end++) {
                sum += nums[end];
                if (sum == k) {
                    ANS++;
                }
            }
        }

        return ANS;
    }
};


// 2. Hashmap
// 44ms 62.32%, 12.5MB 77.33%.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ANS = 0;
        int sum = 0;

        unordered_map<int, int> hash;
        hash[0] = 1;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            auto search = hash.find(sum - k);
            if (search != hash.end()) {
                ANS += hash[sum - k];
            }

            auto searchSum = hash.find(sum);
            if (searchSum != hash.end()) {
                hash[sum]++;
            }
            else {
                hash[sum] = 1;
            }
        }

        return ANS;
    }
};