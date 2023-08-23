class Solution {
public:
struct comp{
    bool operator()(const pair<char,int>&a , const pair<char,int>&b){
        return a.second < b.second;
    }
};

    string reorganizeString(string s) {
        unordered_map<char, int>m;
        for(int i = 0 ; i < s.length() ; i++){
            m[s[i]]++;
        }
        priority_queue<pair<char,int>,vector<pair<char,int>>,comp>pq;
        for(auto i: m){
            pq.push(i);
        }
        pair<char,int>prev;
        string ans = "";
        while(!pq.empty()){
            pair<char , int>current = pq.top();
            pq.pop();
            
            if(prev.second > 0){
                pq.push(prev);
            }
            ans += current.first;
            current.second--;
            prev = current;
            
        }

        return ans.length() == s.length() ? ans : "";
        
    }
};