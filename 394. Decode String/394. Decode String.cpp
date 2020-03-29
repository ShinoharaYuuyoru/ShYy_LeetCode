class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string ANS;

        ANS = doDecoding(s, i);

        return ANS;
    }

private:
    string doDecoding(string& s, int& i) {
        string res;

        while (i < s.size() && s[i] != ']') {
            if (s[i] >= '0' && s[i] <= '9') {
                // Number to repeat
                int repeatNum = 0;
                while (i < s.size() && (s[i] >= '0' && s[i] <= '9')) {
                    repeatNum = repeatNum * 10 + (s[i] - '0');

                    i++;
                }

                i++;    // Skip '['
                string t = doDecoding(s, i);
                i++;    // Skip ']'

                while (repeatNum > 0) {
                    res = res + t;

                    repeatNum--;
                }
            }
            else {
                // Normal
                res.push_back(s[i]);

                i++;
            }
        }

        return res;
    }
};