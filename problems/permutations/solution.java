class Solution {
    public static void swap(int[] nums,int a,int b){
        int temp = nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
    public static void permutation(int[] nums,List<List<Integer>>ans,int idx){
        if(idx==nums.length){
            List<Integer> newnums = new ArrayList<>();
            for(int k:nums){
                newnums.add(k);
            }
            ans.add(newnums);
            return;
        }
        for(int i=idx;i<nums.length;i++){
            
            swap(nums,idx,i);
            permutation(nums,ans,idx+1);
            swap(nums,idx,i);

        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        permutation(nums,ans,0);
        return ans;
    }
}