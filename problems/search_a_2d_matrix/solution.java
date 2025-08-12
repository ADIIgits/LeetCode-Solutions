class Solution {
    public static boolean bsearch(int[][] matrix, int midrow,int cols,int target){
        int st=0; int ed = cols-1;
        while(st<=ed){
            int midc = st + (ed-st)/2;
            if(matrix[midrow][midc]==target) return true;
            if(matrix[midrow][midc]<target) st = midc+1;
            else ed = midc-1;
        }
        return false;
    }
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length; int cols = matrix[0].length;
        int st = 0; int ed = rows-1;
        while(st<=ed){
            int midrow = st + (ed-st)/2;
            if(matrix[midrow][0]<=target && target<=matrix[midrow][cols-1]){
                return bsearch(matrix,midrow,cols,target);  
            }

            if(target<matrix[midrow][0])
            ed=midrow-1;
            if(target>matrix[midrow][cols-1])
            st=midrow+1;
        }
        return false;
    }
}