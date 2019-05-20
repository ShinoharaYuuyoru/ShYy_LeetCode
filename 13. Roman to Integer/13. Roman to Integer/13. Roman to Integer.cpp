#include <iostream>
#include <string>
#include <cassert>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int ANS;

		ANS = 0;

		string::iterator itr;
		for (itr = s.begin(); itr < s.end();)
		{
			if (*itr == 'M')
			{
				ANS = ANS + 1000;
				itr++;
				continue;
			}
			if (*itr == 'D')
			{
				ANS = ANS + 500;
				itr++;
				continue;
			}
			if (*itr == 'C')
			{
				if (itr < s.end() - 1)
				{
					if (*(itr + 1) == 'M')
					{
						ANS = ANS + 900;
						itr = itr + 2;
						continue;
					}
					if (*(itr + 1) == 'D')
					{
						ANS = ANS + 400;
						itr = itr + 2;
						continue;
					}
				}

				ANS = ANS + 100;
				itr++;
				continue;
			}
			if (*itr == 'L')
			{
				ANS = ANS + 50;
				itr++;
				continue;
			}
			if (*itr == 'X')
			{
				if (itr < s.end() - 1)
				{
					if (*(itr + 1) == 'C')
					{
						ANS = ANS + 90;
						itr = itr + 2;
						continue;
					}
					if (*(itr + 1) == 'L')
					{
						ANS = ANS + 40;
						itr = itr + 2;
						continue;
					}
				}

				ANS = ANS + 10;
				itr++;
				continue;
			}
			if (*itr == 'V')
			{
				ANS = ANS + 5;
				itr++;
				continue;
			}
			if (*itr == 'I')
			{
				if (itr < s.end() - 1)
				{
					if (*(itr + 1) == 'X')
					{
						ANS = ANS + 9;
						itr = itr + 2;
						continue;
					}
					if (*(itr + 1) == 'V')
					{
						ANS = ANS + 4;
						itr = itr + 2;
						continue;
					}
				}

				ANS = ANS + 1;
				itr++;
				continue;
			}
		}

		return ANS;
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

		int ret = Solution().romanToInt(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}