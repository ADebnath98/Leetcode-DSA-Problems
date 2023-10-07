class Solution {
public:
int mod=1e9+7;
int dp[55][55][105];
int f(int n,int m, int k,int i,int used , int prev){
    if(i>=n){
        if(used==k)return 1;
        else return 0;
    }

    if(dp[i][used][prev+1]!=-1)return dp[i][used][prev+1];



    int ans =0;
    for(int j=1;j<=m;j++){
        // cout<<i<<" "<<used<<" "<<prev<<endl;  
        if(j>prev){
            if(used+1<=k)ans+=f(n,m,k,i+1,used+1 , j);
        }else{
            ans+=f(n,m,k,i+1,used,prev);
        }
        ans%=mod;
    }

    return dp[i][used][prev+1] = ans;

}
    int numOfArrays(int n, int m, int k) {
        memset(dp , -1 , sizeof(dp));
        return f(n,m,k,0,0,-1 );
        
    }
};