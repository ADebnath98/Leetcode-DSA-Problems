class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>m;
        for(int i=0;i<arr.size();i++){
        m[arr[i]]++;
        }
        vector<int>v;
        for(auto x:m){
            v.push_back(x.second);
        }
        for(auto x:m){
            if(count(v.begin(),v.end(),x.second)>1){
                return false;
            }
        }
        
        return true;
    }
};