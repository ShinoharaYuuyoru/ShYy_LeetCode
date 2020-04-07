// 1. Quicksort implementation and solution.
// 1324ms 5.23%, 10MB 100.00%.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> numsDplc = nums;

        quickSort(numsDplc, 0, numsDplc.size() - 1);

        int left = INT_MAX;
        int right = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != numsDplc[i]) {
                left = min(left, i);
                right = max(right, i);
            }
        }

        int ANS = 0;
        if (left < right) {
            ANS = right - left + 1;
        }
        else {
            ANS = 0;
        }

        return ANS;
    }

private:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            // 1. Partition
            int pivot = nums[right];

            int current = left;
            for (int i = left; i < right; i++) {
                if (nums[i] < pivot) {
                    int temp = nums[current];
                    nums[current] = nums[i];
                    nums[i] = temp;

                    current++;
                }
            }
            int temp = nums[current];
            nums[current] = nums[right];
            nums[right] = temp;

            // 2. Recursion
            quickSort(nums, left, current - 1);
            quickSort(nums, current + 1, right);
        }
    }
};


// 2. Stack
// 48ms 35.71%, 9MB 100.00%.
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> s;

        int left = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            while (s.empty() == false && nums[s.top()] > nums[i]) {
                left = min(left, s.top());
                s.pop();
            }

            s.push(i);
        }

        // Clear stack
        while (s.empty() == false) {
            s.pop();
        }

        int right = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (s.empty() == false && nums[s.top()] < nums[i]) {
                right = max(right, s.top());
                s.pop();
            }

            s.push(i);
        }

        if (left < right) {
            return right - left + 1;
        }
        else {
            return 0;
        }
    }
};