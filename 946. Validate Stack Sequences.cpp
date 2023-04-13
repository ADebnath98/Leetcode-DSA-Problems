class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> st;
        int n=pushed.size();
        int j=0;
        for(int i=0;i<n;){
            if(pushed[i]==popped[j]){
                while(i<n&&pushed[i]==popped[j]){
                i++;
                j++;
                }
            }
            else if(!st.empty()&&st.top()==popped[j]){
                while(j<n&&!st.empty()&&st.top()==popped[j]){
                    st.pop();
                    j++;
                }
            }
            else{
                st.push(pushed[i++]);
            }
        }
        while(!st.empty()&&j<n){
            cout<<st.top()<<popped[j]<<'\n';
            if(st.top()!=popped[j]){
                return false;
            }
            j++;
            st.pop();
        }

    return true;
    }
};