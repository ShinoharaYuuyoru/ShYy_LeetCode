#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		vector<int>::iterator itr1;
		vector<int>::iterator itr2;

		int ANS = 0;
		for (itr1 = height.begin(), itr2 = height.end() - 1; itr1 < itr2;)
		{
			int tempArea = (itr2 - itr1) * ((*itr1 > * itr2) ? *itr2 : *itr1);
			if (tempArea > ANS)
			{
				ANS = tempArea;
			}

			if (*itr1 > * itr2)
			{
				itr2--;
			}
			else
			{
				itr1++;
			}
		}

		return ANS;
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
		vector<int> height = stringToIntegerVector(line);

		int ret = Solution().maxArea(height);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}