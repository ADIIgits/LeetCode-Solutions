class Solution {
    public String longestCommonPrefix(String[] strs) {
        int n = strs.length; String prev=strs[0]; String st="";
        for(String word: strs)
        {
            int m = word.length();
            int mins = Math.min(m,prev.length());
            int k=0;
            while(k<mins){
                if(word.charAt(k)==prev.charAt(k)){
                st+=word.charAt(k)+""; k++;}
                else{
                break;}
            }
            System.out.println(st);
            prev=st;
            st="";
            
        }
        return prev;
    }
}