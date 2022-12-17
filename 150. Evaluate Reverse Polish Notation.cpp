class Solution {
public:

void solve(vector<string> tokens , int &evaluate){

    stack<long long>st;

    string s1 = tokens[0];
    st.push(stoi(s1));

    for(int i = 1 ; i < tokens.size() ; i++){
        if( tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/" ){
            string s2 = tokens[i];

            st.push(stoi(s2));
        }
        else{
            if(tokens[i] == "+"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                int add = v1 + v2;
                st.push(add);
            }
            else if(tokens[i] == "-"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                int sub = v2 - v1;
                st.push(sub);
            }
            else if(tokens[i] == "*"){
                long v1 = st.top();
                st.pop();
                long v2 = st.top();
                st.pop();
                long long  mul = v1 * v2;
                st.push(mul);
            }
            else if(tokens[i] == "/"){
                int v1 = st.top();
                st.pop();
                int v2 = st.top();
                st.pop();
                int div = v2 / v1;
                st.push(div);
            }
        }
    }


    evaluate = st.top();

}
    int evalRPN(vector<string>& tokens) {

        int evaluate = 0;

        solve(tokens , evaluate);

        return evaluate;
        
    }
};