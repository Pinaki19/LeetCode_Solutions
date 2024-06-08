class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        long total=0;
        Set<Integer> s=new HashSet<>();
        int numZeroes=0;
        for(int i:nums){
            if(i%k==0){
                numZeroes++;
                if(numZeroes>1) return true;
                continue;
            }
            numZeroes=0;
            total+=i;
            int rem=(int)(total%k);
            if(total%k==0 || s.contains(rem)) return true;
            s.add(rem);
        }
        return false;
    }
}