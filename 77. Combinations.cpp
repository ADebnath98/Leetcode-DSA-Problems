class Solution {
public:
    void subsets(int n, int k, vector<int>&subOp, vector<vector<int>>&ans,int i){
        //base case
        if(i==n+1){
            if(subOp.size()==k){
            ans.push_back(subOp);
            }
            return;
        }

        //rec case
        //either not take
        subsets(n, k, subOp, ans, i+1);
        //or takee
        subOp.push_back(i);
        subsets(n, k , subOp,ans, i+1);
        subOp.pop_back();

    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int>subOp;
        vector<vector<int>>ans;
        subsets(n,k,subOp,ans,1);
        return ans;
    }
};