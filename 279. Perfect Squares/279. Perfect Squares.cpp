// 1. DP
// 208ms 21.77%, 9MB 90.38%.
class Solution {
public:
    int numSquares(int n) {
        if (n == 0) {
            return 1;
        }
        else if (n < 0) {
            cout << "Input error!" << endl;

            exit(1);
        }
        else {
            vector<int> cntSquares(n + 1, INT_MAX);
            cntSquares[0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j * j <= i; j++) {
                    cntSquares[i] = min(cntSquares[i], cntSquares[i - j * j] + 1);
                }
            }

            return cntSquares.back();
        }
    }
};


// 2. Static DP
// 4ms 97.52%, 6.2MB 100.00%.
class Solution {
public:
    int numSquares(int n) {
        if (n < 0) {
            cout << "Input error!" << endl;

            exit(1);
        }
        else if (n == 0)
        {
            return 1;
        }
        else {
            static vector<int> cntSquares({ 0 });

            while (cntSquares.size() <= n) {
                int m = cntSquares.size();

                int minCnt = INT_MAX;
                for (int i = 1; i * i <= m; i++) {
                    minCnt = min(minCnt, cntSquares[m - i * i] + 1);
                }
                cntSquares.push_back(minCnt);
            }

            cout << cntSquares.back() << endl;
            cout << cntSquares[n] << endl;

            return cntSquares[n];       // Because of static, this should be cntSquares[n] in necessity!
        }
    }
};


