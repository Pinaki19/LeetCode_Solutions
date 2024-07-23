class Mycomp implements Comparator<Integer>{
    int[] freq;
    Mycomp(int[] f){
        freq=f;
    }
    public int compare(Integer i1,Integer i2){
        if(freq[i1+100]==freq[i2+100]){
            return (int)Math.signum(i2-i1);
        }
        return (int)Math.signum(freq[i1+100]-freq[i2+100]);
    }
};
class Solution {
    public int[] frequencySort(int[] nums) {
        int[] freq=new int[202];
        Arrays.fill(freq,0);
        List<Integer> al=new ArrayList<>();
        for(int i:nums){
            freq[i+100]++;
            al.add(i);
        }
        al.sort(new Mycomp(freq));
        return al.stream().mapToInt(i->i).toArray();
    }
}