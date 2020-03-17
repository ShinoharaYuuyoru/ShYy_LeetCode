/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
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

        /*
            To understand this solution, you just need to ask yourself these question.
            Assume the distance from head to the start of the loop is x1
            the distance from the start of the loop to the point fast and slow meet is x2
            the distance from the point fast and slow meet to the start of the loop is x3
            1. What is the distance fast moved?
            2. What is the distance slow moved?
            3. And their relationship?
            ANS:
                x1 + x2 + x3 + x2
                x1 + x2
                x1 + x2 + x3 + x2 = 2 (x1 + x2)
            Thus x1 = x3
        */
        // So, we set searchStartPtr starts from head, the slowPtr starts from the first meeting point.
        if (isCycle == false) {
            return NULL;
        }
        else {
            ListNode* searchStartPtr = head;
            while (true) {
                if (searchStartPtr != slowPtr) {
                    searchStartPtr = searchStartPtr->next;
                    slowPtr = slowPtr->next;
                }
                else {
                    break;
                }
            }

            return searchStartPtr;
        }
    }
};