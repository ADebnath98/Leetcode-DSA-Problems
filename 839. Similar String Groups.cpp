class Solution {
public:
    vector<vector<int>> groupAnagrams(vector<string> strs) {
        unordered_map<string,vector<int>>m;
        for(int i=0;i<strs.size();i++)
        {
                sort(strs[i].begin(), strs[i].end());
                m[strs[i]].push_back(i);      
        }
        vector<vector<int>> v;
        
        for(auto it=m.begin();it!=m.end();it++)
        {
            v.push_back(it->second);
        }
        
        return v;      
    }
    
    int findParent(int node,vector<int>&parent)
    {
        if(node==parent[node])return node;
        return parent[node]=findParent(parent[node],parent);
    }
    void unionn(int u,int v,vector<int>&parent,vector<int>&rank)
    {
        u=findParent(u,parent);
        v=findParent(v,parent);
        if(rank[u]<rank[v])
        {
            parent[u]=v;
            rank[v]++;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
            rank[u]++;
        }
        else
        {
            if(u<v)
            {
                parent[v]=u;
                rank[u]++;
            }
            else
            {
                parent[u]=v;
                rank[v]++;
            }
        }
    }
    // "tars", "rats", "arts","star"
    bool check(int u,int v,vector<string>&strs)
    {
        string s1=strs[u];
        string s2=strs[v];
        int ind=-1;
        bool ans=false;
        int diff=0;
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(ind==-1)ind=i;
                else
                {
                    if(s1[i]==s2[ind] and s1[ind]==s2[i])
                    {
                        ans=true;
                    }
                    else
                        return false;
                }
                diff++;
            }
            if(diff>2)return false;
        }
        if(diff==0)return true;
        return ans;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>v=groupAnagrams(strs);
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        // for(auto it:v)
        // {
        //     for(int i:it)
        //     {
        //         cout<<strs[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto &it:v)
        {
            for(int i=0;i<it.size();i++)
            {
                for(int j=i+1;j<it.size();j++)
                {
                    
                    if(check(i,j,strs))
                    {
                        // cout<<i<<" "<<j<<endl;
                        unionn(i,j,parent,rank);
                    }
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            parent[i]=findParent(i,parent);
            // cout<<parent[i]<<" ";
        }
        // cout<<endl;
        unordered_set<int>st;
        for(int i:parent)
            st.insert(i);
        // for(auto it:st)
        // cout<<it<<" ";
        int ans=st.size();
        return ans;
        // 0 1 2 3 4 5 6 7 8 9
        // 0 0 2 0 4 4 0 2 0 2
    }
};