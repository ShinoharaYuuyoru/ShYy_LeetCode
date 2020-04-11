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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<char> pTree;
        queue<TreeNode*> pQ;
        pQ.push(p);
        levelTraverse(pQ, pTree);

        vector<char> qTree;
        queue<TreeNode*> qQ;
        qQ.push(q);
        levelTraverse(qQ, qTree);

        bool ANS = true;

        if (pTree.size() != qTree.size()) {
            ANS = false;
        }
        else {
            for (int i = 0; i < pTree.size(); i++) {
                if (pTree[i] != qTree[i]) {
                    ANS = false;

                    break;
                }
            }
        }

        return ANS;
    }

private:
    void levelTraverse(queue<TreeNode*>& Q, vector<char>& tree) {
        while (Q.empty() == false) {
            TreeNode* nowNode = Q.front();
            Q.pop();
            if (nowNode == nullptr) {
                tree.push_back('*');
            }
            else {
                tree.push_back('0' + nowNode->val);

                Q.push(nowNode->left);
                Q.push(nowNode->right);
            }
        }
    }
};