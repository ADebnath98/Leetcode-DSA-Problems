class Solution {
public:
    vector<int> fans;
    void help(map<char,int>& mp,int node,vector<vector<int>>& adj, string &labels,int parent){
        //cout<<node<<" ";
        int prev=mp[labels[node]];
        mp[labels[node]]++;
        
        for(auto child:adj[node]){
            if(child==parent){continue;}
            help(mp,child,adj,labels,node);
        }

        fans[node]+=mp[labels[node]]-prev;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        fans.resize(n);
        vector<vector<int>> adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        map<char,int> mp;
        help(mp,0,adj,labels,-1);
        return fans;
    }
};