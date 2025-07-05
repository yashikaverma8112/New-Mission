vector<vector<int>>levelOrder(Node * root){
    vector<int>ans;
    vector<vector<int>>result;

    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node * top = q.front();
        q.pop();

        if(top!=NULL){
            ans.push_back(top->data);

            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
        }
        else{
            result.push_back(ans);
            ans.clear();

            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
    return result;
}