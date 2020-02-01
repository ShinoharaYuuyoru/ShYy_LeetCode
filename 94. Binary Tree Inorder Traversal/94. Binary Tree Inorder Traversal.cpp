/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // Recursive
 // 0ms 100.00%, 9.2MB 89.00%.
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;

		binaInorder(root, result);

		return result;
	}

	void binaInorder(TreeNode* node, vector<int>& result) {
		if (node == nullptr) {
			return;
		}
		else {
			binaInorder(node->left, result);
			result.push_back(node->val);
			binaInorder(node->right, result);
		}
	}
};


// // Iterative
// // 4ms 60.89%, 9.1MB 95.00%.
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> result;
//         stack<TreeNode*> s;
//         TreeNode* node = root;

//         while(node != nullptr || s.empty()==false){
//             while(node != nullptr){
//                 s.push(node);
//                 node = node -> left;
//             }

//             node = s.top();
//             s.pop();
//             result.push_back(node->val);
//             node = node -> right;
//         }

//         return result;
//     }
// };
