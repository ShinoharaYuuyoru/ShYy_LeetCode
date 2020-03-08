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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> numbers;
        if (root != NULL) {
            queue<TreeNode*> Q;
            Q.push(root);
            treeLevelTraverse(numbers, Q);
        }

        return numbers;
    }

private:
    void treeLevelTraverse(vector<vector<int>>& numbers, queue<TreeNode*> Q) {
        queue<TreeNode*> newQ;
        vector<int> levelNums;      // As the traverseNode(s) are not NULL, so the levelNums should not be empty.
        while (Q.empty() == false) {
            TreeNode* traverseNode = Q.front();     // The traverseNode may not be NULL.

            levelNums.push_back(traverseNode->val);

            if (traverseNode->left != NULL) {
                newQ.push(traverseNode->left);
            }
            if (traverseNode->right != NULL) {
                newQ.push(traverseNode->right);
            }

            Q.pop();
        }

        numbers.push_back(levelNums);

        if (newQ.empty() == false) {
            treeLevelTraverse(numbers, newQ);
        }
    }
};