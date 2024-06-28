class Solution {
public:
    void getLcs(auto& s1,auto& s2,auto& ans){
        int n1=s1.size(),n2=s2.size();
        int dp[n1+1][n2+1];
        for(int i=0;i<=n1;i++)
            dp[i][0]=0;
        for(int i=0;i<=n2;i++)
            dp[0][i]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]+1});
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int i=n1,j=n2;
        ans.clear();
        while(i>0 && j>0){
            if(dp[i][j]!=dp[i-1][j] && dp[i][j]!=dp[i][j-1]){
                ans+=s1[i-1];i--;j--;
            }else{
                if(dp[i][j]==dp[i-1][j]) i--;
                else j--;
            }
        }
        reverse(ans.begin(),ans.end());
    }
    string shortestCommonSupersequence(string str1, string str2) {
        ios_base::sync_with_stdio(0);
        string lcs="",ans="";
        getLcs(str1,str2,lcs);
        int i=0,j=0;
        int n1=str1.size(),n2=str2.size();
        if(lcs.empty())
            return str1+str2;
        int l=0;
        while(1){
            if(l>=lcs.size()){
                ans+=str1.substr(i)+str2.substr(j);
                break;
            }
            while(i<n1 && str1[i]!=lcs[l])
                ans+=str1[i++];
            while(j<n2 && str2[j]!=lcs[l])
                ans+=str2[j++];
            ans+=lcs[l++];
            i++;j++;
        }
        return ans;
    }
};