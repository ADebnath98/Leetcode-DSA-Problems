class DSU {

    vector<int> rank;
    vector<int> parent;
    int components = 0;

public:

    DSU(int n)
    {
        components = n;
        rank = vector<int>(n, 0);
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int getParent(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = getParent(parent[node]);
    }

    bool doUnion(int n1, int n2)
    {
        int p1 = getParent(n1);
        int p2 = getParent(n2);

        if(p1 == p2)
            return false;
        
        components--;

        if(rank[p1] < rank[p2])
        {
            parent[p1] = p2;
        }
        else if(rank[p2] < rank[p1])
        {
            parent[p2] = p1;
        }
        else
        {
            rank[p1]++;
            parent[p2] = p1;
        }
        
        return true;
    }

    bool isFullyConnected()
    {
        return components == 1;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        int edgesUsed = 0;
        DSU dsuA(n), dsuB(n);
        
        for(auto const& edge : edges)
        {
            if(edge[0] != 3)
                continue;
            bool A = dsuA.doUnion(edge[1] - 1, edge[2] - 1);
            bool B = dsuB.doUnion(edge[1] - 1, edge[2] - 1);

            if(A || B)
                edgesUsed++;
        }
        
        for(auto const& edge : edges)
        {
            if(edge[0] == 3)
                continue;
            bool A;
            if(edge[0] == 1)
                A = dsuA.doUnion(edge[1] - 1, edge[2] - 1);
            else if(edge[0] == 2)
                A = dsuB.doUnion(edge[1] - 1, edge[2] - 1);

            if(A)
                edgesUsed++;
        }

        if(!dsuA.isFullyConnected() || !dsuB.isFullyConnected())
            return -1;
        
        return edges.size() - edgesUsed;
    }
};