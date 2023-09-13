class Solution {
public:
    static bool cmp(string &a, string &b)
    {
        if(a+b > b+a) return true;
        return false;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> str;
        string ans;

        for(int &x : nums) str.push_back(to_string(x));

        sort(str.begin(),str.end(),cmp);

        for(auto &s : str) ans += s;

        return ans[0] == '0' ? "0" : ans;
    }
};