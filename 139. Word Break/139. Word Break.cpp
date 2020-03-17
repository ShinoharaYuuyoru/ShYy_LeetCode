class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;       // Start point

        /*
            If dp[j] == true
                Set dp[i] = true, if s.substr[j, i) is existing in the dictionary.
            Finally, dp[s.size()] is the ANS.
            Note that the dp's position is 1 bigger than s's posision. e.g. dp[1] == true -> s[~0] is a breakable word.
        */
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == true) {
                    string word = s.substr(j, i - j);     // s[j, i)
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {      // isExist
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }
};