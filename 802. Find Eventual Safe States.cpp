class Solution {
public:
    // return true when i node is safe otherwise false
    bool fn(vector<vector<int>>& graph,int i,vector<int> &safe){
        if(safe[i]==0)return 0; //return false if we know this node is non_safe
        safe[i]=2; // mark it to be under_exploration to avoid cyclic trap
        bool non_vis = 1; // this flag is to store if i node is part of a cycle , we set it to 0 when i node is part of a cycle
        for(int n:graph[i]){
            if(safe[n]==0 || (safe[n]==-1 && !(safe[n]=fn(graph,n,safe)))){
                return safe[i]=0; // return 0 , if (node is already known to be unsafe) or (if unexplored and we find it to be unsafe)
            }else if(safe[n]==2){
                non_vis=0; //if status of neighbour node is 2 then that means it under exploration and thus leading to cycle formation  
            }
        }
        return safe[i]=non_vis;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safe(graph.size(),-1);

//**safe array states {0->non_safe | -1->not_explored_yet | 1->safe_node | 2->under_exploration}**

        vector<int> ans;
        for(int i=0;i<graph.size();++i){
            if(safe[i]==1){ //if safe push to ans
                ans.push_back(i);
            }else if(safe[i]==-1 && fn(graph,i,safe)){ //if not explored ,then explore and store in ans if its safe
                ans.push_back(i);
            }
        }

        return ans;
    }
};