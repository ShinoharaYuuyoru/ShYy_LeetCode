class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        if (s.size() == 0 && t.size() == 0) {
            return true;
        }

        bool ANS = true;

        unordered_map<char, char> mapper;
        unordered_set<char> inHash;
        for (int i = 0; i < s.size(); i++) {
            auto search = mapper.find(s[i]);
            if (search == mapper.end()) {
                auto searchIn = inHash.find(t[i]);
                if (searchIn == inHash.end()) {
                    // DO NOT EXIST
                    mapper.insert(make_pair(s[i], t[i]));
                    inHash.insert(t[i]);
                }
                else {
                    ANS = false;

                    break;
                }
            }
            else {
                if (search->second != t[i]) {
                    ANS = false;

                    break;
                }
            }
        }

        return ANS;
    }
};