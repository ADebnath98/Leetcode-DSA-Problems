class Solution {
public:
    stack<char> rec(string s,int &i){
        stack<char> st;
        while(i<s.size()){
            if(s[i]==')'){
                i++;
                return st;
            }else if(s[i]=='('){
                i++;
                stack<char> kt = rec(s,i);
                while(!kt.empty()){
                    st.push(kt.top());
                    kt.pop();
                }
            }else{
                st.push(s[i]);
                i++;
            }
        }

        return st;
    }
    string reverseParentheses(string s) {
        string ans="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='('){
                i++;
                stack<char> q = rec(s,i);
                while(!q.empty()){
                    ans+=q.top();
                    q.pop();
                }
            }else{
                ans+=s[i];
                i++;
            }
        }

        return ans;
    }
};