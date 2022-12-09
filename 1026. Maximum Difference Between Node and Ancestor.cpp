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
    int maxAncestorDiff(TreeNode* root) {
        int ans=0;
        DFS(root, 1000000, -1, ans);
        return ans;
    }
    void DFS (TreeNode* root, int Min ,int Max , int&ans)
    {
        Max = max(Max , root->val);
        Min = min(Min , root->val);
        if (root->left == nullptr && root->right == nullptr)
            ans = max (ans, abs(Max-Min));
        if(root->left)
          DFS(root->left , Min, Max , ans);
        if(root->right)
          DFS(root->right, Min , Max , ans);
        
    }
};