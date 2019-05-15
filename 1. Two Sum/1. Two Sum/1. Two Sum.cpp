#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	class Solution {

	private:
		typedef struct {
			int num;
			int indices;
		}element;

		bool comp(const element &a, const element &b) {

		}

	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<element> reNums;
			int iterator = 0;
			for (iterator = 1;iterator <= nums.size();iterator++)
			{
				element tempNums;
				tempNums.num = nums[iterator];
				tempNums.indices = iterator;

				reNums.push_back(tempNums);
			}


		}
	};
}