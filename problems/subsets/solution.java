class Solution {
    public static void subsets(int[] nums,List<List<Integer>> ans,List<Integer> list,int i){
        if(i==nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        list.add(nums[i]);
        subsets(nums,ans,list,i+1);
        list.remove(list.size()-1);
        subsets(nums,ans,list,i+1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        subsets(nums,ans,list,0);
        return ans;
    }
}