class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        regex rgx1("[a-z0-9]+/.*$"),rgx2("\\.\\./");
        for(string& log:logs){
            if(regex_match(log,rgx1))
                ans++;    
            else if(regex_match(log,rgx2))
                ans=max(ans-1,0);
        }

        return ans;
    }
};