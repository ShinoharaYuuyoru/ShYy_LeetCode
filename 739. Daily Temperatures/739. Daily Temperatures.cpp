// 1. Brute force
// TLE
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ANS;

        for (int i = 0; i < T.size(); i++) {
            int j = i + 1;
            for (; j < T.size(); j++) {
                if (T[j] > T[i]) {
                    ANS.push_back(j - i);

                    break;
                }
            }
            if (j == T.size()) {
                ANS.push_back(0);
            }
        }

        return ANS;
    }
};


// 2. Stack
// 200ms 50.18%, 13.8MB 100.00%.
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> ANS(T.size());
        stack<int> s;

        for (int i = 0; i < T.size(); i++) {
            while (s.empty() == false && T[i] > T[s.top()]) {
                int index = s.top();
                s.pop();
                ANS[index] = i - index;
            }

            s.push(i);
        }

        return ANS;
    }
};