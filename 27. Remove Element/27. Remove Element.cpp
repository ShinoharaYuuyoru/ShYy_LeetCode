class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()==true){
            return 0;
        }
        else{
            for(auto numptr = nums.begin(); numptr < nums.end();){
                if(*numptr == val){
                    numptr = nums.erase(numptr);
                }
                else{
                    numptr++;
                }
            }
            
            return nums.size();
        }
    }
};