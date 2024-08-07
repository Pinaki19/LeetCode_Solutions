class TrieNode{
public:
    bool isend=false;
    TrieNode* child[26]={nullptr};
    int cost=(int)1e6;
    //add anything necessary here

    static TrieNode* create(auto& words,auto& costs){
        TrieNode* head=new TrieNode();
        TrieNode* temp=head;
        for(int i=0;i<words.size();i++){    //index maybe useful
            string& s=words[i];
            temp=head;
            for(char c:s){
                int z=c-'a';
                if(!temp->child[z])
                    temp->child[z]=new TrieNode();
                temp=temp->child[z];
            }
            temp->isend=true;
            temp->cost= min(temp->cost,costs[i]);
        }
        return head;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        TrieNode* head=TrieNode::create(words,costs);
        int n=target.size();
        int dp[n];
        fill(dp,dp+n,-1);

        function<int(int)> solve=[&](int i)->int{
            if(i>=n) return 0;
             
            if(dp[i]>=0) return dp[i];
            int ans=INT_MAX;
            TrieNode* temp=head;
            for(int j=i;j<n;j++){
                int z=target[j]-'a';
                if(!temp->child[z]) break;
                if(temp->child[z]->isend){
                    int upto=temp->child[z]->cost;
                    int next=solve(j+1);
                    int total= next==INT_MAX? INT_MAX:upto+next;
                    ans=min(ans,total);
                }
                temp=temp->child[z];
            }

            return dp[i]=ans;
        };
        for(int i=n-1;i>=0;i--)
            solve(i);
        return solve(0)==INT_MAX? -1:solve(0);
    }
};