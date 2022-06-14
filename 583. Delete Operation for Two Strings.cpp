class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size() ;
        int n = word2.size() ;
        
        // m+1 and n+1 is for empty string attached with word1 and word2 in dp table 
        vector<vector<int>> dp( m+1, vector<int>(n+1,0) );
        
        for( int i=1 ; i<m+1 ; i++ ){
            for( int j=1 ; j<n+1 ; j++ ){
                
                // if the letter is equal
                // just check the diagonal value in the dp table and add 1 to that value 
                if( word1[i-1] == word2[j-1] )
                    dp[i][j] = 1 + dp[i-1][j-1];
                
                // if the letter is not equal
                // take the maximum value of upward and leftmost value in the dp table 
                else 
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }
        // at the last row and column of the dp table you will get the number of common characters
        // subtract the common characters from size of word1 and word2, and add 
        return m-dp[m][n] + n-dp[m][n] ;
    }
};