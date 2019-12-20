class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ANS;

		set<vector<int>> keyList;
		multimap<vector<int>, string> keyTable;

		for (int strsItr = 0; strsItr < strs.size(); strsItr++) {
			vector<int> key = keyGenerator(strs[strsItr]);
			keyList.insert(key);
			keyTable.insert({ key, strs[strsItr] });
		}

		for (auto keyItr : keyList) {
			vector<string> stringList;
			auto valueRange = keyTable.equal_range(keyItr);
			for (auto valueItr = valueRange.first; valueItr != valueRange.second; valueItr++) {
				stringList.push_back(valueItr->second);
			}
			ANS.push_back(stringList);
		}

		return ANS;
	}

private:
	vector<int> keyGenerator(string str) {
		vector<int> key(26);

		for (int strItr = 0; strItr < str.size(); strItr++) {
			key[str[strItr] - 'a'] += 1;
		}

		return key;
	}
};