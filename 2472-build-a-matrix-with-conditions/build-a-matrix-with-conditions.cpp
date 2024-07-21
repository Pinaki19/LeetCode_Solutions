class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>&cc) {
        vector<int> row_indeg(k,0),col_indeg(k,0);
        vector<vector<int>> row_next(k,vector<int>()),col_next(k,vector<int>());
        for(auto& v:rc){
            int u=v[0]-1,d=v[1]-1;
            row_indeg[d]++;
            row_next[u].push_back(d);
        }

        for(auto& v:cc){
            int l=v[0]-1,r=v[1]-1;
            col_indeg[r]++;
            col_next[l].push_back(r);
        }
        vector<int> r;
        unordered_map<int,int> c;
        queue<int> q;
        for(int i=0;i<k;i++)
            if(row_indeg[i]==0)
                q.push(i);
        while(q.size()){
            int val=q.front();q.pop();
            for(int i:row_next[val]){
                row_indeg[i]--;
                if(row_indeg[i]==0)
                    q.push(i);
            }
            r.push_back(val);
        }

        for(int i=0;i<k;i++)
            if(col_indeg[i]==0)
                q.push(i);
        int l=0;
        while(q.size()){
            int val=q.front();q.pop();
            for(int i:col_next[val]){
                col_indeg[i]--;
                if(col_indeg[i]==0)
                    q.push(i);
            }
            c[val]=l++;
        }

        if(r.size() !=k || c.size() !=k) return {};
        vector<vector<int>> ans(k,vector<int>(k,0));
        int i=0;
        while(i<k){
            int val=r[i];
            int ind=c[val];
            ans[i][ind]=val+1;
            i++;
        }
        return ans;
    }
};