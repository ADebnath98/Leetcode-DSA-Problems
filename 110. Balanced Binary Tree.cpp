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
    int height(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(height(root->left),height(root->right));

    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(abs(leftHeight-rightHeight)>1)return false;

        bool leftAns = isBalanced(root->left);
        if(leftAns==false)return false;
        bool rightAns = isBalanced(root->right);
        if(rightAns==false)return false;
        return true;
    }
};