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
    string tmp;
    string helper(TreeNode* root, unordered_map <string,int> &ump, vector <TreeNode*> &ans){
        if(!root)
            return "";
        tmp = to_string(root->val) + "-" + helper(root->left,ump,ans) + "-" + helper(root->right,ump,ans);
        ump[tmp]++;
        if(ump[tmp] == 2)
            ans.push_back(root);
        return tmp;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(!root)
            return {};
        unordered_map <string,int> ump;
        vector <TreeNode*> ans;
        helper(root,ump,ans);
        return ans;
    }
};