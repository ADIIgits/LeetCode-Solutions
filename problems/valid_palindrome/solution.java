class Solution {
    
    public boolean isPalindrome(String s) {
        int n = s.length();
        int p = 0; int q=n-1;
        while(p<q){
            if(!Character.isLetterOrDigit(s.charAt(p))){
                p++; continue;
            }
            if(!Character.isLetterOrDigit(s.charAt(q))){
                q--; continue;
            }

            if(Character.toLowerCase(s.charAt(p)) == Character.toLowerCase(s.charAt(q))){
                p++;q--; continue;
            } else return false;
        }
        return true;
    }
}