class Solution {
    public static String reverse(String s){
        int n = s.length();
        String newstr="";
        for(int i=0;i<n;i++){
            newstr+=s.charAt(n-i-1);
        }
        return newstr;
    }
    public String reverseWords(String s) {
        int n = s.length();
        String revstr = reverse(s);
        String anstr="";

        for(int i=0;i<n;){
            int j=i;
            while(j<n && Character.isLetterOrDigit(revstr.charAt(j))) j++;
            if(j>i){
                String revword = reverse(revstr.substring(i,j));
                anstr+=" "+revword;
                i=j;
                continue;
            }
            i++;
        }

        

        return anstr.substring(1);
    }
}