class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,int> mp,col;
        for(auto& q:queries){
            int num=q[0],color=q[1];
            if(col.find(num)!=col.end()){
                int prev=col[num];
                mp[prev]-=1;
                if(mp[prev]==0)
                    mp.erase(prev);
            }
            col[num]=color;
            mp[color]+=1;
            ans.push_back(mp.size());
        }
        return ans;
    }
};