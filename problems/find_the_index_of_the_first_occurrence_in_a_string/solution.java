class Solution {
    public int strStr(String haystack, String needle) {
        int n = haystack.length();
        int m = needle.length();
        if(n<m) return -1;
        int mod=121; int base = 256; int h=1;
        //calcing base^m-1
        for(int i=0;i<m-1;i++){
            h=(h*base)%mod;
        }
        int needleHash=0; int haystackHash=0;
        for(int i=0;i<m;i++){
            haystackHash = (haystackHash*base + haystack.charAt(i))%mod;
            needleHash = (needleHash*base + needle.charAt(i))%mod;
        }
        for(int i=0;i<=n-m;i++){
            System.out.print(haystackHash+":"+needleHash+"  ");
            if(haystackHash==needleHash && haystack.substring(i,i+m).equals(needle)) return i;
            if(i<n-m){
                haystackHash = ((haystackHash - haystack.charAt(i)*h)*base + haystack.charAt(i+m))%mod;
                haystackHash = (haystackHash + mod)%mod;
            }
        }
        return -1;
        
    }
}