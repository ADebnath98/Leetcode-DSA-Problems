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
    
    bool func(TreeNode* L, TreeNode* R){
        if(!L || !R) return L==R;
        if(L->val!= R->val) return false;
        
        if(!func(L->left, R->right) || !func(L->right, R->left)) 
            return false;
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        if(root){
            return func(root->left, root->right);
        }
        else return true;
    }
};