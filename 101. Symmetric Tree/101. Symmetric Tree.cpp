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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        else {
            /*
                Level traverse.
                For left tree, we traverse from left to right.
                For right tree, we traverse from right to left.
                If the tree is a symmetric tree, the vectors should be the same.
            */
            vector<string> leftTreeNums;
            queue<TreeNode*> leftQ;
            leftQ.push(root->left);
            leftTreeTraverse(leftTreeNums, leftQ);

            vector<string> rightTreeNums;
            queue<TreeNode*> rightQ;
            rightQ.push(root->right);
            rightTreeTraverse(rightTreeNums, rightQ);

            // Check
            if (leftTreeNums.size() != rightTreeNums.size()) {
                return false;
            }
            else {
                bool isSymmetric = true;
                for (int i = 0; i < leftTreeNums.size(); i++) {
                    if (leftTreeNums[i] != rightTreeNums[i]) {
                        isSymmetric = false;
                        break;
                    }
                }

                return isSymmetric;
            }
        }
    }

private:
    void leftTreeTraverse(vector<string>& leftTreeNums, queue<TreeNode*> leftQ) {
        queue<TreeNode*> newQ;
        while (leftQ.empty() == false) {
            TreeNode* traverseNode = leftQ.front();
            if (traverseNode != NULL) {
                leftTreeNums.push_back(to_string(traverseNode->val));

                // Add left node first, then add right node.
                newQ.push(traverseNode->left);
                newQ.push(traverseNode->right);
            }
            else {
                leftTreeNums.push_back("*");
            }

            leftQ.pop();
        }

        if (newQ.empty() == false) {
            leftTreeTraverse(leftTreeNums, newQ);
        }
    }

    void rightTreeTraverse(vector<string>& rightTreeNums, queue<TreeNode*> rightQ) {
        queue<TreeNode*> newQ;
        while (rightQ.empty() == false) {
            TreeNode* traverseNode = rightQ.front();
            if (traverseNode != NULL) {
                rightTreeNums.push_back(to_string(traverseNode->val));

                // Add right node first, then add left node.
                newQ.push(traverseNode->right);
                newQ.push(traverseNode->left);
            }
            else {
                rightTreeNums.push_back("*");
            }

            rightQ.pop();
        }

        if (newQ.empty() == false) {
            rightTreeTraverse(rightTreeNums, newQ);
        }
    }
};