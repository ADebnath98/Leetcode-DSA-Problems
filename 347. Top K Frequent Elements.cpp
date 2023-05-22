class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int n:nums)
        {
            freq[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto it:freq)
        {
            pq.push({it.second,it.first});
        }
        int limit=k;
        vector<int> ans;
        while(limit-- && !pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};