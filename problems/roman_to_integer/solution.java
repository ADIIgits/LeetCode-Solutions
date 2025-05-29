class Solution {
    public int romanToInt(String s) {
        String sarr[] = s.split("");
        HashMap<String,Integer> romans = new HashMap<>();
        romans.put("I",1);
        romans.put("V",5);
        romans.put("X",10);
        romans.put("L",50);
        romans.put("C",100);
        romans.put("D",500);
        romans.put("M",1000);
        int sum=0;int prev=0;
        for(String sa:sarr)
        {
            if(romans.get(sa)<=prev)
            sum+=romans.get(sa);
            else
            {
                sum-=prev;
                sum+=romans.get(sa)-prev;
            }
            prev=romans.get(sa);

        }
        return sum;
    }
}