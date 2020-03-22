/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 1. Iteratively
 // 12ms 40.51%, 8MB 100.00%.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* geneLastPtr = NULL;
        ListNode* oriPtr = head;
        while (true) {
            if (oriPtr == NULL) {
                break;
            }
            else {
                int oriVal = oriPtr->val;

                ListNode* generator = new ListNode(oriVal);
                if (geneLastPtr == NULL) {
                    // First node.
                    generator->next = NULL;
                    geneLastPtr = generator;
                }
                else {
                    generator->next = geneLastPtr;
                    geneLastPtr = generator;
                }

                oriPtr = oriPtr->next;
            }
        }

        return geneLastPtr;
    }
};


// 2. Recursively
// 8ms 94.31%, 7.7MB 100.00%.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        generator(newHead, head);

        return newHead;
    }

private:
    void generator(ListNode*& geneLastNode, ListNode* nowOriNode) {
        if (nowOriNode == NULL) {
            return;
        }
        else {
            int nowVal = nowOriNode->val;
            ListNode* newNode = new ListNode(nowVal);
            newNode->next = geneLastNode;
            geneLastNode = newNode;

            generator(geneLastNode, nowOriNode->next);

            return;
        }
    }
};