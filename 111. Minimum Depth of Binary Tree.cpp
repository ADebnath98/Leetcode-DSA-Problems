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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;

    // ************ BFS *************
    //     int depth = 0;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(!q.empty()){
    //         int sz = q.size();
    //         depth++;
    //         for(int i=0;i<sz;i++){
    //             TreeNode* node = q.front();
    //             q.pop();
    //             if(node->right == NULL && node->left == NULL){
    //                 return depth;
    //             }
    //             if(node->right){
    //                 q.push(node->right);
    //             }
    //             if(node->left){
    //                 q.push(node->left);
    //             }
    //         }
    //     }
    //     return 0;

    // ************ DFS **************

    int left = minDepth(root->left);
    int right = minDepth(root->right);

    if(root->left && root->right){
        return min(left+1, right+1);
    }

    return max(left+1, right+1);
    }
};