class Solution {
    public:
    vector<int> getRow(int row) {
        
        if(row==0)
        return {1};
        
        vector<int> pre={1};
        for(int i=1;i<=row;i++)
        {
            vector<int> curr(i+1,0);
            curr[0]=1;
            curr[i]=1;
            int j=1;
            int k=0;
            int l=1;
            
            while(l<pre.size())
            {
                curr[j]=pre[k]+pre[l];
                l++;
                k++;
                j++;
            }
            
            pre=curr;
        }
        
        return pre;
    }
};