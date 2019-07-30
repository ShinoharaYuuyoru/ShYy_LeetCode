/*
O(n3). TLE.
*/
//class Solution {
//private:
//	vector<vector<int>> outputSet;
//	set<vector<int>> solutionSet;
//
//	void SetToVec()
//	{
//		set<vector<int>>::iterator setItr;
//		for (setItr = solutionSet.begin(); setItr != solutionSet.end(); setItr++)
//		{
//			outputSet.push_back(*setItr);
//		}
//	}
//
//public:
//	vector<vector<int>> threeSum(vector<int>& nums) {
//		if (nums.size() < 3)
//		{
//			return outputSet;
//		}
//
//		sort(nums.begin(), nums.end());
//		vector<int>::iterator itr1 = nums.begin();
//		for (; itr1 != nums.end(); itr1++)
//		{
//			if (*itr1 > 0)
//			{
//				// The min number is already > 0.
//				break;
//			}
//
//			vector<int>::iterator itr2 = itr1 + 1;
//			for (; itr2 != nums.end(); itr2++)
//			{
//				int twoSum = *itr1 + *itr2;
//				if (twoSum > 0)
//				{
//					// The sum of the two numbers is already > 0.
//					break;
//				}
//
//				vector<int>::iterator itr3 = itr2 + 1;
//				for (; itr3 != nums.end(); itr3++)
//				{
//					int threeSum = twoSum + *itr3;
//					if (threeSum > 0)
//					{
//						// The sum of the three numbers is already > 0.
//						break;
//					}
//					else if (threeSum == 0)
//					{
//						vector<int> triplet = { *itr1, *itr2, *itr3 };
//						solutionSet.insert(triplet);
//					}
//				}
//			}
//		}
//
//		SetToVec();
//		return outputSet;
//	}
//
//	// Initialization
//	Solution() : outputSet(0, vector<int>(3)) {}
//};