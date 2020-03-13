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
    void flatten(TreeNode* root) {
        if (root != NULL) {
            vector<TreeNode*> preorder;

            flattenQueueBuilder(root, preorder);

            flattenTreeBuilder(preorder);
        }
    }

    // Create a flatten queue by preorder traversing.
    void flattenQueueBuilder(TreeNode* node, vector<TreeNode*>& preorder) {
        /*
            The node should be always valid.
        */
        preorder.push_back(node);
        if (node->left != NULL) {
            flattenQueueBuilder(node->left, preorder);
        }
        if (node->right != NULL) {
            flattenQueueBuilder(node->right, preorder);
        }
    }

    // Build the flatten BNTree
    void flattenTreeBuilder(vector<TreeNode*>& preorder) {
        for (int i = 0; i < preorder.size() - 1; i++) {
            int j = i + 1;
            TreeNode* nowNode = preorder[i];
            TreeNode* nextNode = preorder[j];

            nowNode->left = NULL;
            nowNode->right = nextNode;
        }
    }
};