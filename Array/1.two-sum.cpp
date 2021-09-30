/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (47.66%)
 * Likes:    24875
 * Dislikes: 819
 * Total Accepted:    5M
 * Total Submissions: 10.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 * 
 * 
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// O(n2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ret;

//         for(int i = 0; i < nums.size(); i++){
//             for(int j = i + 1; j < nums.size(); j++){
//                 if(nums[i] + nums[j] == target){
//                     ret.push_back(i);
//                     ret.push_back(j);

//                     return ret;
//                 }
//             }
//         }

//         return ret;
//     }
// };


// O(nlogn)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         vector<int> ret;

//         vector<pair<int, int> > newNums;
//         for(int i = 0; i < nums.size(); i++){
//             newNums.push_back(make_pair(nums[i], i));
//         }

//         stable_sort(newNums.begin(), newNums.end(), comp);

//         for(int i = 0, j = newNums.size() - 1; i < j;){
//             int sum = newNums[i].first + newNums[j].first;
//             if(sum < target){
//                 i++;
//             }
//             else if(sum == target){
//                 ret.push_back(newNums[i].second);
//                 ret.push_back(newNums[j].second);

//                 return ret;
//             }
//             else{
//                 j--;
//             }
//         }

//         return ret;
//     }

// private:
//     static bool comp(const pair<int, int> &a1, const pair<int, int> &a2){
//         if(a1.first < a2.first){
//             return true;
//         }
//         else{
//             return false;
//         }
//     }
// };


// Best solution
// O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> MAP;

        for(int i = 0; i < nums.size(); i++){
            int num1 = nums[i];
            int num2 = target - num1;

            if(MAP.find(num2) != MAP.end()){
                ret.push_back(i);
                ret.push_back(MAP[num2]);

                return ret;
            }
            else{
                MAP[num1] = i;
            }
        }

        return ret;
    }
};
// @lc code=end

