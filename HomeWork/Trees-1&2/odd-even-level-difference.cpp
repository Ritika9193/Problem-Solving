class Solution{
  public:
    int getLevelDiff(Node *root)
    {
        int evenSum=0;
        int oddSum=0;
        if(root==NULL){
          return 0;
        }
        queue<Node*>q;
        q.push(root);
        int cnt=1;
        while(!q.empty()){
            int len=q.size();
            while(len--){
                Node* front=q.front();
                q.pop();
                if(cnt%2!=0){
                    oddSum+=front->data;
                }
                else{
                    evenSum+=front->data;
                }
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
            cnt++;
        }
        return oddSum-evenSum;
      
    }
};