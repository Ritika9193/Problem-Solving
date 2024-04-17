struct Node{
    Node* links[26];
    bool flag=false;
    bool containkey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};
class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root=new Node();
        }
        void insert(string word){
            Node* node=root;
            for(int i=0;i<word.size();i++){
                if(!node->containkey(word[i])){
                    node->put(word[i],new Node());
                }
                node=node->get(word[i]);
            }
            node->setEnd();
        }
        string find(string& word){
            Node* node=root;
            string ans="";
            for(int i=0;i<word.size();i++){
                if(node->isEnd()) break;
                if(node->containkey(word[i])){
                    ans+=word[i];
                    node=node->get(word[i]);
                }
                else{
                    break;
                }
            }
            if(node->isEnd()){
                return ans;
            }
            else{
                return "";
            }
        }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        int n=dictionary.size();
        int m=sentence.size();
        string temp="";
        for(int i=0;i<n;i++){
            trie.insert(dictionary[i]);
        }
        string ans="";
        for(int i=0;i<m;i++){
            if(sentence[i]!=' '){
                temp+=sentence[i];
            }
            else{
                string str=trie.find(temp);
                if(str==""){
                    ans+=temp;
                }
                else{
                    ans+=str;
                }
                ans+=' ';
                temp="";
            }
            if(i==m-1){
                string str=trie.find(temp);
                if(str==""){
                    ans+=temp;
                }
                else{
                    ans+=str;
                }
            }
        }
        return ans;
    }
};