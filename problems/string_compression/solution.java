class Solution {
    public int compress(char[] chars) {
        int pos=0;
        if(chars.length==1) return 1;
        for(int i=0;i<chars.length;i++){
            int c=0;
            char ch = chars[i];
            while(i<chars.length && ch==chars[i]){
                c++;
                i++;
            }
            if(c==1){
                chars[pos++]=ch;
            } else {
                chars[pos++]=ch;
                String cchar = Integer.toString(c);
                for(int j=0;j<cchar.length();j++){
                    chars[pos++] = cchar.charAt(j);
                }
            }
            i--;
               
        }
        return pos;
    }
}