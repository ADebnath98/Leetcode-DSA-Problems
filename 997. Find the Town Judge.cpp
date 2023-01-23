class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> m(n,vector<int>(n,0));
          int size = trust.size();
        for(int i=0;i<size;i++)
        {
            int row = trust[i][0] - 1;
            int col = trust[i][1] - 1;
            m[row][col] = 1; 
        }



        //finding the judge
        // 0 0 1
        // 0 0 1
        // 0 0 0
bool check = true;
bool temp = true;
        for(int i=0;i<n;i++)
        {
            check = true;
            for(int j=0;j<n;j++)
            {
                if(m[i][j] != 0)
                  {
                      check = false;
                      break;
                  }
            }
            if(check)
            {
                temp = true;
                for(int k=0;k<n;k++)
                {
                    if(m[k][i] == 0 && k != i)
                       temp = false;
                 }
                 if(temp)
                   return i+1;
            }
        }
        return -1;
    }
};




class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int a[n+1];
        for(int i=0;i<n+1;i++) a[i]=0;
        map<pair<int,int>,int> m;
        for(int i=0;i<trust.size();i++){
            a[trust[i][0]]=1;
            pair<int,int> p={trust[i][0],trust[i][1]};
            m[p]++;
        }
        //to find out which index is missing in trust
        int  k=-1;
        for(int i=1;i<n+1;i++){
            if(a[i]==0) k=i;
        } 
        //if every index is having second value, return -1
        if(k==-1) return k;
        //checking if every index forms a pair with town judge index
        for(int i=1;i<n+1&&i!=k;i++){
            pair<int,int> p={i,k};
            if(!m[p]) return -1;
        }
        return k;
    }
};