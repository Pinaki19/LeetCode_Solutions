class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios_base::sync_with_stdio(0);
        multiset<int> ms;
        for(int i:hand) 
            ms.insert(i);
        
        while(ms.size()){
            int val=*ms.begin();
            ms.erase(ms.find(val));

            for(int i=1;i<groupSize;i++){
                if(ms.find(val+i)==ms.end()) return false;
                ms.erase(ms.find(val+i));
            }
        }
        return 1;
    }
};