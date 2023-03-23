Intuition
from the quesion , we can say we need to find the count of group of computer which are not connected to any other computer ( they may connected in group but does not coonected to another group)

Also we require to count wires, that are availble ,
number of wire can be easly find by given number of connection

int m = con.size();
Approach
To start solving quetion , we need to know , which computer is connected to which one , in short we need a adjency list

let's create adjency list.......

vector<int> adj[n];
  for(auto a : con){
    adj[a[0]].push_back(a[1]);
    adj[a[1]].push_back(a[0]);
  }
once we have adjency list we can use DFS to travell along all the computer that are connected to each other.
As we have N numbers of computer , let's make a array that will tell use given index of computer is visted or not , if a computer is vister that mean have already counted it.

vector<int> vis(n,0);
Here comes main concept .. if i start to travell from a computer at index 0 , i can travell along all the computers that are directly or indirectly connected to index 0 computer , while traversing we will mark as visted so that we are not come to visit any computer again.

Once a group of compter visted and marked as visted , we will try to find another group of computer that are not visted , repeating this process we can find numbers of group of computer that are not connected.

int c=0;
for(int i =0; i<n;i++){
  if(!vis[i]){
    c++;
    dfs(adj,vis,i);
  }
}
here is our DFS fuction

void dfs(vector<int> adj[] , vector<int> &vis , int i){
  vis[i]=1;
  for(auto a : adj[i]){
    if(!vis[a]){
      dfs(adj,vis,a);
    }
  }
}
At last we will check either number of wire is more that our requirement , to connect N numbers of computer we needd atleast N-1 wires , here "m" is numbers of wires .

if(m>=n-1) return c-1;
return -1;
Complexity
Time complexity:
O(N)

Space complexity:
O(N)


class Solution {
public:

    void dfs(vector<int> adj[] , vector<int> &vis , int i){
        vis[i]=1;
        for(auto a : adj[i]){
            if(!vis[a]){
                dfs(adj,vis,a);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(auto a : con){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        int c=0;
        int m = con.size();
        for(int i =0; i<n;i++){
            if(!vis[i]){
                c++;
                dfs(adj,vis,i);
            }
        }
        if(m>=n-1) return c-1;
        return -1;
    }
};