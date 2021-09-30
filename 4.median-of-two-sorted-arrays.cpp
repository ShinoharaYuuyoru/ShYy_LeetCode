/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start

#include<vector>

using namespace std;

// O(n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ret = 0;

        int sizeSum = nums1.size() + nums2.size();
        int half = sizeSum / 2 + 1;

        vector<int> merged;
        for(int i = 0, j = 0; ; ){
            if(merged.size() == half){
                if(sizeSum % 2 == 0){
                    int lastIdx = merged.size() - 1;
                    ret = (double)(merged[lastIdx] + merged[lastIdx - 1]) / 2;
                }
                else{
                    ret = (double)(merged.back());
                }

                return ret;
            }

            if(i == nums1.size()){
                for(; ; j++){
                    if(merged.size() == half){
                        if(sizeSum % 2 == 0){
                            int lastIdx = merged.size() - 1;
                            ret = (double)(merged[lastIdx] + merged[lastIdx - 1]) / 2;
                        }
                        else{
                            ret = (double)(merged.back());
                        }

                        return ret;
                    }
                    else{
                        merged.push_back(nums2[j]);
                    }
                }

                break;
            }
            if(j == nums2.size()){
                for(; ; i++){
                    if(merged.size() == half){
                        if(sizeSum % 2 == 0){
                            int lastIdx = merged.size() - 1;
                            ret = (double)(merged[lastIdx] + merged[lastIdx - 1]) / 2;
                        }
                        else{
                            ret = (double)(merged.back());
                        }

                        return ret;
                    }
                    else{
                        merged.push_back(nums1[i]);
                    }
                }

                break;
            }

            if(nums1[i] <= nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }
            else{
                merged.push_back(nums2[j]);
                j++;
            }
        }

        return ret;
    }
};
// @lc code=end

