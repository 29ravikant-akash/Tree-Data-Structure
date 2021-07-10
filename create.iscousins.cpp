#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int main()
{
    int arr[]={1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, 8, -1, 9, -1, -1, -1, -1};
    int j = 0;
    queue<Node *> q;
    Node *newnode;
    Node *root = new Node;
    // cout << "Enter root node: ";
    // cin >> root->data;
    root->data = arr[j];
    j++;
    root->left = root->right = NULL;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int data;
        // cout << "Enter left node of " << temp->data << " : ";
        // cin >> data;
        data = arr[j];
        j++;
        if (data != -1)
        {
            newnode = new Node;
            newnode->data = data;
            newnode->left = newnode->right = NULL;
            temp->left = newnode;
            q.push(newnode);
        }
        // cout << "Enter right node " << temp->data << " : ";
        // cin >> data;
        data = arr[j];
        j++;
        if (data != -1)
        {
            newnode = new Node;
            newnode->data = data;
            newnode->left = newnode->right = NULL;
            temp->right = newnode;
            q.push(newnode);
        }
    }
    // cout << "end of insertion" << endl;
  
    //-------------------------Is cousins---------------------------
    int a,b;
    int p1=-1,l1=-1,p2=-1,l2=-1;
    int level=0;
    cout<<"Enter the value of two nodes: ";
    cin>>a>>b;
    cout<<"Is cousins : ";
    if(root!=NULL)
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int count=1;
        level++;
        while(count<=size){
            Node* temp=q.front();
            q.pop();
            if(temp->left!=NULL){
                if(temp->left->data==a){
                l1=level;
                p1=temp->data;
                }
                if(temp->left->data==b){
                    l2=level;
                    p2=temp->data;
                }
            }
            if(temp->right!=NULL){
                if(temp->right->data==a){
                l1=level;
                p1=temp->data;
                }
                if(temp->right->data==b){
                    l2=level;
                    p2=temp->data;
                }
            }
            
            if(temp->left!=NULL)
            q.push(temp->left);
            if(temp->right!=NULL)
            q.push(temp->right);
            count++;
        }
    }
    if(l1==l2 && p1!=p2)
    cout<<"Yes, they are cousine";
    else
    cout<<"No, they are not cousine";

    cout<<endl;

    //======================================================The End===============================================================
    return 0;
}
