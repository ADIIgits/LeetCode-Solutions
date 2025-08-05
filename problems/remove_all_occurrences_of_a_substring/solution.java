class Solution {
    public static int foundOccurence(String s,String part){
        int sa = 0; int pa = 0; int se = s.length(); int pe = part.length();
        for(int i=0;i<=se-pe;i++){
            if(s.substring(i,i+pe).equals(part))
            return i;
        }
        return -1;
        
    }
    public static String removeOcc(String s, String part, int pos){
        String news = "";
        news+=s.substring(0,pos);
        news+=s.substring(pos+part.length(),s.length());
        System.out.print(news+" ");
        return news;
    }
    public String removeOccurrences(String s, String part) {
        int p = foundOccurence(s,part);
        while(s.length()>0 && p!=-1){
            s = removeOcc(s,part,p);
            p = foundOccurence(s,part);
        } 
        return s;
    }
}