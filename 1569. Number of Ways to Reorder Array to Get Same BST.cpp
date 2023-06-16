class Solution {
public:
    int mod = 1e9+7;
    vector<vector<long long>>dp;

    long long helper(vector<int>&nums){
        int n= nums.size();
        
        //case when one of the child of parent is absent in that case there is only 1 way to arrange them
        if(n<=2)       
            return 1;
        
        vector<int> small, big;
        
        //forming array of smaller and larger elements separately
        for(int i =1 ; i< n ; i++){                 
            if(nums[i]<nums[0])
                small.push_back(nums[i]);
            else
                big.push_back(nums[i]);
        }

        //finding answer with n smaller elements and m larger elements using corresponding pascal triangle value (m+n)C(m)
        return ( ( ( helper(small) * helper(big) ) % mod ) *  dp[small.size() + big.size()][small.size()]  ) % mod;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1,vector<long long>(n+1,0));
        
        for(int i = 0 ; i < n+1; i++){                  //forming pascal's triangle
            
            dp[i][0]=1;
            dp[i][i]=1;

            for(int j =1 ; j<i ;j++)
                dp[i][j] = ( dp[i-1][j] + dp[i-1][j-1] ) % mod;
        }

        return helper(nums) - 1;        
    }
};