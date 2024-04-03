int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    Node* temp=root;
    int node=INT_MAX;
    while(temp!=NULL){
        if(temp->data==input){
            return temp->data;
        }
        else if(temp->data<input){
            temp=temp->right;
        }
        else{
            node=min(node,temp->data);
            temp=temp->left;
        }
    }
    if(node==INT_MAX) return -1;
    return node;