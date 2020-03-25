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
    bool isPalindrome(ListNode* head) {
        int listSize = 0;
        ListNode* ptr = head;
        for (; ptr != nullptr; ptr = ptr->next) {
            listSize++;
        }

        if (listSize <= 1) {
            return true;
        }
        else {
            bool flag = true;

            int halfSize = listSize / 2;
            vector<int> halfList;
            int i = 0;
            for (i = 0, ptr = head; i < halfSize; i++, ptr = ptr->next) {
                halfList.push_back(ptr->val);
            }

            if (listSize % 2 == 0) {
                i--;        // i == halfSize-1
                for (; i >= 0; i--, ptr = ptr->next) {
                    if (halfList[i] != ptr->val) {
                        flag = false;

                        break;
                    }
                }
            }
            else {
                ptr = ptr->next;
                i--;
                for (; i >= 0; i--, ptr = ptr->next) {
                    if (halfList[i] != ptr->val) {
                        flag = false;

                        break;
                    }
                }
            }

            return flag;
        }
    }
};