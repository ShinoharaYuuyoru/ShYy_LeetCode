class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0) {
            cout << "nums input error!" << endl;

            exit(1);
        }

        unordered_map<int, int> counter;        // Hash
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            auto search = counter.find(num);
            if (search == counter.end()) {
                // First counted.
                counter[num] = 1;
            }
            else {
                // Already exist. Add 1.
                counter[num]++;
            }
        }

        int majorityEle = INT_MIN;
        int appearNum = INT_MIN;
        for (auto pair : counter) {
            if (pair.second > appearNum) {
                majorityEle = pair.first;
                appearNum = pair.second;
            }
        }

        return majorityEle;
    }
};