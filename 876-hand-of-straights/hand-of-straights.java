class Solution {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        TreeMap<Integer,Integer> mp=new TreeMap<>();
        for(int i:hand){
            mp.put(i,mp.getOrDefault(i,0)+1);
        }

        while(mp.size()>0){
            Set s=mp.keySet();
            Iterator<Integer> it=s.iterator();
            int prev=-1;
            int n=groupSize;
            while(n>0 && it.hasNext()){
                n--;
                int val=it.next();
                if(val-prev>1&&prev!=-1) return false;
                if(mp.get(val)==1) it.remove();
                else{
                    mp.put(val,mp.get(val)-1);
                }
                prev=val;
            }
            if(n>0) return false;
        }
        return true;
    }
}