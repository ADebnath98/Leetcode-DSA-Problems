class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
       
        vector<int> ans;
        
        vector<pair<int, pair<int, int>>> temp;
        for(int i = 0; i < tasks.size(); i++) {
            temp.push_back({tasks[i][0], {tasks[i][1], i}});
        }

        sort(temp.begin(), temp.end());
       

        int count = tasks.size();
        int index = 0;
        long long limit = temp[0].first;
        
        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, greater<pair<int, int>>> mini;

        while(count) {

            int i = index;

            while(index < tasks.size()) {
                if(limit < temp[index].first) {
                    break;
                }

                mini.push({temp[index].second.first, temp[index].second.second});
                index++;
            }

            if(index == i && index != tasks.size() && mini.empty()) {
                limit = temp[index].first;
            }


            if(mini.size()) {
                ans.push_back(mini.top().second);
                limit += mini.top().first;
                mini.pop();
                count--;
            }

        }      

        return ans;
    }
};