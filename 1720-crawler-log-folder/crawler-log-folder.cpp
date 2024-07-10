class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        regex rgx1("[a-z0-9]+/.*$"),rgx2("\\.\\./");
        for(string& log:logs){
            if(regex_match(log,rgx1)){
                ans++; 
                cout<<"rgx 1 "<<log;
            }
                
            else if(regex_match(log,rgx2)){
                cout<<"rgx 2 "<<log;
                ans=max(ans-1,0);
            }
                
        }

        return ans;
    }
};