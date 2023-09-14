class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        int candProcessed=0;
        function<void(int)> f=[&](int currsum) {
            //
            if (currsum==target) {
                result.push_back(current);
                return;            
            }
            //
            if (candProcessed==candidates.size()) {
                return;
            }
            //
            int num=candidates[candProcessed];
            candProcessed++;
            int cnt=(target-currsum)/num;
            //use this candidate 0..cnt times
            f(currsum);
            for(int i=1;i<=cnt;++i) {
                current.push_back(num);
                f(currsum+num*i);                
            }
            for(int i=1;i<=cnt;++i) current.pop_back();
            candProcessed--;

        };
        f(0);
        return result;                
    }
};