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
        for(itr = lists.begin();itr<lists.end();itr++)
        {
            ListNode* head;
            head = *itr;
            
            ListNode* listItr = head;
            for(;listItr!=NULL;)
            {
                merged.push_back(listItr->val);
                listItr = listItr->next;
            }
        }
        
        stable_sort(merged.begin(), merged.end());
        
        ListNode* finalListGenerator = finalList;
        vector<int>::iterator mergedItr;
        for(mergedItr = merged.begin(); mergedItr<merged.end();mergedItr++)
        {
            finalListGenerator->next = new ListNode(*mergedItr);
            
            finalListGenerator = finalListGenerator->next;
        }
        
        return finalList->next;
    }
};