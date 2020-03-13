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
    int maxDepth(TreeNode* root) {
        if (root != NULL) {
            int treeDepth = 0;
            queue<TreeNode*> nodeQ;
            queue<int> levelQ;
            nodeQ.push(root);
            levelQ.push(1);

            while (nodeQ.empty() == false && levelQ.empty() == false) {
                TreeNode* nowNode = nodeQ.front();
                int nowLevel = levelQ.front();

                treeDepth = nowLevel;

                if (nowNode != NULL) {
                    if (nowNode->left != NULL) {
                        nodeQ.push(nowNode->left);
                        levelQ.push(nowLevel + 1);
                    }
                    if (nowNode->right != NULL) {
                        nodeQ.push(nowNode->right);
                        levelQ.push(nowLevel + 1);
                    }

                    nodeQ.pop();
                    levelQ.pop();
                }
                else {
                    cout << "CRITICAL ERROR!" << endl;
                    exit(1);
                }
            }

            return treeDepth;
        }
        else {
            return 0;
        }
    }
};