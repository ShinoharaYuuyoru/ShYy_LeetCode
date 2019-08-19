class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;

		sort(nums.begin(), nums.end());

		if (nums.size() < 4)
		{
			return result;
		}
		else
		{
			vector<int>::iterator a = nums.begin();
			for (; a < nums.end() - 3; a++)
			{
				vector<int>::iterator b = a + 1;
				for (; b < nums.end() - 2; b++)
				{
					int twoSumTarget = target - *a - *b;

					vector<int>::iterator c = b + 1;
					vector<int>::iterator d = nums.end() - 1;
					while (c < d)
					{
						int twoSum = *c + *d;
						if (twoSum < twoSumTarget)
						{
							c++;
						}
						else if (twoSum > twoSumTarget)
						{
							d--;
						}
						else
						{
							// Equal.
							vector<int> solution = { *a, *b, *c, *d };
							result.push_back(solution);

							while (c < d && *c == solution[2])
							{
								c++;
							}
							while (c < d && *d == solution[3])
							{
								d--;
							}
						}
					}

					while (b < nums.end() - 2 && *b == *(b + 1))
					{
						b++;
					}
				}

				while (a < nums.end() - 3 && *a == *(a + 1))
				{
					a++;
				}
			}
		}

		return result;
	}
};