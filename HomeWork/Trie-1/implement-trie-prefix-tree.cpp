struct Node{
    Node* link[26];
    bool flag=false;

    bool containkey(char ch){
        return (link[ch-'a']!=NULL);
    }

    void put(char ch, Node* node){
        link[ch-'a']=node;
    }

    Node* get(char ch){
        return link[ch-'a'];
    }

    void setEnd(){
        flag=true;
    }

    bool isEnd(){
        return flag;
    }
};
class Trie {
private: 
    Node* root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            //pehle se character present hai ya nahi
            if(!node->containkey(word[i])){
                //if not present then ye naye node me character daal dega
                node->put(word[i],new Node());
            }
            //move to reference trie
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containkey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        //to check whether the flag is true or false
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
         Node* node=root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containkey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */