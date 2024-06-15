class Solution {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        ArrayList<Integer[]> al=new ArrayList<>();
        for(int i=0;i<profits.length;i++)
            al.add(new Integer[] {capital[i],profits[i]});
        
        al.sort(new Comparator<Integer[]>(){
            public int compare(Integer[] a,Integer[] b){
                if(a[0]==b[0])
                    return a[1]-b[1];
                return a[0]-b[0];
            }
        });
        PriorityQueue<Integer> pq=new PriorityQueue<>(Comparator.reverseOrder());
        int i=0;
        while(i<al.size() && al.get(i)[0]<=w)
            pq.add(al.get(i++)[1]);

        while(k-->0){
            if(pq.isEmpty()) break;
            w+=pq.poll();
            while(i<al.size() && al.get(i)[0]<=w)
                pq.add(al.get(i++)[1]);
        }
        return w;
    }
}