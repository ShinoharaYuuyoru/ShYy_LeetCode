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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        else {
            vector<int> numbers;
            LDR(root, numbers);     // Traverse the tree in LDR.

            // Check
            bool isValid = true;
            for (int i = 1; i < numbers.size(); i++) {
                if (numbers[i] > numbers[i - 1]) {
                    isValid = true;
                    continue;
                }
                else {
                    isValid = false;
                    break;
                }
            }

            return isValid;
        }
    }

private:
    void LDR(TreeNode* node, vector<int>& numbers) {
        if (node != NULL) {
            LDR(node->left, numbers);
            numbers.push_back(node->val);
            LDR(node->right, numbers);
        }
    }
};