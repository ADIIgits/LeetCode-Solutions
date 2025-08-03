class Solution {
    public static void swap(char[] s,int p,int q){
        char temp = s[p];
        s[p]=s[q];
        s[q]=temp;
    }
    public void reverseString(char[] s) {
        int n = s.length;
        int p = 0; int q=n-1;
        while(p<=q){
            swap(s,p,q);
            p++; q--;
        }
    }
}