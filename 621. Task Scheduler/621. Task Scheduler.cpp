class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26);

        for (auto c : tasks) {
            map[c - 'A']++;
        }
        sort(map.begin(), map.end(), greater<int>());

        int time = 0;
        while (map[0] > 0) {
            int i = 0;
            while (i <= n) {
                if (map[0] == 0) {
                    break;
                }

                if (i < 26 && map[i] > 0) {
                    map[i]--;
                }

                time++;
                i++;
            }

            sort(map.begin(), map.end(), greater<int>());
        }

        return time;
    }
};