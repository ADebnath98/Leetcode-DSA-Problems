class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    pq.push({0,{i,j}});
                }
            }
        }

        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int nh = temp.first+1;
            int i=temp.second.first;
            int j=temp.second.second;

            if((i-1)>=0){
                if(res[i-1][j]>nh){
                    res[i-1][j]=nh;
                    pq.push({nh,{i-1,j}});
                }
            }

            if((j-1)>=0){
                if(res[i][j-1]>nh){
                    res[i][j-1]=nh;
                    pq.push({nh,{i,j-1}});
                }
            }

            if((i+1)<m){
                if(res[i+1][j]>nh){
                    res[i+1][j]=nh;
                    pq.push({nh,{i+1,j}});
                }
            }

            if((j+1)<n){
                if(res[i][j+1]>nh){
                    res[i][j+1]=nh;
                    pq.push({nh,{i,j+1}});
                }
            }
        }
        return res;
    }
};