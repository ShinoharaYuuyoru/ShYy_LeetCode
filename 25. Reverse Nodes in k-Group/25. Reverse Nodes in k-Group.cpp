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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1)
        {
            return head;
        }
        
        ListNode* reversedListHead;
        
        int listLen = 0;
        ListNode* listItr;
        for(listItr = head; listItr!=NULL;)
        {
            listLen++;
            
            listItr = listItr->next;
        }
        
        if(listLen<k)
        {
            return head;
        }

        int times = listLen/k;
        
        ListNode* nextWindowHead = head;
        ListNode* windowGenerator;
        for(int i=0; i<times; i++)
        {
            vector<ListNode*> window;
            window.clear();
            
            windowGenerator = nextWindowHead;
            for(int j = 0; j<k; j++)
            {
                window.push_back(windowGenerator);

                windowGenerator = windowGenerator->next;
            }
            nextWindowHead = windowGenerator;
            
            // Start Reverse
            vector<ListNode*>::iterator vecItrLeft = window.begin();
            vector<ListNode*>::iterator vecItrRight = window.end()-1;
            for(;vecItrLeft<vecItrRight;)
            {
                ListNode* temp;
                temp = *vecItrLeft;
                *vecItrLeft = *vecItrRight;
                *vecItrRight = temp;
                
                vecItrLeft++;
                vecItrRight--;
            }
            
            // Set new head
            if(i==0)
            {
                reversedListHead = window[0];
            }
            
            vector<ListNode*>::iterator vecFinalItr;
            for(vecFinalItr = window.begin();vecFinalItr<window.end();vecFinalItr++)
            {
                if(vecFinalItr == window.end()-1)
                {
                    // The reversed window's tail.
                    if(i==times - 1)
                    {
                        // Final. The next window doesn't exist.
                        (*vecFinalItr)->next = nextWindowHead;
                    }
                    else
                    {
                        // i < times. The next window exists.
                        ListNode* realNextWindowHead = nextWindowHead;
                        for(int t = 0; t<k-1;t++)
                        {
                            realNextWindowHead = realNextWindowHead->next;
                        }
                        
                        (*vecFinalItr)->next = realNextWindowHead;
                    }
                }
                else
                {
                    (*vecFinalItr)->next = *(vecFinalItr+1);
                }
            }
        }
        
        return reversedListHead;
    }
};