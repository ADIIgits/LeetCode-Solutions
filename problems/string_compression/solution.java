class Solution {
    public int compress(char[] chars) {
        int k=0; int n = chars.length;
        for(int i=0;i<n;i++){
            int j=i+1; int count=1;
            while(j<n && chars[j-1]==chars[j]){ count++; j++; }
            chars[k++] = chars[i];
            if(count>1){
                if(count<=9){
                    chars[k++] = (char) ('0'+count);
                } else {
                    String s = count+"";
                    for(int p=0;p<s.length();p++){
                        chars[k++] = (char) s.charAt(p);
                    } 
                }
                i=j-1; 
            }

        }
        return k;
    }
}