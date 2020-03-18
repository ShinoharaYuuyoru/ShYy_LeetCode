// My solution.
// 208ms 11.63%, 36.6MB 100.00%.
class LRUCache {
public:
    LRUCache(int capacity) {
        myLRUCapacity = capacity;
    }

    int get(int key) {
        auto search = myLRU.find(key);
        if (search != myLRU.end()) {
            // Exist
            // Update queue
            auto queueSearch = find(myLRUQueue.begin(), myLRUQueue.end(), key);
            queueSearch = myLRUQueue.erase(queueSearch);
            myLRUQueue.push_back(key);

            return myLRU[key];
        }
        else {
            return -1;
        }
    }

    void put(int key, int value) {
        auto search = myLRU.find(key);
        if (search != myLRU.end()) {
            // Exist
            // LRU update
            myLRU[key] = value;
            // Queue update
            auto queueSearch = find(myLRUQueue.begin(), myLRUQueue.end(), key);
            queueSearch = myLRUQueue.erase(queueSearch);
            myLRUQueue.push_back(key);
        }
        else {
            // Does not exist.
            if (myLRU.size() < myLRUCapacity) {
                // LRU free.
                myLRU[key] = value;
                myLRUQueue.push_back(key);
            }
            else {
                // LRU full.
                int popFirstKey = myLRUQueue[0];
                auto queueErased = myLRUQueue.erase(myLRUQueue.begin());
                auto LRUErased = myLRU.erase(popFirstKey);

                // Insert
                myLRUQueue.push_back(key);
                myLRU[key] = value;
            }
        }

    }

private:
    unordered_map<int, int> myLRU;
    vector<int> myLRUQueue;
    int myLRUCapacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */