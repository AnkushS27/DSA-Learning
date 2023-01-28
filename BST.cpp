
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

node* insertInBST(node* &root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }
    
    if(d>root->data){
        root->right = insertInBST(root->right, d);
    } else{
        root->left = insertInBST(root->left, d);
    }
    
    return root;
}

void takeInput(node* &root){
    int data;
    cin >> data;
    
    while(data != -1){
        insertInBST(root, data);
        cin>>data;
    }
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

node* minVal(node* root){
    node* mini = root->left;
    
    while(mini->left != NULL){
        mini = mini->left;
    }
    
    return mini;
}

node* deletion(node* root, int val){
    // base case
    if(root == NULL){
        return root;
    }
    
    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        
        // 1 child either left or right
        if(root->left != NULL && root->right == NULL){  // for left child
            node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){  // for right child
            node* temp = root->right;
            delete root;
            return temp;
        }
        
        // 2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deletion(root->right, mini);
            return root;
        }
    } else if(root->data > val){
        root->left = deletion(root->left, val);
        return root;
    } else{
        root->right = deletion(root->right, val);
        return root;
    }
    
    return root;
}

// 50 20 70 10 30 90 110 -1

int main()
{
    node* root = NULL;
    cout<<"Enter data to insert in BST : ";
    takeInput(root);
    
    levelOrderTraversal(root);
    
    deletion(root, 70);
    levelOrderTraversal(root);
    
    // cout<<"\nInoder - ";
    // inorder(root);
    // cout<<"\nPreorder - ";
    // preorder(root);
    // cout<<"\nPostorder - ";
    // postorder(root);
    
    return 0;
}
