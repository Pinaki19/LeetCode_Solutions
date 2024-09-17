class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string t;
        set<string> stringSet;
        stringstream ss(s1+" "+s2);
        
        set<string> exclude;
        while(ss>>t){
            if(exclude.find(t)==exclude.end()){
                if(stringSet.find(t)!=stringSet.end()){
                    stringSet.erase(t);
                    exclude.insert(t);
                }else
                    stringSet.insert(t);
            }
        }
        vector<string> answer(stringSet.begin(),stringSet.end());
        return answer;
    }
};