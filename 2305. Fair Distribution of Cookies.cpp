class Solution {
public:
    int solve(vector<int>& cookies,int indx,vector<int>&child,int maxi){
          if(indx>=cookies.size()) 
            return maxi;

          int ans = INT_MAX;
          for(int i = 0 ;i< child.size();i++){
              child[i] +=cookies[indx];
             ans = min (ans,solve(cookies,indx+1,child,max(maxi,child[i])));
              child[i] -=cookies[indx];
          }
        return ans;
     }  
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        int maxi = INT_MIN;
        return solve(cookies,0,child,maxi);
    }
};