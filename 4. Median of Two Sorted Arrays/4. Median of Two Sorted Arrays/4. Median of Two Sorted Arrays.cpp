#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double ANS;
		vector<int> combine;

		//// Method 1: Insert.
		//combine.insert(combine.end(), nums1.begin(), nums1.end());
		//combine.insert(combine.end(), nums2.begin(), nums2.end());

		//stable_sort(combine.begin(), combine.end());

		// Method 2: Merge.
		combine.resize(nums1.size() + nums2.size());
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), combine.begin());

		int sizeSum = combine.size();
		if (sizeSum % 2 == 0)
		{
			double temp1 = combine[sizeSum / 2 - 1];
			double temp2 = combine[sizeSum / 2];
			ANS = (temp1 + temp2) / 2;
		}
		else
		{
			double temp = combine[sizeSum / 2];
			ANS = temp;
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
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);

		double ret = Solution().findMedianSortedArrays(nums1, nums2);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
