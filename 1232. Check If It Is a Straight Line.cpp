class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int points=coordinates.size();
        int x_diff=(coordinates[1][0]-coordinates[0][0]);
        int y_diff=(coordinates[1][1]-coordinates[0][1]);

        int curr_x_diff,curr_y_diff;
        for(int i=2;i<points;i++)
        {
            curr_x_diff=(coordinates[i][0]-coordinates[i-1][0]);
            curr_y_diff=(coordinates[i][1]-coordinates[i-1][1]);
            if(y_diff*curr_x_diff !=x_diff*curr_y_diff)
                    return false;
        }
            return true;
    }
};