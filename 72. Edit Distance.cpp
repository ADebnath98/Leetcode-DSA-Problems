class Solution {
public:
    int minDistance(string word1, string word2) {
        int v[word1.size()+1][word2.size()+1];
        for(int i=0; i<=word1.size(); i++){
            v[i][0]=i;
        }
        for(int j=0; j<=word2.size(); j++){
            v[0][j]=j;
        }
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
                v[i][j]=(word1[i-1]==word2[j-1])?min(v[i-1][j-1],min(v[i-1][j]+1,v[i][j-1]+1)):min(v[i-1][j-1]+1,min(v[i-1][j]+1,v[i][j-1]+1));
            }
        }
        return v[word1.size()][word2.size()];
    }
};72. Edit Distance
