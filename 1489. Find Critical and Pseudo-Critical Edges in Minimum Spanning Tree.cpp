Approach
It is an extenstion of Kruskal's Algorithm to find the critical and pseudo critical edges.

Complexity
Time complexity: E^2 + E*logE
Space complexity: V , V is nodes
Neglecting the space required to store answer.


class Solution {
public:

    class DSU{

        public:

        vector <int> parent;
        vector <int> size;

        DSU(int n){

            parent.resize(n,0);
            size.resize(n,1);

            for(int i=0 ; i<n ; i++){
                parent[i] = i;
            }
        }

        int findUPar(int node){

            if(node == parent[node]){
                return node;
            }

            return parent[node] = findUPar(parent[node]);

        }

        void unionBySize(int u , int v){

            int up_u = findUPar(u);
            int up_v = findUPar(v);

            // Already connected to the same set
            if(up_u == up_v) return;

            if(size[up_u] > size[up_v]){
                size[up_u] += size[up_v];
                parent[up_v] = up_u; 
            }

            else{

                size[up_v] += size[up_u];
                parent[up_u] = up_v;
            }

        }

    };

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        // DSU object d
        DSU d(n);

        auto newEdges = edges;
        
        // Add index to edges for tracking
        int m = newEdges.size();
        
        for (int i = 0; i < m; i++) {
            newEdges[i].push_back(i);
        }

        // Sort edges based on weight
        sort(newEdges.begin(), newEdges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
        });


        int mst = 0;

        // Now traverse in edges and check if already being connected or not

        for(auto &edge: newEdges){

            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            // Check if not already connected

            if(d.findUPar(u) != d.findUPar(v)){

                d.unionBySize(u,v);
                mst += wt;
            }

        }

        // Now finding out the critical edges
        vector <int> criticalEdges;
        vector <int> pseudocriticalEdges;

        for(int i=0 ; i<m ; i++){

            // Deleting or ignoring the ith edges while calculating MST
            DSU x(n);
            int currMst = 0;

            for(int j = 0 ; j<m ; j++){

                if(i != j){

                    int u = newEdges[j][0];
                    int v = newEdges[j][1];
                    int wt = newEdges[j][2];

                    // Check if not already connected

                    if(x.findUPar(u) != x.findUPar(v)){

                        x.unionBySize(u,v);
                        currMst += wt;

                    }

                }
            }

            // Now if my CurrMST is greater than mst means we have ignored a critical edge
            // ot currMst is smaller than even the standard MST value means , removing ith edge leads to disconnected components , hence i is also an critical edge

            if(currMst > mst or currMst < mst){

                criticalEdges.push_back(newEdges[i][3]);
            }

            // Now find the pseudo critical nodes

            else{

                // Force this ith edge and again calculate the MST , if forcing this node has does not have any effect on the original mst that means it a pseduo critical node

                DSU y(n);

                // forced the edge ant took UNION
                y.unionBySize(newEdges[i][0] , newEdges[i][1]);

                int forcedMST = newEdges[i][2];

                for(int j = 0 ; j<m ; j++){

                    if(i != j){

                        int u = newEdges[j][0];
                        int v = newEdges[j][1];
                        int wt = newEdges[j][2];

                        // Check if not already connected

                        if(y.findUPar(u) != y.findUPar(v)){

                            y.unionBySize(u,v);
                            forcedMST += wt;
                        }

                    }
                }

                if(forcedMST == mst) pseudocriticalEdges.push_back(newEdges[i][3]);

            }

        }

        
        return {criticalEdges , pseudocriticalEdges};

    }
};