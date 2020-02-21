class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // Preprocessing
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());

        // Start
        vector<vector<int>> ANS;

        int length = nums.size();
        int maxNum = (int)pow(2, length);

        // bitset can visit by [], and the lowest position is 0.
        // The iterator should smaller than length.
        int counter = 0;
        for (counter = 0; counter < maxNum; counter++) {
            bitset<sizeof(int) * 8> b(counter);

            vector<int> subset;

            int checker = 0;
            for (checker = 0; checker < length; checker++) {
                if (b[checker] == 1) {
                    subset.push_back(nums[checker]);
                }
            }
            ANS.push_back(subset);
        }

        return ANS;
    }
};