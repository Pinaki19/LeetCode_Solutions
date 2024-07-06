class Solution {
public:
    int passThePillow(int n, int time) {
        n--;
        int num_cycles=time/n;
        int rem=time%n;
        if(num_cycles&1)
            return n-rem+1;
        else
            return rem+1;
        return -1;
    }
};