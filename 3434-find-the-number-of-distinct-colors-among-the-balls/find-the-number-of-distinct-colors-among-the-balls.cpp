class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_set<int> cols;
        unordered_map<int,int> mp1,mp2;
        vector<int> ans;
        for(auto q:queries){
            int b=q[0],c=q[1];
            if(mp2.find(b)!=mp2.end()){
                int col=mp2[b];
                mp1[col]--;
                if(mp1[col]==0)
                    cols.erase(col);
            }
            cols.insert(c);
            mp2[b]=c;
            mp1[c]++;
            ans.push_back(cols.size());
        }
        return ans;
    }
};