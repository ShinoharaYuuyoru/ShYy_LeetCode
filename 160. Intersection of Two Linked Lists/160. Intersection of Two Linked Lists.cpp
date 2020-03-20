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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* APtr = headA;
        ListNode* BPtr = headB;
        ListNode* intersectPoint = NULL;
        /*
            If APtr reaches the end, redirect to headB;
            If BPtr reaches the end, redirect to headA.
            Then check to the end:
                If at a point that APtr == BPtr, that's the point.
                If APtr or BPtr or both ends NULL, return NULL.
        */
        bool breakFlagA = false;
        bool breakFlagB = false;
        while (true) {
            if (APtr == NULL) {
                // APtr redirect to headB
                breakFlagA = true;
                APtr = headB;
            }

            if (BPtr == NULL) {
                // BPtr redirect to headA
                breakFlagB = true;
                BPtr = headA;
            }

            if (breakFlagA == true && breakFlagB == true) {
                // Exit
                break;
            }
            else {
                // Continue
                APtr = APtr->next;
                BPtr = BPtr->next;
            }
        }

        while (true) {
            if (APtr == NULL) {
                if (BPtr == NULL) {
                    // No intersection
                    intersectPoint = NULL;

                    break;
                }
                else {
                    cout << "CRITICAL ERROR!" << endl;

                    exit(1);
                }
            }
            else {
                if (BPtr == NULL) {
                    cout << "CRITICAL ERROR!" << endl;

                    exit(1);
                }
                else {
                    if (APtr == BPtr) {
                        // Intersection
                        intersectPoint = APtr;

                        break;
                    }
                    else {
                        // Continue searching
                        APtr = APtr->next;
                        BPtr = BPtr->next;
                    }
                }
            }
        }

        return intersectPoint;
    }
};