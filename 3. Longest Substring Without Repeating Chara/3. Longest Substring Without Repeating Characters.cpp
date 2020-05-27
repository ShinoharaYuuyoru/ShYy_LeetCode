// 1. Brute force
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


// 2. Hash O(n)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1) {
			return s.size();
		}

		int ANS = 0;

		unordered_set<char> hash;

		hash.insert(s[0]);

		int prePtr = 0;
		int nextPtr = 1;
		while (prePtr < s.size() && nextPtr < s.size()) {
			auto search = hash.find(s[nextPtr]);
			if (search != hash.end()) {
				// Exist.
				hash.erase(s[prePtr]);

				prePtr++;
			}
			else {
				hash.insert(s[nextPtr]);

				nextPtr++;
			}

			// Update
			if (hash.size() > ANS) {
				ANS = hash.size();
			}
		}

		return ANS;
	}
};