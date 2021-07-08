#include<iostream>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

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
    //------------------right view----------------------------------
    cout<<"right view : ";
    if(root!=NULL)
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int count=1;
        while(count<=size){
            Node* temp=q.front();
            q.pop();
            if(count==size)
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            count++;
        }
    }
    cout<<endl;
    return 0;
}
