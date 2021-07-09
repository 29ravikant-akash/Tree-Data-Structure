#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

int height(Node* node){
    if(node==NULL)
    return 0;
    int lh=height(node->left);
    int rh=height(node->right);
    if(lh>rh)
    return lh+1;
    else
    return rh+1;
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
    
    //---------------------height----------------------------------
    cout<<"Height : ";
    cout<<height(root);
    cout<<endl;

    return 0;
}
