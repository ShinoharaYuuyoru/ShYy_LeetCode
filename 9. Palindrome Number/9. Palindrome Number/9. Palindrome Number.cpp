#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		int xCpy = x;
		string intToString;

		bool ANS;

		if (xCpy < 0)
		{
			ANS = false;

			return ANS;
		}
		else
		{
			if (xCpy == 0)
			{
				ANS = true;

				return ANS;
			}
			else
			{
				for (; xCpy > 0;)
				{
					intToString.push_back(xCpy % 10);
					xCpy = xCpy / 10;
				}

				string::iterator headItr;
				string::iterator endItr;
				for (headItr = intToString.begin(), endItr = intToString.end() - 1; headItr < endItr; headItr++, endItr--)
				{
					if (*headItr == *endItr)
					{
						continue;
					}
					else
					{
						ANS = false;

						return ANS;
					}
				}

				ANS = true;

				return ANS;
			}
		}
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		bool ret = Solution().isPalindrome(x);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}