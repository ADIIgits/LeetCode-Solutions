class Solution {
    public static ArrayList<Character> close(char b,ArrayList<Character> stack){
        if(stack.isEmpty()){
            stack.add(b);
            return stack;
        }
        char a = stack.get(stack.size()-1);
        if(a=='(' && b==')')
        {
            stack.remove(stack.size()-1);
        }
        else if(a=='{' && b=='}')
        {
            stack.remove(stack.size()-1);
        }
        else if(a=='[' && b==']')
        {
            stack.remove(stack.size()-1);
        }
        else{
            stack.add(b);
        }
        return stack;
        
    }
    public boolean isValid(String s) {
        int n = s.length();
        ArrayList<Character> stack = new ArrayList<>();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='{' || s.charAt(i)=='[')
            stack.add(s.charAt(i));
            else
            stack = close(s.charAt(i),stack);
        }
        return stack.isEmpty();
    }
          
}