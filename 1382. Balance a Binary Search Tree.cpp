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

     void inorder(TreeNode* root, vector<TreeNode*> &v) {
        if (root==NULL)
            return;
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
    
    TreeNode* createBST(vector<TreeNode*> &v, int s, int e) {
        if (e<s)
            return NULL;
        
        int mid = s + (e-s)/2;
        TreeNode* root = v[mid];
        root->left = createBST(v, s, mid-1);
        root->right = createBST(v, mid+1, e);
        
        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
       vector<TreeNode*> v;
        inorder(root,v);
        return createBST(v,0,v.size()-1);
    }
};