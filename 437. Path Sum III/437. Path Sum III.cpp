/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 // // Preorder(Unoptimized)
 // // 52ms 10.91%, 95.3MB 6.45%.
 // class Solution {
 // public:
 //     int pathSum(TreeNode* root, int sum) {
 //         int result = 0;
 //         vector<TreeNode*> outNodes;

 //         preOrder(root, sum, 0, outNodes, result);

 //         return result;
 //     }

 //     void preOrder(TreeNode* node, int sum, int currentSum, vector<TreeNode*> outNodes, int &result){
 //         if(node == nullptr){
 //             return;
 //         }
 //         else{
 //             currentSum += node->val;
 //             if(currentSum == sum){
 //                 result++;
 //             }
 //             outNodes.push_back(node);
 //             int tempSum = currentSum;
 //             // i < outNodes.size()-1 -> MUST reserve last one nodes because you can not give an empty tree.
 //             for(int i = 0; i < outNodes.size() - 1; i++){
 //                 tempSum -= outNodes[i]->val;
 //                 if(tempSum == sum){
 //                     result++;
 //                 }
 //             }

 //             preOrder(node->left, sum, currentSum, outNodes, result);
 //             preOrder(node->right, sum, currentSum, outNodes, result);

 //             outNodes.pop_back();
 //         }
 //     }
 // };


 // PreOrder with Hashmap
 // 16ms 90.68%, 19MB 12.90%.
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		unordered_map<int, int> hashMap;

		return preOrderWithHashmap(root, sum, hashMap, 0);
	}

	int preOrderWithHashmap(TreeNode* node, int sum, unordered_map<int, int>& hashMap, int currentSum) {
		if (node == nullptr) {
			return 0;
		}
		else {
			int result = 0;
			currentSum += node->val;
			result = (currentSum == sum) + (hashMap[currentSum - sum] ? hashMap[currentSum - sum] : 0);
			hashMap[currentSum]++;
			result += preOrderWithHashmap(node->left, sum, hashMap, currentSum) + preOrderWithHashmap(node->right, sum, hashMap, currentSum);
			hashMap[currentSum]--;

			return result;
		}
	}
};