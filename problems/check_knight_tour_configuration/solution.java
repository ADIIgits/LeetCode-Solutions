class Solution {
    public static boolean knightTour(int[][] grid,int row,int col){
        int n = grid.length;
        int curr = grid[row][col];
        if(grid[row][col]==n*n-1) return true;
        int r,c;
        r=row+2;c=col+1;
        if(r<n && c<n){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }
        r=row+2;c=col-1;
        if(r<n && c>=0){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }
        r=row-2;c=col+1;
        if(r>=0 && c<n){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }
        r=row-2;c=col-1;
        if(r>=0 && c>=0){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }



        r=row+1;c=col+2;
        if(r<n && c<n){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }
        r=row+1;c=col-2;
        if(r<n && c>=0){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }
        r=row-1;c=col+2;
        if(r>=0 && c<n){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }
        r=row-1;c=col-2;
        if(r>=0 && c>=0){
            if(grid[r][c]==curr+1) return knightTour(grid,r,c);
        }

        return false;

    }
    public boolean checkValidGrid(int[][] grid) {
        if(grid[0][0]!=0) return false;
        return knightTour(grid,0,0);
    }
}