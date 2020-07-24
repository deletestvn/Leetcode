/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if(root == nullptr) return true;
        return isSymmetricRecursion(root -> left, root -> right);
    }

    bool isSymmetricRecursion(TreeNode* l1, TreeNode* l2) {
    	if(l1 == nullptr && l2 == nullptr) return true;
    	if(l1 == nullptr || l2 == nullptr) return false;

    	return (l1 -> val == l2 -> val) 
    		&& isSymmetricRecursion(l1 -> left, l2 -> right)
    		&& isSymmetricRecursion(l1 -> right, l2 -> left);
    }

    bool isSymmetricIteration(TreeNode* root) {
        if(root == nullptr) return true;
    	queue<TreeNode* > treeQueue;
    	treeQueue.push(root -> left);
    	treeQueue.push(root -> right);
    	while(!treeQueue.empty()) {
    		TreeNode* l1 = treeQueue.front();
    		treeQueue.pop();
    		TreeNode* l2 = treeQueue.front();
    		treeQueue.pop();

    		if(l1 == nullptr && l2 == nullptr) continue;
    		if(l1 == nullptr || l2 == nullptr) return false;
    		if(l1 -> val != l2 -> val) return false;

    		treeQueue.push(l1 -> left);
    		treeQueue.push(l2 -> right);
    		treeQueue.push(l1 -> right);
    		treeQueue.push(l2 -> left);
    	}

    	return true;
    }
};