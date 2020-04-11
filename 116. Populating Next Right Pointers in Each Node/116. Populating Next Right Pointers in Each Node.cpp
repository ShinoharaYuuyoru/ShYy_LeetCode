/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// Constant space simple solution
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37472/A-simple-accepted-solution
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }

        Node* pre = root;
        Node* cur = nullptr;
        while (pre->left != nullptr) {
            cur = pre;
            while (cur != nullptr) {
                cur->left->next = cur->right;

                if (cur->next != nullptr) {
                    cur->right->next = cur->next->left;
                }

                cur = cur->next;
            }

            pre = pre->left;
        }

        return root;
    }
};