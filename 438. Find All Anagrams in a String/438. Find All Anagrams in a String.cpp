// Sliding window
// https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92027/C%2B%2B-O(n)-sliding-window-concise-solution-with-explanation
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(26, 0), sv(26, 0);
        vector<int> ANS;

        if (s.size() < p.size()) {
            return ANS;
        }

        for (int i = 0; i < p.size(); i++) {
            pv[p[i] - 'a']++;
            sv[s[i] - 'a']++;
        }
        if (pv == sv) {
            ANS.push_back(0);
        }

        // Start sliding
        for (int i = p.size(); i < s.size(); i++) {
            sv[s[i] - 'a']++;
            sv[s[i - p.size()] - 'a']--;

            if (pv == sv) {
                ANS.push_back(i - p.size() + 1);
            }
        }

        return ANS;
    }
};