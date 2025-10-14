class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        if(n<m) return false;
        int[] freq = new int[26];
        int[] windowfreq = new int[26];
        for(int i=0;i<m;i++){
            freq[s1.charAt(i)-'a']++;
            windowfreq[s2.charAt(i)-'a']++;
        }
        for(int i=0;i<=n-m;i++){
            int j=0;
            for(j=0;j<26;j++){
                if(freq[j]==windowfreq[j]) continue;
                else break;
            }
            if(j>=26) return true;
            windowfreq[s2.charAt(i)-'a']--;
            if(i<n-m)
            windowfreq[s2.charAt(i+m)-'a']++;
        }
        return false;
    } 
}