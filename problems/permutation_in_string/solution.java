class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int s1len = s1.length(); int s2len = s2.length();
        if(s1len>s2len) return false;
        int[] map1 = new int[26];
        int[] map2 = new int[26];
        for(int i=0;i<s1.length();i++){
            map1[s1.charAt(i)-'a']++;
            map2[s2.charAt(i)-'a']++;
        }
        
        for(int i=0;i<=s2len-s1len;i++){
            int j=0;
            for(j=0;j<26;j++){
                if(map1[j]!=map2[j]) 
                break; 
                else continue;
            }
            if(j>=26) return true;

            map2[s2.charAt(i)-'a']--;
            if(i<s2len-s1len)
            map2[s2.charAt(i+s1len)-'a']++;
        }
        return false;

    }
}