class Solution {
    public static void getsubs(int[] nums,List<List<Integer>> ans,List<Integer> list,int i){
        if(i==nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        list.add(nums[i]);
        getsubs(nums,ans,list,i+1);
        list.remove(list.size()-1);
        getsubs(nums,ans,list,i+1);

    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        getsubs(nums,ans,list,0);
        return ans;
    }
}