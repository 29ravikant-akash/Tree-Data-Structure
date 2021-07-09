#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
void preorder(Node* node){
    if(node!=NULL){
        cout<<node->data<<" ";
        preorder(node->left);
        preorder(node->right);
    }
}
void inorder(Node* node){
    if(node!=NULL){
        inorder(node->left);
        cout<<node->data<<" ";
        inorder(node->right);
    }
}
void postorder(Node* node){
    if(node!=NULL){
        postorder(node->left);
        postorder(node->right);
        cout<<node->data<<" ";
    }
}
int main(){ 
    queue<Node*> q;
    Node* newnode;
    Node* root=new Node;
    cout<<"Enter root node: ";
    cin>>root->data;
    root->left=root->right=NULL;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        int data;
        cout<<"Enter left node of "<<temp->data<<" : ";
        cin>>data;
        if(data!=-1){
            newnode=new Node;
            newnode->data=data;
            newnode->left=newnode->right=NULL;
            temp->left=newnode;
            q.push(newnode);
        }
        cout<<"Enter right node "<<temp->data<<" : ";
        cin>>data;
        if(data!=-1){
            newnode=new Node;
            newnode->data=data;
            newnode->left=newnode->right=NULL;
            temp->right=newnode;
            q.push(newnode);
        }
    }
    
    cout<<"end of insertion"<<endl;
    
    // //------------------levelorder traversal-------------------
    cout<<"levelorder traversal: ";
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);
    }
    cout<<endl;
    //------------------preorder traversal-------------------------
    cout<<"preorder traversal: ";
    preorder(root);
    cout<<endl;
    //------------------inorder traversal--------------------------
    cout<<"inorder traversal: ";
    inorder(root);
    cout<<endl;
    //------------------postorder traversal------------------------
    cout<<"postorder traversal: ";
    postorder(root);
    cout<<endl;
    
    return 0;
}
