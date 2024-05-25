class TrieNode{
public:
    TrieNode* child[26]={nullptr};
    bool isEnd;
    TrieNode():isEnd(false) {}
};
class Solution {
public:
    void solve(int i,string s,TrieNode* cur,TrieNode*head,auto& ans,string t){
        if(i>=s.size()){
            if(cur->isEnd)
                ans.push_back(t);
            return;
        }
        int p=s[i]-'a';
        if(cur->isEnd)
            solve(i,s,head,head,ans,t+" ");
        if(cur->child[p])
            solve(i+1,s,cur->child[p],head,ans,t+s[i]);
        else
            return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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

        vector<string> ans;
        solve(0,s,head,head,ans,"");
        return ans;

    }
};