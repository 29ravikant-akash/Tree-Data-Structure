#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

int inplacesum(Node* node){
    if(node==NULL)
    return 0;
    
    int ls=inplacesum(node->left);
    int rs=inplacesum(node->right);
    int sum=ls+node->data+rs;
    node->data=ls+rs;
    return sum;
}

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

    //-------------------------In place sum------------------------
    cout<<"In place sum : ";
    cout<<inplacesum(root);
    cout<<endl;

    //======================================================The End===============================================================
    return 0;
}
