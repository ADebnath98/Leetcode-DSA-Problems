class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string a;
        for(int i=0;i<words.size();i++){
            a+=words[i];
            if(a==s)    return true;
        }
        return false;
    }
};