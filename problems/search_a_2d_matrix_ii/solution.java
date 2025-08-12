class Solution {
    public static int bsearch(int[][] matrix,int rmid,int cols,int target){
        int cst = 0; int ced = cols-1;
        while(cst<=ced){
            int cmid = cst + (ced-cst)/2;
            if(matrix[rmid][cmid]==target) return cmid;
            if(matrix[rmid][cmid]<target) cst = cmid+1;
            else ced = cmid-1;
        }
        return -1;
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length; int cols = matrix[0].length;
        int rmid = 0;
        int cmid = cols-1;
        while(rmid>=0 && rmid<rows && cmid>=0 && cmid<cols){
            
            if(matrix[rmid][cmid]==target) return true;
            if(matrix[rmid][cmid]<target){
                rmid++;
            } else {
                cmid--;
            }
        }
        return false;
    }
}