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
 // 8ms 97.13%, 9.2MB 100.00%.
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }

        bool isCycle = false;

        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
        while (true) {
            if (slowPtr == NULL || fastPtr == NULL) {
                isCycle = false;
                break;
            }
            else {
                if (slowPtr != fastPtr) {
                    slowPtr = slowPtr->next;        // slowPtr step 1 forward.
                    if (fastPtr->next != NULL) {
                        fastPtr = fastPtr->next->next;      // fastPtr step 2 forward.
                    }
                    else {
                        isCycle = false;
                        break;
                    }
                }
                else {
                    isCycle = true;
                    break;
                }
            }
        }

        return isCycle;
    }
};