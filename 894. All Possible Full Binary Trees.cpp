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
 
vector<TreeNode*> v[21];
class Solution {
public:

    vector<TreeNode*> allPossibleFBT(int n) {
        if(v[1].empty()){
            v[1] = {new TreeNode()};
            for(int i=3; i<=20; i++){
                for(int j=1; j<i; j+=2){
                    for(auto&l:v[j]){
                        for(auto&r:v[i-1-j]){
                            TreeNode* root = new TreeNode();
                            root->left = l;
                            root->right = r;
                            v[i].push_back(root);
                        }
                    }
                }
            }
        }

        return v[n];
    }
};