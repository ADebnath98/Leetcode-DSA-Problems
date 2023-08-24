class Solution {
public:
    string multiply(string s, string t) {
        vector<int> v(s.length()+t.length(),0);
        if(s=="0"||t=="0")
        return "0";
        for(int i=t.length()-1;i>=0;i--)
        {
            for(int j=s.length()-1;j>=0;j--)
            {
                int a,b;
                a=t[i]-'0';
                b=s[j]-'0';
                v[i+j+1]+=a*b;
            }
        }
        int c=0;
        string l="";
        for(int i=v.size()-1;i>=0;i--)
        {
            v[i]+=c;
            c=v[i]/10;
            l.push_back((v[i]%10)+'0');
        }
        for(int i=l.length()-1;i>=0;i--)
        {
            if(l[i]!='0')
            break;
            l.pop_back();
        }
        reverse(l.begin(),l.end());
        return l;
    }
};