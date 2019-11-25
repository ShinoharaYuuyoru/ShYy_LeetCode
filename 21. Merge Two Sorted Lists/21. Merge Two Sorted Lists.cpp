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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l1Ptr = l1;
		ListNode* l2Ptr = l2;
		ListNode* merged = NULL;
		ListNode* mergedPtr = merged;

		// Any list is empty.
		if (l1Ptr == NULL) {
			return l2;
		}
		if (l2Ptr == NULL) {
			return l1;
		}

		// Valid lists. Start merging.
		for (; l1Ptr != NULL && l2Ptr != NULL;) {
			int l1Val = l1Ptr->val;
			int l2Val = l2Ptr->val;
			if (l1Val <= l2Val) {
				// Pushback l1Val
				if (merged == NULL) {
					// Create merged.
					mergedPtr = new ListNode(l1Val);
					merged = mergedPtr;
				}
				else {
					mergedPtr->next = new ListNode(l1Val);
					mergedPtr = mergedPtr->next;
				}

				l1Ptr = l1Ptr->next;
			}
			else {
				// Pushback l2Val
				if (merged == NULL) {
					// Create merged.
					mergedPtr = new ListNode(l2Val);
					merged = mergedPtr;
				}
				else {
					mergedPtr->next = new ListNode(l2Val);
					mergedPtr = mergedPtr->next;
				}

				l2Ptr = l2Ptr->next;
			}
		}

		// End of merging and any list remained. Concatenate merged with it.
		if (l1Ptr == NULL && l2Ptr != NULL) {
			// l2 remained.
			while (l2Ptr != NULL) {
				int l2Val = l2Ptr->val;
				mergedPtr->next = new ListNode(l2Val);
				mergedPtr = mergedPtr->next;

				l2Ptr = l2Ptr->next;
			}
		}
		else {       // This should just be (l1Ptr != NULL && l2Ptr == NULL)
			// l1 remained.
			while (l1Ptr != NULL) {
				int l1Val = l1Ptr->val;
				mergedPtr->next = new ListNode(l1Val);
				mergedPtr = mergedPtr->next;

				l1Ptr = l1Ptr->next;
			}
		}

		return merged;
	}
};