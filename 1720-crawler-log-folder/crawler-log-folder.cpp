class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;

        for(string& log:logs){
            if(log.size()>2 && log[0]=='.'){
                if(log[1]=='.')
                    ans=max(ans-1,0);
            }
            else if(log[0]!='.') ans++;
        }

        return ans;
    }
};