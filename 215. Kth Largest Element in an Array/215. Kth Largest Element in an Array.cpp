// 1. Swapping.
// 8ms 97.71%, 7MB 100.00%.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return nums[0];
        }

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int pivotPos = partition(nums, left, right);
            if (pivotPos + 1 == k) {
                return nums[pivotPos];
            }
            else if (pivotPos + 1 < k) {
                // Search rightside
                left = pivotPos + 1;
            }
            else {
                // Search leftside
                right = pivotPos - 1;
            }
        }

        // This should not happen.
        return -1;
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivotIndex = left + (right - left) / 2;
        int pivot = nums[pivotIndex];

        swap(nums, pivotIndex, right);      // Save the pivot value in nums[right].

        // We part all numbers into two part:
        // Pivot
        // Bigger (equal) than pivot: left
        // Smaller than pivot: right
        int leftBound = left;
        int rightBound = right - 1;
        while (leftBound <= rightBound) {
            if (nums[leftBound] >= pivot) {
                leftBound++;
            }
            else if (nums[rightBound] < pivot) {
                rightBound--;
            }
            else {
                // nums[leftBound] < pivot && nums[rightBound] >= pivot.
                swap(nums, leftBound, rightBound);
                leftBound++;
                rightBound--;
            }
        }

        // Return the pivot into center.
        swap(nums, leftBound, right);

        // Return the pivotIndex
        return leftBound;
    }

    void swap(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;

        return;
    }
};


// 2. Priority queue
// 12ms 78.44%, 7MB 100.00%.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > Q;

        for (int i = 0; i < nums.size(); i++) {
            if (Q.size() < k) {
                Q.push(nums[i]);
            }
            else {       // Q.size() == k
                if (Q.top() < nums[i]) {
                    Q.pop();
                    Q.push(nums[i]);
                }
            }
        }

        return Q.top();
    }
};