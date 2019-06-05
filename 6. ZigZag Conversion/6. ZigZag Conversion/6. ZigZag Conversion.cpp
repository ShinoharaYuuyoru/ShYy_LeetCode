#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		string ZigZagStr = "";

		if (s.size() <= numRows || numRows == 1)
		{
			ZigZagStr = s;
		}
		else
		{
			int numRowsCount = 0;
			for (numRowsCount = 1; numRowsCount <= numRows && numRowsCount <= s.size(); numRowsCount++)
			{
				int theNum = numRowsCount - 1;
				ZigZagStr.push_back(s.at(theNum));

				int oddEven = 1;		// Odd and Even number, e.g. 1 and 2, tiktok.
				while (1)
				{
					int addNum1 = 0;
					int addNum2 = 0;

					if (oddEven == 1)
					{
						addNum1 = (numRows - numRowsCount) * 2;
						if (addNum1 == 0)
						{
							oddEven = 2;

							continue;
						}

						theNum = theNum + addNum1;

						if (theNum >= s.size())
						{
							break;
						}
						else
						{
							ZigZagStr.push_back(s.at(theNum));
						}

						oddEven = 2;
					}
					if (oddEven == 2)
					{
						addNum2 = (numRowsCount - 1) * 2;
						if (addNum2 == 0)
						{
							if (addNum1 == 0)
							{
								oddEven = 1;

								break;
							}
							else
							{
								oddEven = 1;

								continue;
							}
						}

						theNum = theNum + addNum2;

						if (theNum >= s.size())
						{
							break;
						}
						else
						{
							ZigZagStr.push_back(s.at(theNum));
						}

						oddEven = 1;
					}
				}
			}
		}

		return ZigZagStr;
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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		getline(cin, line);
		int numRows = stringToInteger(line);

		string ret = Solution().convert(s, numRows);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}