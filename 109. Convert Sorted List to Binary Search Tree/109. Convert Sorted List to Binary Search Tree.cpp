/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  * };
  */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int size = findSize(head);

        iterator = head;

        return convertListToBST(0, size - 1);
    }

private:
    ListNode* iterator;

    int findSize(ListNode* head) {
        ListNode* ptr = head;
        int c = 0;
        while (ptr != nullptr) {
            ptr = ptr->next;
            c++;
        }

        return c;
    }

    TreeNode* convertListToBST(int l, int r) {
        if (l > r) {
            return nullptr;
        }

        int mid = (l + r) / 2;

        // First step of simulated inorder traversal. Recursively form the left half
        TreeNode* left = convertListToBST(l, mid - 1);

        // Once left half is traversed, process the current node
        TreeNode* node = new TreeNode(iterator->val);
        node->left = left;

        // Maintain the invariance mentioned in the algorithm
        iterator = iterator->next;

        // Recurse on the right hand side and form BST out of them
        node->right = convertListToBST(mid + 1, r);

        return node;
    }
};