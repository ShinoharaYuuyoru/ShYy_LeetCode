class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) {
            cout << "Input error!" << endl;

            exit(1);
        }
        if (nums.size() == 1) {
            return 0;
        }

        int left = -1, now = 0, right = 1;
        while (true) {
            if (now == 0) {
                if (nums[now] > nums[right]) {
                    return now;
                }
            }
            else if (now == nums.size() - 1) {
                if (nums[now] > nums[left]) {
                    return now;
                }
            }
            else {
                if (nums[now] > nums[left] && nums[now] > nums[right]) {
                    return now;
                }
            }

            left++;
            now++;
            right++;
        }
    }
};