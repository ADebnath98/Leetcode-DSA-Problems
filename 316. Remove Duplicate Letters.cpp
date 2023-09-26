Approach
Vector LastIndex is used to store the last index of every character of the string.
vector check is used to check if we added the current character in stack or not.
Stack is used to store the previous characters that is stored yet.




class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastIndex(26, -1);
        for(int i = 0; i < s.size(); i++)
            lastIndex[s[i] - 'a'] = i;
        
        vector<bool> check(26, false);
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            int c = s[i] - 'a';
            if(check[c])
                continue;
            while(!st.empty() && s[i] < st.top() && lastIndex[st.top() - 'a'] > i){
                check[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            check[c] = true;
        }
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


