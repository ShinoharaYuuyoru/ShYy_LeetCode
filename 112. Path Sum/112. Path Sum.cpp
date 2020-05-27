/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) {
            return false;
        }

        bool ANS = false;

        preTraverse(root, sum, 0, ANS);

        return ANS;

    }

    void preTraverse(TreeNode* node, int& sum, int nowSum, bool& ANS) {
        // Cut
        if (ANS == true) {
            return;
        }

        if (node == nullptr) {
            return;
        }

        nowSum += node->val;

        // Leaf node
        if (node->left == nullptr && node->right == nullptr) {
            if (nowSum == sum) {
                ANS = true;
                return;
            }
            else {
                ;
            }
        }
        else {
            preTraverse(node->left, sum, nowSum, ANS);
            preTraverse(node->right, sum, nowSum, ANS);
        }
    }
};