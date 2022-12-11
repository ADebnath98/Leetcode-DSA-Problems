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
    int maxPath=INT_MIN;
    int maxPathSum(TreeNode* root) {
        int temp = solve(root);
        return maxPath;
    }
    int solve(TreeNode* root)
    {
        if(!root) return 0; 

        int left = solve(root->left);
        int right = solve(root->right);

        //calculate current max
        int currMax = max({root->val,root->val+left,root->val+right,root->val+left+right});

        //store max path till now
        maxPath = max(currMax,maxPath);

        //return either root, or left path or right path
        return max({root->val,root->val+left,root->val+right});
    }
};