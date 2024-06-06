class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        set<int> s;
        for(int i:hand) {
            mp[i]++;
            s.insert(i);
        }
        while(s.size()){
            int val=*s.begin();
            mp[val]--;
            if(mp[val]==0)
                s.erase(val);

            for(int i=1;i<groupSize;i++){
                if(s.find(val+i)==s.end()) return false;
                int t=val+i;
                mp[t]--;
                if(mp[t]==0) s.erase(t);
            }
        }
        return 1;
    }
};