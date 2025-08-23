class Solution {
    public static void subsets(int[] nums,List<List<Integer>> ans,List<Integer> list,int i){
        if(i==nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        list.add(nums[i]);
        subsets(nums,ans,list,i+1);
        list.remove(list.size()-1);
        int idx = i+1;
        while(idx<nums.length && nums[idx-1]==nums[idx]) idx++;
        subsets(nums,ans,list,idx);

    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        Arrays.sort(nums);
        subsets(nums,ans,list,0);
        return ans;
    }
}