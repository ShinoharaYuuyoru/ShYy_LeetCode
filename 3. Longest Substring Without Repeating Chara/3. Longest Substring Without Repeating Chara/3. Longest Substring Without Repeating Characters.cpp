/*
* TITLE: 3. Longest Substring Without Repeating Characters
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> subStrMap;
		int mapValue;
		int maxSubStrLength;
		string::iterator itr1;
		string::iterator itr2;

		mapValue = 1;
		maxSubStrLength = 0;
		for (itr1 = s.begin(); itr1 < s.end(); itr1++)
		{
			char headChara = *itr1;
			subStrMap[headChara] = mapValue;
			mapValue++;

			for (itr2 = itr1 + 1; itr2 < s.end(); itr2++)
			{
				char nextChara = *itr2;

				if (subStrMap[nextChara] == 0)
				{
					// Add.
					subStrMap[nextChara] = mapValue;
					mapValue++;
				}
				else
				{
					// Exist.
					break;
				}
			}

			if ((mapValue - 1) > maxSubStrLength)
			{
				maxSubStrLength = mapValue - 1;
			}

			subStrMap.clear();
			mapValue = 1;
		}

		return maxSubStrLength;
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

		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}