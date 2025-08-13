class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        int rows = matrix.length;
        int cols = matrix[0].length;
        int startrow = 0; int startcol = 0; int endcol = cols-1;
        int endrow = rows-1;
        while(startrow<=endrow && startcol<=endcol){
            //top
            for(int i=startcol;i<=endcol;i++){
                ans.add(matrix[startrow][i]);
            }
            //right
            for(int i=startrow+1;i<=endrow;i++){
                ans.add(matrix[i][endcol]);
            }
            //bottom
            for(int i=endcol-1;i>=startcol;i--){
                if(startrow==endrow) break;
                ans.add(matrix[endrow][i]);
            }
            //left
            for(int i=endrow-1;i>startrow;i--){
                if(startcol==endcol) break;
                ans.add(matrix[i][startcol]);
            }
            startcol++; endcol--;
            startrow++; endrow--;
        }
        return ans;
    }
}