/*
***** NOTICE *****
From this time, we will not upload the whole VS project, neither we will not use any IDE to finish the problem.

We will just upload the segment of code where we can finish it on LeetCode browser coding platform.

That is, you can just paste the code on the platform and see the result :)
*****
*/


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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* finalList = new ListNode(0);

		vector<int> merged;

		vector<ListNode*>::iterator itr;
		for (itr = lists.begin(); itr < lists.end(); itr++)
		{
			ListNode* head;
			head = *itr;

			ListNode* listItr = head;
			for (; listItr != NULL;)
			{
				merged.push_back(listItr->val);
				listItr = listItr->next;
			}
		}

		stable_sort(merged.begin(), merged.end());

		ListNode* finalListGenerator = finalList;
		vector<int>::iterator mergedItr;
		for (mergedItr = merged.begin(); mergedItr < merged.end(); mergedItr++)
		{
			finalListGenerator->next = new ListNode(*mergedItr);

			finalListGenerator = finalListGenerator->next;
		}

		return finalList->next;
	}
};


// O(kn), 792ms 6.12%, 12.6MB 5.95%.
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* merged = nullptr;
        ListNode* mergedPtr = nullptr;

        vector<ListNode*> ptrLists = lists;

        while (true) {
            bool endFlag = true;
            int minVal = INT_MAX;
            int minPos = 0;
            for (int i = 0; i < ptrLists.size(); i++) {
                if (ptrLists[i] == nullptr) {
                    endFlag = endFlag & true;
                }
                else {
                    endFlag = false;

                    if (ptrLists[i]->val < minVal) {
                        minVal = ptrLists[i]->val;
                        minPos = i;
                    }
                }
            }

            // End
            if (endFlag == true) {
                break;
            }
            else {
                ListNode* newNode = new ListNode(minVal);
                if (merged == nullptr) {
                    merged = newNode;
                    mergedPtr = merged;
                }
                else {
                    mergedPtr->next = newNode;
                    mergedPtr = mergedPtr->next;
                }

                ptrLists[minPos] = ptrLists[minPos]->next;
            }
        }

        return merged;
    }
};