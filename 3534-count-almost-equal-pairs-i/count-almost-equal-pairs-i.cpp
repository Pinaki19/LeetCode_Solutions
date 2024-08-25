class Solution {
public:
    int countPairs(vector<int>& nums) {
        int c = 0;
        int n = nums.size();
        vector<string> vs;
        for(int i:nums){
            string is=to_string(i);
            string rest="";
            for(int i=0;i<10-is.size();i++)
                rest+='0';
            vs.push_back(rest+is);
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[i]=vector<int>(10,0);
            for(char c:vs[i]){
                int t=c-'0';
                mp[i][t]++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    c++;
                    continue;
                }
                int d=0;
                int p1=-1,p2=-1;
                for(int p=0;p<10;p++){
                    if(vs[i][p]!=vs[j][p]){
                       d++;
                       if(p1==-1)
                        p1=p;
                        else
                        p2=p;
                    }
                    
                }
                if(d==2){
                    string t=vs[i];
                    swap(t[p1],t[p2]);
                    if(t==vs[j])
                        c++;
                }
            }
        }
        
        return c;
    }
};