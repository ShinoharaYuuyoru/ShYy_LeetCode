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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode* LCA = nullptr;
        bool finalFlag = LCAFinder(root, LCA, p, q);

        return LCA;
    }

private:
    bool LCAFinder(TreeNode* node, TreeNode*& LCA, TreeNode* p, TreeNode* q) {
        if (node == nullptr) {
            return false;
        }
        else {
            if (LCA != nullptr) {
                return false;
            }
            else {
                bool thisFlag = (node == p) | (node == q);

                bool leftFlag = false;
                bool rightFlag = false;
                leftFlag = LCAFinder(node->left, LCA, p, q);
                rightFlag = LCAFinder(node->right, LCA, p, q);

                int sum = thisFlag + leftFlag + rightFlag;
                if (sum >= 2) {
                    LCA = node;
                }

                return thisFlag | leftFlag | rightFlag;
            }
        }
    }
};