/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // DP
 // https://leetcode.com/problems/house-robber-iii/discuss/79333/Simple-C%2B%2B-solution
class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;

        return doRob(root, l, r);
    }

private:
    int doRob(TreeNode* node, int& l, int& r) {
        if (node == nullptr) {
            return 0;
        }

        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = doRob(node->left, ll, lr);
        r = doRob(node->right, rl, rr);

        return max(node->val + ll + lr + rl + rr, l + r);
    }
};