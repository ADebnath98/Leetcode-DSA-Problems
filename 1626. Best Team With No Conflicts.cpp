class Solution {
public:
    bool static comp(pair<int,int> p1,pair<int,int> p2)
    {
        if(p1.second==p2.second)
        return p1.first<p2.first;
        return p1.second<p2.second;
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> v;
        for(int i=0;i<ages.size();i++)
        {
            v.push_back({scores[i],ages[i]});
        }
        sort(v.begin(),v.end(),comp);
       for(int i=0;i<scores.size();i++)
       scores[i]=v[i].first;
       return maxSumIS(scores);
    }
     int maxSumIS(vector<int> arr)
   {
       int n = arr.size();
    int i, j, max = 0;
    int msis[n];
    for ( i = 0; i < n; i++ )
        msis[i] = arr[i];
    for ( i = 1; i < n; i++ )
        for ( j = 0; j < i; j++ )
            if (arr[i] >=arr[j] &&
                msis[i] < msis[j] + arr[i])
                msis[i] = msis[j] + arr[i];

    for ( i = 0; i < n; i++ )
        if ( max < msis[i] )
            max = msis[i];
 
    return max;
  }
};