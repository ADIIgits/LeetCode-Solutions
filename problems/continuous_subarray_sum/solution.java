class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer,Integer> map = new HashMap<>();
        //we wanna check, if (prefix[j]-prefix[i-1])%k==0 or not
        //(a-b)%k==0 is same as a%k - b%k == 0, thus a%k = b%k
        //thus, we wanna check if prefix[j]%k==0 && prefix[i-1]%k==0, we are looking for duplicate pair of remainders.
        int[] prefix = new int[n]; int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            prefix[i]=sum;
        }
        map.put(0,-1);
        for(int i=0;i<n;i++){
            int rem = prefix[i]%k;
            //prefix[i] holds sum of array till i.
            //so if any prefix[i]%k==0, it means subarray from 0 to i is divisble by k, thats why we added (0,-1) in map
            if(map.containsKey(rem)){
                if(i-map.get(rem)>=2) return true;
            }
            else map.put(rem,i);
        }
        return false;
    }
}