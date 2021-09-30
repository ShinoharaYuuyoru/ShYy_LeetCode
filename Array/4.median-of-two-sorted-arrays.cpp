/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (32.74%)
 * Likes:    12602
 * Dislikes: 1708
 * Total Accepted:    1.1M
 * Total Submissions: 3.3M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return
 * the median of the two sorted arrays.
 * 
 * The overall run time complexity should be O(log (m+n)).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,3], nums2 = [2]
 * Output: 2.00000
 * Explanation: merged array = [1,2,3] and median is 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3,4]
 * Output: 2.50000
 * Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [0,0], nums2 = [0,0]
 * Output: 0.00000
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: nums1 = [], nums2 = [1]
 * Output: 1.00000
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: nums1 = [2], nums2 = []
 * Output: 2.00000
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * 1 <= m + n <= 2000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 * 
 * 
 */

// @lc code=start

#include <vector>
#include <climits>

using namespace std;


// My solution
// O((m+n)/2)
// 28ms 78.08%
// 89.8MB 23.86%
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         double ret = 0;

//         int sizeSum = nums1.size() + nums2.size();
//         int half = sizeSum / 2 + 1;

//         vector<int> merged;
//         for(int i = 0, j = 0; ; ){
//             if(merged.size() == half){
//                 if(sizeSum % 2 == 0){
//                     int lastIdx = merged.size() - 1;
//                     ret = (double)(merged[lastIdx] + merged[lastIdx - 1]) / 2;
//                 }
//                 else{
//                     ret = (double)(merged.back());
//                 }

//                 return ret;
//             }

//             if(i == nums1.size()){
//                 for(; ; j++){
//                     if(merged.size() == half){
//                         if(sizeSum % 2 == 0){
//                             int lastIdx = merged.size() - 1;
//                             ret = (double)(merged[lastIdx] + merged[lastIdx - 1]) / 2;
//                         }
//                         else{
//                             ret = (double)(merged.back());
//                         }

//                         return ret;
//                     }
//                     else{
//                         merged.push_back(nums2[j]);
//                     }
//                 }

//                 break;
//             }
//             if(j == nums2.size()){
//                 for(; ; i++){
//                     if(merged.size() == half){
//                         if(sizeSum % 2 == 0){
//                             int lastIdx = merged.size() - 1;
//                             ret = (double)(merged[lastIdx] + merged[lastIdx - 1]) / 2;
//                         }
//                         else{
//                             ret = (double)(merged.back());
//                         }

//                         return ret;
//                     }
//                     else{
//                         merged.push_back(nums1[i]);
//                     }
//                 }

//                 break;
//             }

//             if(nums1[i] <= nums2[j]){
//                 merged.push_back(nums1[i]);
//                 i++;
//             }
//             else{
//                 merged.push_back(nums2[j]);
//                 j++;
//             }
//         }

//         return ret;
//     }
// };


// Best solution
// O(log(min(m+n)))
// 32ms 64.73%
// 89.3MB 85.87%
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // length of nums1 < nums2.
        if(nums1.size() > nums2.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int n1Size = nums1.size();
        int n2Size = nums2.size();

        int low = 0;
        int high = n1Size;
        while(low <= high){
            int partitionX = (low + high) / 2;
            int partitionY = (n1Size + n2Size + 1) / 2 - partitionX;

            int maxN1Left = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
            int minN1Right = (partitionX == n1Size) ? INT_MAX : nums1[partitionX];

            int maxN2Left = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
            int minN2Right = (partitionY == n2Size) ? INT_MAX : nums2[partitionY];

            if(maxN1Left <= minN2Right && maxN2Left <= minN1Right){
                if((n1Size + n2Size) % 2 == 0){
                    return (double)(max(maxN1Left, maxN2Left) + min(minN1Right, minN2Right)) / 2;
                }
                else{
                    return (double)(max(maxN1Left, maxN2Left));
                }
            }
            else if(maxN1Left > minN2Right){
                // Too much in the left of nums1
                high = partitionX - 1;
            }
            else{
                // Too much in the right of nums1
                low = partitionX + 1;
            }
        }

        return -1;      // Impossible
    }
};

// @lc code=end

