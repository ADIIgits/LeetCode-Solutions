class Solution {
    public int strStr(String haystack, String needle) {
        int he = haystack.length();
        int ne = needle.length();
        int base = 256; int mod = 101; int h=1;
        if(he<ne) return -1;
        
        int needleHash = 0; int haystackHash = 0;
        for(int i=0;i<ne-1;i++){
            h=(h*base)%mod;
        }
        for(int i=0;i<ne;i++){
            needleHash = (needleHash * base + needle.charAt(i))%mod;
            haystackHash = (haystackHash * base + haystack.charAt(i))%mod;
        }
        
        for(int i = 0; i<=he-ne;i++){
            System.out.print(haystackHash+":"+needleHash+"  ");
            if(haystackHash == needleHash && haystack.substring(i,i+ne).equals(needle)){
                return i;
            }
            if(i<he-ne){
                haystackHash = (base*(haystackHash - haystack.charAt(i)*h) + haystack.charAt(i+ne))%mod;
                haystackHash = (haystackHash + mod)%mod;
            }
        }
        return -1;
    }
}