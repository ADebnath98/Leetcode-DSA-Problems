class TreeAncestor {
public:
vector<vector<int>> parents;
    TreeAncestor(int n, vector<int>& parent) {
        parents.resize(16,vector<int>(n));
        for(int i=0;i<n;i++)
        parents[0][i]=parent[i];
        for(int k=1;k< 16;k++){
            for(int i=0;i<n;i++){
                int intermediate=parents[k-1][i];
                if(intermediate!=-1)
                parents[k][i]=parents[k-1][intermediate];
                else
                parents[k][i]=-1;
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        for(int i=0;i<16;i++){
            if(k & (1<<i))
            node=parents[i][node];
            if(node==-1) return -1;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */