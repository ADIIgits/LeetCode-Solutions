class Solution {
    public static void subset(int[] arr, List<Integer> current, List<List<Integer>> subs,int i){
        if(i==arr.length){
            subs.add(new ArrayList(current));
            return;
        }
        
        current.add(arr[i]);
        subset(arr,current,subs,i+1);
        current.remove(current.size()-1);
        subset(arr,current,subs,i+1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<Integer> current = new ArrayList<>();
        List<List<Integer>> subs = new ArrayList<>();
        subset(nums,current,subs,0);
        return subs;
    }
}