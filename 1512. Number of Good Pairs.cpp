class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        map<int,int> mp;
        for(auto it:nums){
            count += mp[it];
            mp[it]++;
        }
        return count;
    }
};
