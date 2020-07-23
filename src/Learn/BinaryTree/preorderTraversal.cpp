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
    vector<int> preorderTraversal(TreeNode* root) {     
        vector<int> result;
        preorderRecursion(root, result);
        return result;         
    }

    void preorderRecursion(TreeNode* root, vector<int>& result) {
        if(root == nullptr) return;

        result.push_back(root -> val);
        preorderRecursion(root -> left, result);
        preorderRecursion(root -> right, result);
    }

    void preorderIteration(TreeNode* root, vector<int>& result) {
        if(root == nullptr) return;

        stack<TreeNode *> treeStack;
        
        treeStack.push(root);

        while(!treeStack.empty()) {
            TreeNode * currNode = treeStack.top();
            result.push_back(currNode -> val);
            treeStack.pop();

            if(currNode -> right != nullptr) treeStack.push(currNode -> right);
            if(currNode -> left != nullptr) treeStack.push(currNode -> left);
        }
    }
};