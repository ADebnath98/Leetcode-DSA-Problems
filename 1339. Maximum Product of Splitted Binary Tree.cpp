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
private:
    long res = INT_MIN;
    long tSum = 0;

    //finding total sum
    inline int sumUp(TreeNode* root){
        return root ? root->val + sumUp(root->left) + sumUp(root->right) : 0;
    }

    //finding maximum POS
    int dfs(TreeNode* root){
        if(not root) return 0;
        long sum = root->val + dfs(root->left) + dfs(root->right);
        res = max(res, sum*(tSum-sum));
        return sum;
    }

public:
    int maxProduct(TreeNode* root) {
        tSum = sumUp(root);
        dfs(root);
        return res%1000000007;
    }
};