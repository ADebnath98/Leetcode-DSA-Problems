class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
      vector<int> ans;
      if (k==0){
        ans.push_back(target->val);
        return ans;
      }
       queue<TreeNode*> q;
      
       vector<TreeNode*> adj[500];
       q.push(root);
       //BFS in the binary tree to create the graph
       while (!q.empty()){
         TreeNode* front=q.front();
         q.pop();

         if (front->right){
           q.push(front->right);
         adj[front->val].push_back(front->right);
         adj[front->right->val].push_back(front);
       }
        if (front->left){
          q.push(front->left);
         adj[front->val].push_back(front->left);
         adj[front->left->val].push_back(front);
       }
       }
       vector<int> vis(500,0);
        queue<pair<TreeNode*,int>> q1;
        q1.push({target,0});
        vis[target->val]=1;
        while (!q1.empty()){
            TreeNode* front=q1.front().first;
            int cnt=q1.front().second;
            q1.pop();

            for (auto it:adj[front->val]){
              if (!vis[it->val]){
              vis[it->val]=1;
              q1.push({it, cnt+1});
              if (cnt+1==k)
              ans.push_back(it->val);
              }
            }
        }
        return ans;
    }
};