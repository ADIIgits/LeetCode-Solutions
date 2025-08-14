class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        List<List<Integer>> ansArray = new ArrayList<>();
        
        for(int i=0;i<n-1;i++){
            int st=i+1; int ed=n-1;
            if(i>0 && nums[i]==nums[i-1]) continue;

            while(st<ed){
                int sum = nums[i]+nums[st]+nums[ed];
                List<Integer> subarray = new ArrayList<>();
                if(sum==0){
                    subarray.add(nums[i]);
                    subarray.add(nums[st]);
                    subarray.add(nums[ed]);

                    ansArray.add(subarray);
                    

                    while(st<n-1 && nums[st]==nums[st+1]) st++;
                    while(ed<n-1 && nums[ed]==nums[ed-1]) ed--;
                    st++; ed--;
                    continue;
                }
                if(sum<0) st++;
                else ed--;

            }

        }
        return ansArray;
    }
}