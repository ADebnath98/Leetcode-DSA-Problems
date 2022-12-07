class Solution {
    int sum=0;
    void solve(TreeNode* root, int low, int high)
    {
        if(root==NULL) // if the root is null just return
        {
            return;
        }

        // if root is not null than definately it will be holding some value
        sum+=(root->val>=low && root->val<=high)?root->val:0;
        
        if(root->left==NULL && root->right!=NULL) // considering right subtree
        {
            solve(root->right,low,high);
        }
        else if(root->right==NULL && root->left!=NULL) //considering left subtree
        {
            solve(root->left,low,high);
        }
        else // else considereing both left and right subtree 
        {
            solve(root->left,low,high);
            solve(root->right,low, high);
        }
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root,low,high);
        return sum;
    }
};