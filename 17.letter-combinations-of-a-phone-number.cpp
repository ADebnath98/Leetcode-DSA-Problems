class Solution {
public:
map<char,string>mp;
void f(int i,string &digits,string &s,vector<string>&ans){
    if(i>=digits.size()) {
        ans.push_back(s);
        return;
        }
    char curr=digits[i];
    for(auto it:mp[curr]){
        s+=it;
        f(i+1,digits,s,ans);
        s.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string s="";
        vector<string>ans;
        if(digits==s) return ans;
        f(0,digits,s,ans);
        return ans;
    }
};