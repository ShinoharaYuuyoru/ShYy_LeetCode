#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	class Solution {

	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int>::iterator itr1;
			vector<int>::iterator itr2;
			int indeces1;
			int indeces2;

			vector<int> output;

			for (itr1 = nums.begin(), indeces1 = 0; itr1 < nums.end(); itr1++, indeces1++)
			{
				for (itr2 = itr1 + 1, indeces2 = indeces1 + 1; itr2 < nums.end(); itr2++, indeces2++)
				{
					int sum = *itr1 + *itr2;

					if (sum == target)
					{
						output.push_back(indeces1);
						output.push_back(indeces2);

						break;
					}
					else
					{
						continue;
					}
				}
			}

			return output;
		}
	};

	vector<int> input;
	int target;

	int temp;
	for (int i = 0; i < 10; i++)
	{
		cin >> temp;

		input.push_back(temp);
	}
	cin >> target;

	vector<int> output;
	Solution solution;
	output = solution.twoSum(input, target);

	if (!output.empty())
	{
		vector<int>::iterator outputItr;
		for (outputItr = output.begin(); outputItr < output.end(); outputItr++)
		{
			cout << *outputItr << endl;
		}
	}
	else
	{
		cout << "No Solution!" << endl;
	}

	return 0;
}
