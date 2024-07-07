struct Trie{
    bool isend;
    int cost;
    Trie* child[26]={nullptr};
    Trie():isend(false),cost(INT_MAX){};
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        
        Trie* head=new Trie;
        vector<int> dp(target.size(),-1);
        for(int i=0;i<words.size();i++){
            string &s=words[i];
            Trie* temp=head;
            for(char c:s){
                int z=c-'a';
                if(!temp->child[z]){
                    temp->child[z]=new Trie();
                }
                temp=temp->child[z];
            }
            temp->isend=true;
            temp->cost=min(temp->cost,costs[i]);
        }
        
       function<int(int)> solve=[&](int i)->int{
            if(i>=target.size())return 0;
            
            if(dp[i]>=0) return dp[i];
            Trie* node=head;
            int ans=INT_MAX;
            for(int j=i;j<target.size();j++){
                int z=target[j]-'a';
                if(!node->child[z]) return dp[i]=ans;
                if(node->child[z]->isend && node->child[z]->cost<ans){ 
                    int next=solve(j+1);
                    int val= next==INT_MAX? INT_MAX:node->child[z]->cost+next;
                    ans=min(ans,val);
                }
                node=node->child[z];
            }
            return dp[i]=ans;
        };
        for(int i=target.size()-1;i>=0;i--)
            solve(i);
        return solve(0)==INT_MAX? -1:solve(0);
    }
};