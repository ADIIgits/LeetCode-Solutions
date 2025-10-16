class Solution {
    public static void generate(int[] nums, List<List<Integer>> allsubsets, List<Integer> subset,int i){
        int n = nums.length;
        if(i==n){
            allsubsets.add(new ArrayList<>(subset)); return;
        }
        subset.add(nums[i]);
        generate(nums,allsubsets,subset,i+1);
        subset.remove(subset.size()-1);
        int j=i;
        while(j<n && nums[i]==nums[j]) j++;
        generate(nums,allsubsets,subset,j);

    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> allsubsets = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();
        generate(nums,allsubsets,subset,0);
        return allsubsets;

    }
}