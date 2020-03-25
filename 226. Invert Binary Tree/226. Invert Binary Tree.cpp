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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* head = root;
        if (head == nullptr) {
            return head;
        }

        doInvert(head);

        return head;
    }

private:
    void doInvert(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;

        doInvert(node->left);
        doInvert(node->right);

        return;
    }
};