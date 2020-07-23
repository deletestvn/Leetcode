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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderRecursion(root, result);
        return result;
    }

    void inorderRecursion(TreeNode* root, vector<int>& result) {
    	if(root == nullptr) return;

    	inorderRecursion(root -> left, result);
    	result.push_back(root -> val);
    	inorderRecursion(root -> right, result);
    }

    void inorderIteration(TreeNode* root, vector<int>& result) {
    	if(root == nullptr) return;

    	stack<TreeNode *> treeStack;
    	TreeNode * currNode = root;

    	while(currNode != nullptr || !treeStack.empty()) {
    		while(currNode != nullptr) {
    			treeStack.push(currNode);
    			currNode = currNode -> left;
    		}
    		
    		currNode = treeStack.top();
    		treeStack.pop();
    		result.push_back(currNode -> val);
    		currNode = currNode -> right;
    	}
    }
};