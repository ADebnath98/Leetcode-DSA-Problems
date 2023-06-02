class Solution {
public:
    long double dis(int x ,int y , int p , int q){
        long dx =abs(x-p);
        long dy = abs(y-q);
        long dsq = dx*dx + dy*dy;
        return sqrt(dsq);
    }

    int func(int x , int  y , int r , vector<int>& vis , vector<vector<int>>& bombs){
        int partans= 1;
        for(int i = 0 ; i < bombs.size() ; i++){
            if(vis[i] == 1) continue;
            double dist = dis(x, y, bombs[i][0] , bombs[i][1]);
            if(dist <=  r ){
                vis[i] = 1;
                partans += func(bombs[i][0] , bombs[i][1] , bombs[i][2] , vis ,bombs);
            }
        }
        return partans;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int ans=0 ;
        vector<int>vis(bombs.size() , 0);
        for(int i = 0 ; i < bombs.size() ; i++){
            fill(vis.begin() , vis.end() , 0); 
            vis[i] = 1;
            ans = max(ans , func(bombs[i][0], bombs[i][1] , bombs[i][2] , vis , bombs));
        }
        return ans;
    }
};
