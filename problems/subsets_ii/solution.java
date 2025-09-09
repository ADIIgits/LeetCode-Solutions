class Solution {
    public static void subs(int[] nums,List<List<Integer>> ans,List<Integer> list,boolean[] visited,int i){
        int n = nums.length;
        if(i==nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        list.add(nums[i]);
        subs(nums,ans,list,visited,i+1);
        list.remove(list.size()-1);
        int idx = i+1;
        while(idx<n && nums[idx-1]==nums[idx]){
            idx++;
        }
        subs(nums,ans,list,visited,idx);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        boolean[] visited = new boolean[n]; 
        Arrays.sort(nums);
        subs(nums,ans,list,visited,0);
        return ans;

        
    }
}