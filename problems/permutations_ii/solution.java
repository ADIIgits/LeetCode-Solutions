class Solution {
    public static void perm(int[] nums, List<List<Integer>> ans,List<Integer> list,boolean[] visited){
        int n = nums.length;
        if(list.size()==n){
            ans.add(new ArrayList<>(list));
            return;
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]) continue;

            visited[i]=true;
            list.add(nums[i]);
            perm(nums,ans,list,visited);
            list.remove(list.size()-1);
    
            perm(nums,ans,list,visited);
            visited[i]=false;

            while(i>=0 && i+1<n && nums[i]==nums[i+1]){
                i++;
            }

        }
    }
    public List<List<Integer>> permuteUnique(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        boolean[] visited = new boolean[n];
        perm(nums,ans,list,visited);
        return ans;
    }
}