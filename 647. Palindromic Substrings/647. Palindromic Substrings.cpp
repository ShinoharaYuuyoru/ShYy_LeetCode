class Solution {
public:
    int countSubstrings(string s) {
        int N = s.size();
        int ANS = 0;

        for (int center = 0; center <= 2 * N - 1; center++) {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < N && s[left] == s[right]) {
                ANS++;

                left--;
                right++;
            }
        }

        return ANS;
    }
};