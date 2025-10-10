class Solution {
    
    public boolean isPalindrome(String s) {
        int st=0; int ed=s.length()-1;
        while(st<=ed){
            char stch = s.charAt(st);
            char edch = s.charAt(ed);
            if(Character.isLetterOrDigit(stch)){
                if(Character.isLetterOrDigit(edch)){
                    if(Character.toLowerCase(stch)!=Character.toLowerCase(edch)) return false;
                    else st++;ed--;
                } else ed--;
            } else st++;

        }
        return true;
    }
    
}