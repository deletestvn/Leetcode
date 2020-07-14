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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return vector<TreeNode*>(0);
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
    	// If a tree cannot be generated with current interval
    	if(start > end) return vector<TreeNode*>{nullptr};

    	vector<TreeNode*> results;

    	// For current interval each number is taken as root once
    	for(int i = start; i <= end; i++) {
    		vector<TreeNode*> leftTrees, rightTrees;
            
            // Generate left and right
    	    leftTrees = helper(start, i - 1);
   			rightTrees = helper(i + 1, end);
            
    		// Combine root with left and right
    		for(auto leftTree : leftTrees) {
    			for(auto rightTree : rightTrees) {
    				auto root = new TreeNode(i);
    				root -> left = leftTree;
    				root -> right = rightTree;
    				results.push_back(root);
    			}
    		}
    	}
        return results;
    }
};