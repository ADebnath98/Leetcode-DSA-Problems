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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int res=INT_MIN,cnt=1,lvl=1;
        while(!q.empty()){
            vector<int>level;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            int temp=0;
            for(auto it:level){
                temp+=it;   //calculating the sum at this level
            }
    
            if(temp>res){
                res=temp;  //comparing it if current sum greater then update the  result
                lvl=cnt;   //store  this level
            }
            cnt++; //counter for every level tracking
        }
        return lvl;
    }
};