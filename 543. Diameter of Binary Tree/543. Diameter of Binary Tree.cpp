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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        ANS = 0;
        int maxSubtreeDepth = calcMaxDepth(root);

        return ANS - 1;
    }

private:
    int ANS;

    int calcMaxDepth(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        else {
            int leftSubtreeMaxDepth = calcMaxDepth(node->left);
            int rightSubtreeMaxDepth = calcMaxDepth(node->right);

            ANS = max(ANS, leftSubtreeMaxDepth + rightSubtreeMaxDepth + 1);

            return max(leftSubtreeMaxDepth, rightSubtreeMaxDepth) + 1;
        }
    }
};