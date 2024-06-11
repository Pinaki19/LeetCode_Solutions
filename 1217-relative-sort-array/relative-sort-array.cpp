class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int time=1;
        unordered_map<int,int> mp;
        for(int i:arr2) mp[i]=time++;
        sort(arr1.begin(),arr1.end(),[&mp](int a,int b){
            if(a==b) return false;
            if(mp[a]==0 && mp[b] || mp[b]==0 && mp[a])
                return mp[a]==0? false:true;
            if(mp[a]==mp[b])
                return a<b;
            return mp[a]<mp[b];
        });
       
        return arr1;
    }
};