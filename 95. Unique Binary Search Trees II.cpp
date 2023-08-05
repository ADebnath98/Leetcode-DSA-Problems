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
   vector<TreeNode*> dfs( int l ,int h ){

  vector<TreeNode*> ans;
     for(int i=l;i<h;i++){
         
           vector<TreeNode*> left =dfs(l,i);
           vector<TreeNode*>  right  =dfs(i+1,h);

           for(int a=0;a<left.size();a++){

               for(int b=0;b<right.size();b++){
                      TreeNode * root= new TreeNode(i+1);
                      root->left=left[a];
                      root->right=right[b];
                      ans.push_back(root);
               }
           }

     }
     if(ans.size()==0)ans.push_back(NULL);
     return ans;
    }
    vector<TreeNode*> generateTrees(int n) {

     return dfs(0,n);
 
    }
};