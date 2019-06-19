#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		unsigned int length = nums.size();

		for (int i = 0; i < length; i++)
		{
			while (nums[i] > 0 && nums[i] <= length && nums[i] != nums[nums[i] - 1])
			{
				// Swap
				int t = nums[i];
				nums[i] = nums[nums[i] - 1];
				nums[t - 1] = t;
			}

			if (nums[i] != i + 1)
			{
				nums[i] = 0;
			}
		}

		for (int i = 0; i < length; i++)
		{
			if (nums[i] == 0)
			{
				return i + 1;
			}
		}

		return length + 1;
	}
};

void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().firstMissingPositive(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}