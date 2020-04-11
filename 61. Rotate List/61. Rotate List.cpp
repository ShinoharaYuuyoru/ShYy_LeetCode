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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        int listSize = 0;
        for (ListNode* i = head; i != nullptr; i = i->next) {
            listSize++;
        }

        int moveSize = listSize - (k % listSize);

        ListNode* tail = head;
        for (; tail->next != nullptr; tail = tail->next);

        ListNode* newHead = head;
        for (int i = 0; i < moveSize; i++) {
            ListNode* newNode = new ListNode(newHead->val);

            tail->next = newNode;
            tail = newNode;

            ListNode* temp = newHead->next;
            delete(newHead);
            newHead = temp;
        }

        return newHead;
    }
};