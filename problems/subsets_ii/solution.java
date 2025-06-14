class Solution {
    public static void subs(int[] arr,List<Integer> current,List<List<Integer>> allSubsets, int i){
        if(i==arr.length){
            allSubsets.add(new ArrayList(current));
            return;
        }
        
        current.add(arr[i]);
        subs(arr,current,allSubsets,i+1);
        current.remove(current.size()-1);
        int idx=i+1;
        while(idx<arr.length && arr[idx]==arr[idx-1]){
            idx++;
        }
        subs(arr,current,allSubsets,idx);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<List<Integer>> allSubsets = new ArrayList<>();
        List<Integer> current = new ArrayList<>();
 
        Arrays.sort(nums);
        subs(nums,current,allSubsets,0);
        return allSubsets;
    }
}