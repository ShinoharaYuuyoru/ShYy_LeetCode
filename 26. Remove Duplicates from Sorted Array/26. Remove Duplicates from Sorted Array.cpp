class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty() == true){
            return 0;
        }
        else{
            int preNum = nums[0];
            
            for(auto numptr = nums.begin()+1; numptr < nums.end();){
                int num = *numptr;
                if(num == preNum){
                    numptr = nums.erase(numptr);
                }
                else{
                    preNum = num;
                    numptr++;
                }
            }
            
            return nums.size();
        }
    }
};