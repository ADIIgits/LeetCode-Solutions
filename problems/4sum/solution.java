class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Arrays.sort(nums); int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                
                int start = j+1; int end = n-1;
                while(start<end){
                    long sum = (long) nums[i]+nums[j]+nums[start]+nums[end];
                    if(sum==target){
                        List<Integer> subarr = new ArrayList<>();
                        subarr.add(nums[i]);
                        subarr.add(nums[j]);
                        subarr.add(nums[start]);
                        subarr.add(nums[end]);
                        
                        ans.add(subarr);
                        while(start<end && nums[start]==nums[start+1]) start++;
                        while(start<end && nums[end]==nums[end-1]) end--;
                        start++; end--;
                        continue;
                    }
                    if(sum<target) start++;
                    else end--;
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
            }
            


        }
        
        return ans;
    }
}