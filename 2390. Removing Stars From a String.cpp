class Solution {
public:
    string removeStars(string s) {
        s.push_back(999);
        int n= int(s.size());
        vector<int> order(n);

        int i = 0,cnt = 0;

        auto beg = order.begin();
        auto end = beg;
        

        while(i < n) {
            *end = s[i];
            if(s[i] == '*'){
                cnt++;
            }else if(cnt){
                end = end - cnt * 2;
                cnt = 0;
                continue;
            }
            i++;
            end++;
        }
        return string(beg,end-1);
    } 
};