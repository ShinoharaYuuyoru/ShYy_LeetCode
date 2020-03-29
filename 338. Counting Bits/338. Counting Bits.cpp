// 1. My solution
// 60ms 15.94%, 7.8MB 100.00%.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ANS;
        for (int i = 0; i <= num; i++) {
            int nowNum = i;
            int nowCnt = 0;
            while (true) {
                if (nowNum == 0) {
                    ANS.push_back(nowCnt);

                    break;
                }
                else {
                    if (nowNum % 2 == 1) {
                        nowCnt++;
                    }

                    nowNum = nowNum >> 1;
                }
            }
        }

        return ANS;
    }
};


// 2. DP
// https://leetcode.com/problems/counting-bits/discuss/79539/Three-Line-Java-Solution
// 48ms 98.54%, 7.2MB 100.00%.
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ANS(num + 1);
        for (int i = 1; i <= num; i++) {
            ANS[i] = ANS[i >> 1] + (i & 1);
        }

        return ANS;
    }
};