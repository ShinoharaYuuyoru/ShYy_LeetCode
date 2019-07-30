class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int closestSum = target;
		int distance = INT_MAX;

		sort(nums.begin(), nums.end());

		vector<int>::iterator itr1;
		for (itr1 = nums.begin(); itr1 != nums.end(); itr1++)
		{
			vector<int>::iterator itr2 = itr1 + 1;
			vector<int>::iterator itr3 = nums.end() - 1;
			while (itr2 < itr3)
			{
				int threeSum = *itr1 + *itr2 + *itr3;
				if (abs(target - threeSum) < distance)
				{
					distance = abs(target - threeSum);
					closestSum = threeSum;
				}

				if (threeSum < target)
				{
					itr2++;
				}
				else if (threeSum > target)
				{
					itr3--;
				}
				else
				{
					distance = abs(target - threeSum);
					closestSum = threeSum;
					return closestSum;
				}
			}
		}

		return closestSum;
	}
};

/*
O(n3) bad solution.
*/
//class Solution {
//public:
//	int threeSumClosest(vector<int>& nums, int target) {
//		int closestSum = target;
//		int distance = INT_MAX;
//
//		sort(nums.begin(), nums.end());
//
//		vector<int>::iterator itr1;
//		for (itr1 = nums.begin(); itr1 != nums.end(); itr1++)
//		{
//			vector<int>::iterator itr2;
//			for (itr2 = itr1 + 1; itr2 != nums.end(); itr2++)
//			{
//				vector<int>::iterator itr3;
//				for (itr3 = itr2 + 1; itr3 != nums.end(); itr3++)
//				{
//					int threeSum = *itr1 + *itr2 + *itr3;
//					if (abs(target - threeSum) < distance)
//					{
//						distance = abs(target - threeSum);
//						closestSum = threeSum;
//					}
//				}
//			}
//		}
//
//		return closestSum;
//	}
//};