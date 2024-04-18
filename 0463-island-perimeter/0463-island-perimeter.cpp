class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
               if(grid[row][col]){
                int left=(col==0 ? 1: grid[row][col-1] == 0);
                int right=(col==m-1 ? 1: grid[row][col+1] == 0);
                int upper=(row==0 ? 1: grid[row-1][col] == 0);
                int down=(row==n-1 ? 1: grid[row+1][col] == 0);
                ans= ans+left+right+upper+down;
               } 
            }
        }
        return ans;
    }
};