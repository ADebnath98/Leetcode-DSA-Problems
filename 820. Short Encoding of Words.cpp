class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        unordered_set<string>un(words.begin(), words.end());
        
        for(auto x : un){
            
            for(int i = 1; i<x.length(); i++)
                un.erase(x.substr(i));
        }
        
        int ans = 0;
        for(auto x : un)
            ans += x.length() + 1;
        
        return ans;
        
    }
};