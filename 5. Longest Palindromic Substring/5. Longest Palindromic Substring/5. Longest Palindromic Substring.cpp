#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
private:
	int maxSubStrLength = 1;
	int maxSubStrLeftItr = 0;
	int maxSubStrRightItr = 0;

	string maxSubStr;

public:
	string longestPalindrome(string s) {

		countOddSubStr(s);
		countEvenSubStr(s);

		maxSubStr = s.substr(maxSubStrLeftItr, maxSubStrLength);

		return maxSubStr;
	}

	void countOddSubStr(string s)
	{
		int sItr;
		for (sItr = 0; sItr < s.size(); sItr++)
		{
			int subStrLength = 0;
			int leftItr = sItr;
			int rightItr = sItr;
			for (leftItr = sItr, rightItr = sItr; leftItr >= 0 && rightItr < s.size(); leftItr--, rightItr++)
			{
				if (leftItr == sItr && rightItr == sItr)
				{
					subStrLength = 1;

					continue;
				}

				if (s.at(leftItr) == s.at(rightItr))
				{
					subStrLength = subStrLength + 2;

					if (subStrLength > maxSubStrLength)
					{
						maxSubStrLength = subStrLength;
						maxSubStrLeftItr = leftItr;
						maxSubStrRightItr = rightItr;
					}

					continue;
				}
				else
				{
					break;
				}
			}
		}
	}

	void countEvenSubStr(string s)
	{
		int firstItr, secondItr;
		for (firstItr = 0, secondItr = firstItr + 1; firstItr < s.size() - 1, secondItr < s.size(); firstItr++, secondItr++)
		{
			if (s.at(firstItr) == s.at(secondItr))
			{
				int subStrLength = 0;
				int leftItr = firstItr;
				int rightItr = secondItr;
				for (leftItr = firstItr, rightItr = secondItr; leftItr >= 0 && rightItr < s.size(); leftItr--, rightItr++)
				{
					if (s.at(leftItr) == s.at(rightItr))
					{
						subStrLength = subStrLength + 2;
						
						if (subStrLength > maxSubStrLength)
						{
							maxSubStrLength = subStrLength;
							maxSubStrLeftItr = leftItr;
							maxSubStrRightItr = rightItr;
						}

						continue;
					}
					else
					{
						break;
					}
				}
			}
		}
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);

		string ret = Solution().longestPalindrome(s);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}