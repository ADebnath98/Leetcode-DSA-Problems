#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
class Solution {
public:
	int numFactoredBinaryTrees(vector<int>& arr) {
		unordered_map<int,long int> dp;
		int len=arr.size();

		// Sorting array
		sort(arr.begin(), arr.end());

		for(int i=0;i<len;i++){
			// One tree is always possible (root only)
			dp[arr[i]] = 1;

			// Check for all elements less than current element arr[i]
			for(int j=0; j<i; j++){
				// Check if arr[j] is factor of arr[i] 
				// and the second factor (arr[i]/arr[j]) is seen
				if(arr[i]%arr[j]==0 && dp.find((arr[i]/arr[j]))!=dp.end()){
					// Add combinations in dp with arr[j] as left child
					// So (arr[i]/arr[j]) becomes right child automatically
					dp[arr[i]] += (dp[arr[j]] * dp[(arr[i]/arr[j])]) % MOD;
					dp[arr[i]] %= MOD;
				}
			}
		}
		
		int ans=0;
		// Find sum of dp to sum solution of all subproblems
		for(auto i : dp){
			ans += i.second;
			ans %= MOD;
		}
		return ans;
	}
};

int main() {
  vector<int> arr = {2,5,10,20};
  Solution *sol = new Solution();
  cout<<sol->numFactoredBinaryTrees(arr)<<endl;
}