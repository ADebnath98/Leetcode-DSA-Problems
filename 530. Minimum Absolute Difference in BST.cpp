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
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL){
            return INT_MAX;
        }
        int ans = INT_MAX;
        if (root->left){
            TreeNode* leftMin = root->left;
            while(leftMin->right != NULL){
                leftMin = leftMin->right;
            }
            ans = min(abs(root->val - leftMin->val), ans);
            ans = min(getMinimumDifference(root->left), ans);
        }
        if (root->right){
            TreeNode* rightMin = root->right;
            while(rightMin->left != NULL){
                rightMin = rightMin->left;
            }
            ans = min(abs(root->val - rightMin->val), ans);
            ans = min(getMinimumDifference(root->right), ans);
        }
        return ans;
    }
};