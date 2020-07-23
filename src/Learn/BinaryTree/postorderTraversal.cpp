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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderRecursion(root, result);
        return result;
    }

    void postorderRecursion(TreeNode* root, vector<int>& result) {
    	if(root == nullptr) return;

    	postorderRecursion(root -> left, result);
    	postorderRecursion(root -> right, result);
    	result.push_back(root -> val);
    }

    void postorderIteration(TreeNode* root, vector<int>& result) {
    	if(root == nullptr) return;

        stack<TreeNode *> treeStack;
        treeStack.push(root);
        TreeNode * prevNode = root;

        while(!treeStack.empty()) {
        	TreeNode * currNode = treeStack.top();
        	if(currNode -> left != nullptr && currNode -> left != prevNode && currNode -> right != prevNode) 
        		treeStack.push(currNode -> left);
        	else if(currNode -> right != nullptr && currNode -> right != prevNode)
        		treeStack.push(currNode -> right);
        	else {
        		result.push_back(currNode -> val);
        		prevNode = treeStack.top();
        		treeStack.pop();
        	}
        }
    }
};