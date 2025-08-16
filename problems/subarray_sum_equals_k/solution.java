class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        int p=0;
        for(int i=0;i<n;i++){
            p+=nums[i];
            nums[i]=p;
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==k){
                count++;
            }
            if(map.containsKey(nums[i]-k)){
                
                count+=map.get(nums[i]-k);
                // map.put(nums[i]-k,map.get(nums[i]-k)+1);
            }
            if(!map.containsKey(nums[i])){
                map.put(nums[i],0);
            }
            map.put(nums[i],map.get(nums[i])+1);
        }
        return count;
    }
}