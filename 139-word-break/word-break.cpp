class TrieNode{
public:
    TrieNode* child[26]={nullptr};
    bool isEnd;
    TrieNode():isEnd(false) {}
};

class Solution {
public:
    bool solve(int i,auto& s,TrieNode* cur,TrieNode* head,auto& dp){
        if(i>=s.size()) return cur->isEnd;
        if(dp.find({i,cur})!=dp.end()) return dp[{i,cur}];
        int p=s[i]-'a';
        bool res=false;
        if(cur->isEnd)
            res=solve(i,s,head,head,dp);
        if(cur->child[p])
            res|=solve(i+1,s,cur->child[p],head,dp);
        return dp[{i,cur}]=res;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* head=new TrieNode();
        for(auto& s:wordDict){
            TrieNode* temp=head;
            for(char c:s){
                int p=c-'a';
                if(!temp->child[p])
                    temp->child[p]=new TrieNode();
                temp=temp->child[p];
            }
            temp->isEnd=true;
        }
        map<pair<int,TrieNode*>,bool> dp;
        return solve(0,s,head,head,dp);
    }
};