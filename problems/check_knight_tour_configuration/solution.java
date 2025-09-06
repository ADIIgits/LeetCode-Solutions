class Solution {
    public static boolean check(int[][] grid,int row,int col,int curr){
        int n = grid.length;
        if(row<0 || col<0) return false;
        if(row>=n || col>=n) return false;

        if(grid[row][col]==n*n-1) return true;

        int r=row-2; int c = col-1;

        if(r>=0 && c>=0 && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row-2; c=col+1;
        if(r>=0 && c<n && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row+2; c=col-1;
        if(r<n && c>=0 && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row+2; c=col+1;
        if(r<n && c<n && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row-1; c=col-2; 
        if(r>=0 && c>=0 && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row-1;c=col+2;
        if(r>=0 && c<n && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row+1;c=col-2;
        if(r<n && c>=0 && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        r=row+1;c=col+2;
        if(r<n && c<n && grid[r][c]==curr+1){
            curr=grid[r][c];
            return check(grid,r,c,curr);
        }
        return false;
    }
    public boolean checkValidGrid(int[][] grid) {
        int n = grid.length;
        if(grid[0][0]!=0)return false;
        return check(grid,0,0,0);
       

    }
}