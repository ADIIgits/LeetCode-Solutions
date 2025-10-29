class Solution {
    
    public static void generate(int[] nums,List<List<Integer>> AllSubsets,List<Integer> subset,int i){
        int n = nums.length;
        if(i==n){
            AllSubsets.add(new ArrayList<>(subset));
            return;
        }
        subset.add(nums[i]);
        generate(nums,AllSubsets,subset,i+1);
        subset.remove(subset.size()-1);
        int idx = i+1;
        while(idx<n && nums[idx-1]==nums[idx]) idx++;
        generate(nums,AllSubsets,subset,idx);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> AllSubsets = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();
        generate(nums,AllSubsets,subset,0);
        return AllSubsets;

    }
}