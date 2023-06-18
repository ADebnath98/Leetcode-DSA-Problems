Intuition
We can first find the number of strictly increasing
paths starting at postion [i,j]
Finally add all values of [i,j] to the answer
To find answer to particular postion we use DFS
Approach
Create 2D matrix ans
ans[i][j] will store number of paths starting at [i,j]
Now dfs for all i,j
In dfs we do ans[parent] = sum(ans[child]) + 1
Complexity
Time complexity: O(n∗m)O(n*m)O(n∗m)
Space complexity: O(n∗m)O(n*m)O(n∗m)


class Solution {
public:
    vector<vector<int>> ans;
    int n,m;
    int mod = 1000000007;
    vector<pair<int,int>> dir = {{0,1},{0,-1},{-1,0},{1,0}};

    int safe(int i,int j){
        if(i>=0 and i<n and j>=0 and j<m) return 1;
        else return 0;
    }

    void find(int i,int j,vector<vector<int>>& mat){
        if(ans[i][j] != -1) return;
        int res = 1;
        for(auto d:dir){
            int ni = i+d.first;
            int nj = j+d.second;
            if(not safe(ni,nj)) continue;
            if(mat[ni][nj] > mat[i][j]){
                find(ni,nj,mat);
                // adding the ans of the child to the parent
                res += ans[ni][nj];
                res %= mod;
            }
        }
        ans[i][j] = res;
    }

    int countPaths(vector<vector<int>>& mat) {

        n = mat.size();
        m = mat[0].size();
        ans.assign(n,vector<int>(m,-1));
        for(int i=0; i<n; i++){
            for(int j=0;j<m;j++){
                // dfs only if the postion is not visited
                if(ans[i][j] == -1){
                    find(i,j,mat);
                }
            }
        }

        // adding ans for all postions
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                res += ans[i][j];
                res %= mod;
            }
            cout<<endl;
        }

        return res;
    }
};