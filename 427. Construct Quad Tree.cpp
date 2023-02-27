/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
Node* buildQTree(int rS, int rE, int cS, int cE, vector<vector<int>> &grid){
    if(rS>rE or cS>cE) return NULL;
    int isLeaf=1;
    int value=grid[rS][cS];
    for(int r=rS;r<=rE;r++){
        for(int c=cS;c<=cE;c++){
            if(grid[r][c]!=value){
                isLeaf=0;
                break;
            }
        }
        if(!isLeaf) break;
    }
    if(isLeaf) return new Node(value,isLeaf);
    int rM=(rE+rS)/2;
    int cM=(cE+cS)/2;
    Node* one=buildQTree(rS,rM,cS,cM,grid);
    Node* two=buildQTree(rS,rM,cM+1,cE,grid);
    Node* three=buildQTree(rM+1,rE,cS,cM,grid);
    Node* four=buildQTree(rM+1,rE,cM+1,cE,grid);
    return new Node(0,0,one,two,three,four);
}
    Node* construct(vector<vector<int>>& grid) {
        int n=grid.size();
        return buildQTree(0,n-1,0,n-1,grid);
    }
};