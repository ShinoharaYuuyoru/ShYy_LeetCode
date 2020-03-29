// Map and Heap
// 24ms 39.30%, 9.4MB 100.00%.
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++) {
            mapping[nums[i]]++;
        }

        vector<pair<int, int>> heap;
        for (auto unique : mapping) {
            pair<int, int> p = make_pair(unique.first, unique.second);
            heap.push_back(p);
        }

        make_heap(heap.begin(), heap.end(), cmp);
        sort_heap(heap.begin(), heap.end(), cmp);

        vector<int> ANS;
        for (int i = 0; i < k; i++) {
            ANS.push_back(heap[i].first);
        }

        return ANS;
    }

private:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};