class TrieNode{
    TrieNode[] child=new TrieNode[26];
    boolean isEnd;
}

class Solution {
    String matchSmallest(TrieNode head,String w){
        int matched=-1;
        TrieNode temp=head;
        for(int i=0;i<w.length();i++){
            int t=(int)w.charAt(i)-(int)'a';
            if(temp.isEnd)
                return w.substring(0,i);
            if(temp.child[t]==null)
                return w;
            temp=temp.child[t];
        }
        return w;
    }
    public String replaceWords(List<String> dict, String sentence) {
        TrieNode head=new TrieNode();
        TrieNode temp;
        for(String s:dict){
            temp=head;
            for(int i=0;i<s.length();i++){
                int t=(int)s.charAt(i)-(int)'a';
                if(temp.child[t]==null)
                    temp.child[t]=new TrieNode();
                temp=temp.child[t];
            }
            temp.isEnd=true;
        }
        String[] words=sentence.split(" ");
        String ans="";
        for(int i=0;i<words.length;i++){
            ans+= matchSmallest(head,words[i]);
            if(i!=words.length-1)
                ans+=" ";
        }

        return ans;
    }
}