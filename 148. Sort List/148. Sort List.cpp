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
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        // Get list length
        int listLength = 0;
        ListNode* ptr = head;
        while (ptr != NULL) {
            listLength++;
            ptr = ptr->next;
        }

        /*
            Use bottom-up stretegy.
            In each step
                1. We split 1, 2, 4, 8, ... nodes
                2. Merge 1+1, 2+2, 4+4, 8+8, ... nodes
                    During merging, do sorting.
        */
        ListNode dummyHead(0);      // Set a dummy head before the original head node.
        dummyHead.next = head;
        ListNode* leftSubListHead, * rightSubListHead, * mergedListTail;
        ListNode* mergePtr = head;
        int splitSize = 0;
        for (splitSize = 1, mergePtr = NULL; splitSize < listLength; splitSize = splitSize * 2) {
            mergePtr = dummyHead.next;
            mergedListTail = &dummyHead;

            while (mergePtr != NULL) {
                leftSubListHead = mergePtr;
                rightSubListHead = split(leftSubListHead, splitSize);
                mergePtr = split(rightSubListHead, splitSize);
                mergedListTail = merge(leftSubListHead, rightSubListHead, mergedListTail);
            }
        }

        return dummyHead.next;
    }

private:
    /*
        Split.
        Input:
            Split start node, split size.
        Return:
            The remained list's head.
    */
    ListNode* split(ListNode* start, int splitSize) {
        ListNode* ptr = start;
        for (int i = 1; ptr != NULL && i < splitSize; i++) {
            ptr = ptr->next;
        }

        // End of the list
        if (ptr == NULL) {
            return NULL;
        }

        ListNode* rightSubListHead = ptr->next;
        ptr->next = NULL;

        return rightSubListHead;
    }

    /*
        Merge.
        Input:
            Left sub list head, Right sub list head, Merged list tail.
                We can see &dummyHead as the "last" merged list's tail. So, at the start of each split and merging, the mergedListTail is &dummyHead.
        Return:
            The merged list tail.
    */
    ListNode* merge(ListNode* leftSubListHead, ListNode* rightSubListHead, ListNode* mergedListTail) {
        ListNode* leftSubListPtr = leftSubListHead;
        ListNode* rightSubListPtr = rightSubListHead;
        ListNode* mergedListPtr = mergedListTail;
        while (leftSubListPtr != NULL && rightSubListPtr != NULL) {
            int leftVal = leftSubListPtr->val;
            int rightVal = rightSubListPtr->val;
            if (leftVal < rightVal) {
                mergedListPtr->next = leftSubListPtr;
                mergedListPtr = mergedListPtr->next;
                leftSubListPtr = leftSubListPtr->next;
            }
            else {
                mergedListPtr->next = rightSubListPtr;
                mergedListPtr = mergedListPtr->next;
                rightSubListPtr = rightSubListPtr->next;
            }
        }

        // Connect remaining list
        if (leftSubListPtr == NULL) {
            mergedListPtr->next = rightSubListPtr;
        }
        else if (rightSubListPtr == NULL) {
            mergedListPtr->next = leftSubListPtr;
        }
        else {
            // THIS SHOULD NOT BE HAPPEND!
            cout << "MERGE ERROR!" << endl;
            exit(1);
        }
        while (mergedListPtr->next != NULL) {
            mergedListPtr = mergedListPtr->next;
        }

        return mergedListPtr;
    }
};