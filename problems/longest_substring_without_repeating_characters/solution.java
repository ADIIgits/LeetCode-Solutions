class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n<1) return 0;
        if(n==1) return 1;
        int p=0; int q=0;
        int max=Integer.MIN_VALUE;
        ArrayList<Character> ch = new ArrayList<>();
        while(q<n)
        {
            char c = s.charAt(q);
            if(!ch.contains(c)){
            ch.add(c); q++;}
            else{
                if(ch.size()>max)
                max=ch.size();
                p++; q=p;
                ch.clear();
            }
        }
        if(ch.size()>max)
        max=ch.size();
        
        return max;
    }
}