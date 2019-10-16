class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2){
            return;
        }
        else{
            int numAptr = -1;
            for(int num1ptr = nums.size()-2; num1ptr>=0; num1ptr--){
                int num2ptr = num1ptr+1;
                
                if(nums[num1ptr] < nums[num2ptr]){
                    numAptr = num1ptr;
                    break;
                }
            }
            if(numAptr == -1){
                // Reverse the array end return.
				reverseArray(nums, 0, nums.size()-1);
                
                return;
            }
            else{
                int numBptr = -1;
                for(int numptr = nums.size()-1; numptr >= 0; numptr--){
                    if(nums[numptr] > nums[numAptr]){
                        numBptr = numptr;
                        break;
                    }
                }
                // The numBptr must have a value and it will bigger than numAptr.

                // Swap
                int tempNum=nums[numAptr];
                nums[numAptr] = nums[numBptr];
                nums[numBptr] = tempNum;

                // Reverse the array after numAptr.
                reverseArray(nums, numAptr+1, nums.size()-1);
            }
        }
    }
    
    void reverseArray(vector<int>& nums, int startPtr, int endPtr){
		while(startPtr < endPtr){
			int tempNum = nums[startPtr];
			nums[startPtr] = nums[endPtr];
			nums[endPtr] = tempNum;
            
            startPtr++;
            endPtr--;
		}
		
		return;
	}
};