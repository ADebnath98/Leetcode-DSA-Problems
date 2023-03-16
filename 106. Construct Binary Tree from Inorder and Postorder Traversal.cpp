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
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        map<int,int> mpp;
        for(int i=0;i<in.size();i++)    mpp[in[i]]=i;
        TreeNode* root=solve(post,0,post.size()-1,in,0,in.size()-1,mpp);
        return root;
    }
    TreeNode* solve(vector<int>& post, int post_start , int post_end, vector<int>& in , int in_start , int in_end , map<int,int> &mpp)
    {
        if(post_start>post_end || in_start>in_end)  return NULL;
        TreeNode* root=new TreeNode(post[post_end]);
        int in_root=mpp[post[post_end]];
        int nums_left=in_root-in_start;
        root->left=solve(post , post_start , post_start+nums_left-1 , in , in_start , in_root-1 , mpp);
        root->right=solve(post , post_start+nums_left , post_end-1 , in , in_root+1 , in_end , mpp);
        return root;
    }
};