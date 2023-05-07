class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> ans;
        vector<int> curr;
        curr.push_back(obstacles[0]);
        ans.push_back(1);
        std::vector<int>::iterator temp;
        for(int i = 1;i<obstacles.size();i++){
            temp = upper_bound(curr.begin(), curr.end(), obstacles[i]);
            if((temp-curr.begin()) == curr.size()){
                curr.push_back(obstacles[i]);
                ans.push_back(curr.size());
            }
            else{
                curr[temp-curr.begin()] = obstacles[i];
                ans.push_back(1+temp-curr.begin());
            }
        }
        return ans;

    }
};