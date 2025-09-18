class Solution {
    public static void generate(List<String> ans,int n,String s,int o,int c){
        if(s.length()==n*2){
            ans.add(s);

            return;
        }
        if(o<n)
        generate(ans,n,s+"(",o+1,c);
        if(c<o)
        generate(ans,n,s+")",o,c+1);
    }
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        generate(ans,n,"",0,0);
        
        return ans;
    }
}