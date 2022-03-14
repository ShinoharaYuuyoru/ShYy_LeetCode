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
