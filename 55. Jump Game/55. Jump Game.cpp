class Solution {
public:
	//     // Violence
	//     bool canJump(vector<int>& nums) {
	//         int size = nums.size();
	//         vector<int> getHere(size);

	//         getHere[0] = 1;

	//         int globalItr = 0;
	//         for(globalItr = 0; globalItr < size; globalItr++)
	//         {
	//             if(getHere[globalItr] == 1)
	//             {
	//                 int maxStep = nums[globalItr];
	//                 int step = 0;
	//                 for(step = 1; step <= maxStep && ((globalItr + step) < size); step++)
	//                 {
	//                     getHere[globalItr + step] = 1;
	//                 }
	//             }
	//         }

	//         if(getHere[size - 1] == 1)
	//         {
	//             return true;
	//         }
	//         else
	//         {
	//             return false;
	//         }
	//     }

	//     // DP
	//     bool canJump(vector<int>& nums) {
	//         int size = nums.size();

	//         vector<int> dp(size, 0);

	//         int itr = 0;
	//         for(itr = 1; itr < size; itr++)
	//         {
	//             dp[itr] = max(dp[itr - 1], nums[itr - 1]) - 1;

	//             if(dp[itr] < 0)
	//             {
	//                 return false;
	//             }
	//         }

	//         return true;
	//     }

		// Greedy
	bool canJump(vector<int>& nums) {
		int lastPos = nums.size() - 1;

		for (int nowPos = lastPos; nowPos >= 0; nowPos--)
		{
			if (nowPos + nums[nowPos] >= lastPos)
			{
				lastPos = nowPos;
			}
		}

		if (lastPos == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};