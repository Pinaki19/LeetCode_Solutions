class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double total_wait=0;
        int prev=0;
        for(auto c:customers){
            int start=c[0],time=c[1];
            int wait=0;
            if(start<=prev)
                wait+=prev-start;
            
            total_wait+=wait;;
            total_wait+=time;
            prev=start+time+wait;
        }
        return total_wait/customers.size();
    }
};