class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int n = grid.length;
        HashSet<Integer> cache = new HashSet<>();
        int repeating = -1; int missing = -1;
        int orgSum = 0; int arrSum = 0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                
                arrSum+=grid[i][j];
                if(cache.contains(grid[i][j])){
                    repeating = grid[i][j];
                }
                cache.add(grid[i][j]);
            }   
        }
        orgSum = (n*n*(n*n + 1))/2;
        missing = orgSum - (arrSum - repeating);
        return new int[]{repeating,missing};
    }
}