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
    int res=0;
    void solve(TreeNode*root, bool goLeft, int path){
        if(root==NULL)return;
        res=max(res, path);
        if(goLeft){
            solve(root->left, false, path+1);
            solve(root->right, true, 1);
        }
        else{
            solve(root->right, true, path+1);
            solve(root->left, false, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        solve(root, true, 0);
        solve(root, false, 0);
        return res;
    }
};