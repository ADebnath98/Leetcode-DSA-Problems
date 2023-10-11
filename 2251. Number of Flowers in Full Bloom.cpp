Intuition
Similar to finding maximum number of hotel rooms available at any time, given the reporting and leaving day of each customer.

Approach
We can use a strategy where we find the maximum number of flowers bloomed till a particular day by storing both the starting and ending time in a single array and sorting them.
Also, store the index of people in another array(here pp) and sort it.
Then, just find the number of flowers bloomed till the particular day in a linear fashion.

Complexity
Time complexity:
O(n+m)

Space complexity:
O(n+m)


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<pair<int,int>> v,pp;

        //1 represent the day it will bloom, -1 the day it will die
        for(auto &it: flowers){
            v.push_back({it[0],1});
            v.push_back({it[1]+1,-1});
        }
        //to sort the people array saving their indices
        for(int i=0;i<people.size();i++)
            pp.push_back({people[i],i});

        sort(pp.begin(),pp.end());
        sort(v.begin(),v.end());

        vector<int> ans(people.size());
        //count -> stores the number of flowers bloomed till ith day
        int count = 0, j=0;

        //people who will visit before any flower has bloomed
        while(j<pp.size() && pp[j].first<v[0].first){
            pp[j].second = 0;
            j++;
        }

        for(int i=0;i<v.size();i++){
            count += v[i].second;
            while(j<pp.size() && i<v.size()-1 && pp[j].first>=v[i+1].second && pp[j].first<v[i+1].first){
                // cout<<pp[j].first<<" "<<v[i].first<<'\n';
                ans[pp[j].second] = count;
                j++;
            }
        }
        while(j<pp.size()){
            ans[pp[j].second] = count;
            j++;
        }
        return ans;
    }
};