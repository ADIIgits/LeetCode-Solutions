class Solution {
    public static void permutation(int[] nums, List<List<Integer>> ans,List<Integer> list, boolean[] visited){
        if(list.size()==nums.length){
            ans.add(new ArrayList<>(list));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if(visited[i]) continue;
            visited[i]=true;
            list.add(nums[i]);
            permutation(nums,ans,list,visited);
            list.remove(list.size()-1);
            visited[i]=false;
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        permutation(nums,ans,list,visited);
        return ans;
    }
}