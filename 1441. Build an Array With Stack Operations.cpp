class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int val = 1;
        for(int i=0; i<target.size(); i++){
            while(val != target[i]){
                ans.push_back("Push");
                ans.push_back("Pop");
                val++;
            }
            if(val == target[i]){
                ans.push_back("Push");
                val++;
            }
        }
        return ans;
    }
};