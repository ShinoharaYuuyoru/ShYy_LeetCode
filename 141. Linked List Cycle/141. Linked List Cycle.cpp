/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 1. Hashtable
 // 20ms 16.72%, 11.3MB 23.68%.
class Solution {
public:
    bool hasCycle(ListNode* head) {
        // WHERE IS pos???

        bool isCycle = false;

        set<ListNode*> hash;

        ListNode* ptr = head;
        while (true) {
            if (ptr == NULL) {
                isCycle = false;
                break;
            }
            else {
                if (hash.find(ptr) == hash.end()) {       // Not exists.
                    hash.insert(ptr);

                    ptr = ptr->next;
                }
                else {       // Exists.
                    isCycle = true;
                    break;
                }
            }
        }

        return isCycle;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 2. Two pointers: slow and fast ptrs.
 // 12ms 73.80%, 9MB 100.00%.
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        bool isCycle = false;

        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        while (true) {
            if (slowPtr == NULL || fastPtr == NULL) {
                isCycle = false;
                break;
            }
            else {
                slowPtr = slowPtr->next;
                if (fastPtr->next == NULL) {
                    isCycle = false;
                    break;
                }
                else {
                    fastPtr = fastPtr->next->next;
                }

                if (slowPtr == fastPtr) {
                    isCycle = true;
                    break;
                }
            }
        }

        return isCycle;
    }
};