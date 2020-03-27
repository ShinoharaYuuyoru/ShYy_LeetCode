// 44ms 30.39%, 11.8MB 100.00%.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> exceptProduct;

        vector<int> leftProduct;
        vector<int> rightProduct;

        int product = 1;
        for (int i = 1; i < nums.size(); i++) {
            product = product * nums[i - 1];
            leftProduct.push_back(product);
        }

        product = 1;
        for (int i = nums.size() - 1 - 1; i >= 0; i--) {
            product = product * nums[i + 1];
            rightProduct.push_back(product);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                exceptProduct.push_back(rightProduct[rightProduct.size() - 1]);
            }
            else if (i == nums.size() - 1) {
                exceptProduct.push_back(leftProduct[leftProduct.size() - 1]);
            }
            else {
                exceptProduct.push_back(leftProduct[i - 1] * rightProduct[rightProduct.size() - 1 - i]);
            }
        }

        return exceptProduct;
    }
};


// 1648ms 5.97%, 11.7MB 100.00%.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums:        1   2   3   4   5
        // leftProduct      1   2   6   24
        // rightProduct 120 60  20  5
        vector<int> exceptProduct;

        vector<int> leftProduct;
        vector<int> rightProduct;

        int product = 1;
        for (int i = 1; i < nums.size(); i++) {
            product = product * nums[i - 1];
            leftProduct.push_back(product);
        }

        product = 1;
        for (int i = nums.size() - 1 - 1; i >= 0; i--) {
            product = product * nums[i + 1];
            rightProduct.insert(rightProduct.begin(), product);     // Insert will cost a lot of time!
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                exceptProduct.push_back(rightProduct[0]);
            }
            else if (i == nums.size() - 1) {
                exceptProduct.push_back(leftProduct[leftProduct.size() - 1]);
            }
            else {
                exceptProduct.push_back(leftProduct[i - 1] * rightProduct[i]);
            }
        }

        return exceptProduct;
    }
};


// 40ms 74.97%, 10.5MB 100.00%.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> exceptProduct(nums.size(), 0);

        exceptProduct[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            exceptProduct[i] = nums[i - 1] * exceptProduct[i - 1];
        }

        int R = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            exceptProduct[i] = exceptProduct[i] * R;

            R *= nums[i];
        }

        return exceptProduct;
    }
};