class Solution {
    public static String reverse(String word){
        String revword = "";
        for(int i=word.length()-1;i>=0;i--){
            revword+=word.charAt(i)+"";
        }
        return revword;
    }
    public String reverseWords(String s) {
        int slen = s.length();
        s=reverse(s);
        String ans = "";
        for(int i=0;i<slen;i++){
            String word = "";
            while(i<slen && s.charAt(i)!=' '){
                word+=s.charAt(i)+"";
                i++;
            }
            word = reverse(word);
            if(word.length()>0)
            ans+=" "+word;
        }
        return ans.substring(1,ans.length());
        
    }
}