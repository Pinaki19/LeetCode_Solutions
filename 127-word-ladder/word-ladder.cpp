class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        bool exists=false;
        int startind=-1;
        int endind=-1;
        for(int i=0;i<n;i++){
            string& word=wordList[i];
            if(word==endWord)
                endind=i;
            if(word==beginWord){
                exists=true;
                startind=i;
            }
        }
        if(endind==-1||startind==endind) return 0;
        if(!exists){
            startind=n;
            n++;
            wordList.push_back(beginWord);
        }

        map<string,int> mp;
        for(int i=0;i<wordList.size();i++)
            mp[wordList[i]]=i;

        queue<int> q;
        vector<bool> visited(n,false);
        visited[startind]=true;
        q.push(startind);
        int ans=0;
        while(!q.empty()){
            int len=q.size();
            ans++;
            for(int i=0;i<len;i++){
                int ind=q.front();
                q.pop();
                if(ind==endind) return ans;
                for(int j=0;j<wordList[ind].size();j++){
                    char p=wordList[ind][j];
                    for(char c='a';c<='z';c++){
                        if(c==p) continue;
                        wordList[ind][j]=c;
                        if(mp.find(wordList[ind])!=mp.end()){
                            int nind=mp[wordList[ind]];
                            if(!visited[nind]){
                                q.push(nind);
                                visited[nind]=true;
                            }
                        }
                    }
                    wordList[ind][j]=p;
                }
            }
        } 
        return 0;
    }
};