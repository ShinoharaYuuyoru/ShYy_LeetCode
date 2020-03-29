class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> queued;
        if (people.size() == 0) {
            return queued;
        }

        sort(people.begin(), people.end(), cmp);

        int ptr = 0;
        while (ptr < people.size()) {
            vector<int> one = people[ptr];
            int count = one[1];
            auto insertPos = queued.begin();
            for (int i = 0; i < count; i++) {
                insertPos++;
            }
            queued.insert(insertPos, one);

            ptr++;
        }

        return queued;
    }

private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] > b[0]) {
            return true;
        }
        else if (a[0] == b[0]) {
            if (a[1] >= b[1]) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }
};