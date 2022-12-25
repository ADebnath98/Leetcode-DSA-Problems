class Solution {
public:
    int fun(vector<int>& nums,int target){
        int cnt=0;
        int i=0;
        int sum=nums[i];
        while(sum<=target){
            if(i==nums.size()-1) return nums.size();
            cnt++;
            sum+=nums[++i];
        }
        return cnt;
      
    
    

    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(auto &u:queries){
            ans.push_back(fun(nums,u));
        }
        return ans;
    }
};