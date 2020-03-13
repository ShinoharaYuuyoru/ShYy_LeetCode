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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;

        root = BNTreeBuilder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);

        return root;
    }

    TreeNode* BNTreeBuilder(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd) {
        /*
            preorder[preStart] is the root of the tree.
            Find the root value in inorder[inStart, inEnd] to divide left and right tree.
        */
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        int rootVal = preorder[preStart];
        auto divideItr = find(inorder.begin() + inStart, inorder.begin() + inEnd + 1, rootVal);

        int leftTreeNodeNum = divideItr - inorder.begin() - inStart;

        TreeNode* root = new TreeNode(rootVal);
        root->left = BNTreeBuilder(preorder, preStart + 1, preStart + leftTreeNodeNum, inorder, inStart, inStart + leftTreeNodeNum - 1);
        root->right = BNTreeBuilder(preorder, preStart + leftTreeNodeNum + 1, preEnd, inorder, inStart + leftTreeNodeNum + 1, inEnd);

        return root;
    }
};