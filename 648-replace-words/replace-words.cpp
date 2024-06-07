
class TrieNode{
public:
    TrieNode* child[26]={nullptr};
    bool isEnd;
};
class Solution {
public:
    string matchSmallest(TrieNode* head,string& w){
        int matched=-1;
        TrieNode* temp=head;
        for(int i=0;i<w.length();i++){
            int t=w[i]-'a';
            if(temp->isEnd)
                return w.substr(0,i);
            if(!temp->child[t])
                return w;
            temp=temp->child[t];
        }
        return w;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        TrieNode* head=new TrieNode();
        TrieNode* temp;
        for(string s:dict){
            temp=head;
            for(int i=0;i<s.length();i++){
                int t=s[i]-'a';
                if(!temp->child[t])
                    temp->child[t]=new TrieNode();
                temp=temp->child[t];
            }
            temp->isEnd=true;
        }
        stringstream ss(sentence);
        string ans="",s;
        while(getline(ss,s,' ')){
            ans+=matchSmallest(head,s);
            ans+=" ";
        }
        ans.erase(ans.find_last_not_of(' ')+1);
        return ans;
    }
};