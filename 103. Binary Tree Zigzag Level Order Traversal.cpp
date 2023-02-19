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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> level;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node -> val);
                if(node -> left)
                {
                    q.push(node -> left);
                }
                if(node -> right)
                {
                    q.push(node -> right);
                }
            }
            count++;
            if(count % 2 == 0)
            {
                reverse(level.begin(), level.end());
            }
            ans.push_back(level);
            level.clear();
        }
        return ans;
    }
};