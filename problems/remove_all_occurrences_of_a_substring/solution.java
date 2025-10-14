class Solution {
    public static int foundOccurence(String haystack, String needle){
        int base=256; int mod = 121; int h=1;
        
        int n=haystack.length(); int m = needle.length();
        if((n<=0) || (m<=0) || (n<m)) return -1;
        //calcing base^m-1
        for(int i=0;i<m-1;i++){
            h=(h*base)%mod;
        }
        int haystackhash=0; int needlehash=0;
        //calcing first window and needle
        for(int i=0;i<m;i++){
            haystackhash = (haystackhash*base + haystack.charAt(i))%mod;
            needlehash = (needlehash*base + needle.charAt(i))%mod;
        }
        //rolling hash
        for(int i=0;i<=n-m;i++){
            if(haystackhash == needlehash && haystack.substring(i,i+m).equals(needle)) return i;
            if(i<n-m){
                haystackhash = ((haystackhash - haystack.charAt(i)*h )*base + haystack.charAt(i+m))%mod;
                haystackhash = (haystackhash+mod)%mod;
            }
        }
        return -1;

    }
    public static String findAndremoveOccurence(String s,int pos,String part){
        int n = s.length();
        int m = part.length();
        return s.substring(0,pos) + s.substring(pos+m,n);
        
    }
        
    public String removeOccurrences(String s, String part) {
        
        int p = foundOccurence(s,part);
        while(s.length()>0 && p!=-1){
            s = findAndremoveOccurence(s,p,part);
            p = foundOccurence(s,part);
        }
        return s;
    }
}