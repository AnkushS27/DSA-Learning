#include <iostream>
#include <queue>

using namespace std;

class node{
    public:
    node* left;
    int data;
    node* right;
    
    node(int d){
        this->left = NULL;
        this->data = d;
        this->right =NULL;
    }
};

node* buildTree(node* root){
    cout<<"\nEnter the data: "<<endl;
    int data;
    cin>>data;
    
    root = new node(data);
    
    if(data==-1){
        return NULL;
    }
    
    cout<<"Enter data to the left of "<<data<<" : ";
    root->left = buildTree(root->left);
    cout<<"Enter data to the right of "<<data<<" : ";
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        } else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}

// Inorder - LNR
// Peorder - NLR
// Postorder - LRN

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    // LNR
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    // NLR
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    
    // LRN
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;
    
    root = buildTree(root);
    
    cout<<"printing tree: "<<endl;
    levelOrderTraversal(root);
    
    cout<<"\nInoder - ";
    inorder(root);
    cout<<"\nPreorder - ";
    preorder(root);
    cout<<"\nPostorder - ";
    postorder(root);

    return 0;
}
