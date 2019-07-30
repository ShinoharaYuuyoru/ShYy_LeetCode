class Solution {
public:
	bool isMatch(string s, string p) {
		regex e(p);
		smatch m;

		return (bool)regex_match(s, m, e);
	}
};