class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());
		// nums.erase(unique(nums.begin(), nums.end()), nums.end());        // This method will cause TLE too.
		// The solution is skipping the number already scanned manually.

		vector<int>::iterator itr1;
		for (itr1 = nums.begin(); itr1 != nums.end(); itr1++)
		{
			int target = 0 - *itr1;
			vector<int>::iterator itr2 = itr1 + 1;
			vector<int>::iterator itr3 = nums.end() - 1;

			while (itr2 < itr3)
			{
				int twoSum = *itr2 + *itr3;

				if (twoSum < target)
				{
					itr2++;
				}
				else if (twoSum > target)
				{
					itr3--;
				}
				else
				{
					vector<int> triplet{ *itr1, *itr2, *itr3 };
					result.push_back(triplet);

					// Skipping itr2 and itr2.
					while (itr2 < itr3 && *itr2 == triplet[1])
					{
						itr2++;
					}
					while (itr2 < itr3 && *itr3 == triplet[2])
					{
						itr3--;
					}
				}
			}

			// Skipping itr1.
			while ((itr1 + 1) < nums.end() && *(itr1 + 1) == *itr1)
			{
				itr1++;
			}
		}

		return result;
	}
};

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