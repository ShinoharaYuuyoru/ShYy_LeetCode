class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ANS;

        int maxVal = INT_MIN;
        for (int i = 0; i < nums.size() - k + 1; i++) {
            // First time
            if (maxVal == INT_MIN) {
                for (int j = i; j < i + k; j++) {
                    if (nums[j] > maxVal) {
                        maxVal = nums[j];
                    }
                }
            }
            // i >= 1
            else {
                if (nums[i + k - 1] > maxVal) {
                    maxVal = nums[i + k - 1];
                }
                else {
                    // pop max
                    if (nums[i - 1] == maxVal) {
                        maxVal = INT_MIN;       // Reset maxVal
                        for (int j = i; j < i + k; j++) {
                            if (nums[j] > maxVal) {
                                maxVal = nums[j];
                            }
                        }
                    }
                    // max still in the window
                    else {
                        ;
                    }
                }
            }

            ANS.push_back(maxVal);
        }

        return ANS;
    }
};