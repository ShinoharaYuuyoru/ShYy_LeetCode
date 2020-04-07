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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* merged = nullptr;

        merge(merged, t1, t2);

        return merged;
    }

private:
    void merge(TreeNode*& nodeMerge, TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) {
            return;
        }
        else if (node1 != nullptr && node2 == nullptr) {
            int node1Val = node1->val;
            nodeMerge = new TreeNode(node1Val);

            merge(nodeMerge->left, node1->left, nullptr);
            merge(nodeMerge->right, node1->right, nullptr);
        }
        else if (node1 == nullptr && node2 != nullptr) {
            int node2Val = node2->val;
            nodeMerge = new TreeNode(node2Val);

            merge(nodeMerge->left, nullptr, node2->left);
            merge(nodeMerge->right, nullptr, node2->right);
        }
        else {
            int node1Val = node1->val;
            int node2Val = node2->val;
            nodeMerge = new TreeNode(node1Val + node2Val);

            merge(nodeMerge->left, node1->left, node2->left);
            merge(nodeMerge->right, node1->right, node2->right);
        }
    }
};