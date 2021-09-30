/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
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


// // O(n)
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

