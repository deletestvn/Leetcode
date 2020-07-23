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
    vector<vector<int>> levelOrder(TreeNode* root) {
    	if(root == nullptr) return {};

    	vector<int> currLevel;
        vector<vector<int>> result;
        
        queue<TreeNode* > treeQueue;
        treeQueue.push(root);

        int levelCount = 1;

        while(!treeQueue.empty()) {
        	TreeNode * currNode = treeQueue.front();
        	if(currNode -> left != nullptr) treeQueue.push(currNode -> left);
        	if(currNode -> right != nullptr) treeQueue.push(currNode -> right);

        	currLevel.push_back(currNode -> val);
        	treeQueue.pop();

        	if(--levelCount == 0) {
        		result.emplace_back(currLevel);
        		currLevel.clear();
        		levelCount = treeQueue.size();
        	}
        }        
        return result;
    } 
};