class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(string s:details){
            int age=s[11]-'0';
            age*=10;
            age+=s[12]-'0';
            ans+= age>60;
        }

        return ans;
    }
};