#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool root_node_path(Node *node, vector<int> &v, int nodedata)
{
    if (node == NULL)
        return false;

    v.push_back(node->data);
    if (node->data == nodedata)
        return true;
    if (root_node_path(node->left, v, nodedata) || root_node_path(node->right, v, nodedata))
        return true;

    v.pop_back();
    return false;
}

int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, 8, -1, 9, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7,-1,-1,8,-1,-1,-1,-1,9,-1,-1,10,11,-1,-1,-1,-1};
    // int arr[] = {1, 2, -1, 3, 4, -1, 5, -1, 6,-1,-1, 7, -1, -1, -1};
    // int arr[] = {1, 2, -1, 4, 5, 6, 7, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, -1, 3, -1, 4, -1, -1, -1};
    int iterate = 0;
    queue<Node *> q;
    Node *newnode;
    Node *root = new Node;
    // cout << "Enter root node: ";
    // cin >> root->data;
    root->data = arr[iterate];
    iterate++;
    root->left = root->right = NULL;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        int data;
        // cout << "Enter left node of " << temp->data << " : ";
        // cin >> data;
        data = arr[iterate];
        iterate++;
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
        data = arr[iterate];
        iterate++;
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

    //-------------------------All root to leave path---------------------------
    vector<int> v1;
    vector<int> v2;
    int data1;
    int data2;
    cout << "Enter the node 1 : ";
    cin >> data1;
    cout << "Enter the node 2: ";
    cin >> data2;
    root_node_path(root, v1, data1);
    root_node_path(root, v2, data2);
  
    cout<<"Path of node 1 : ";
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";
    cout << endl;
    cout<<"Path of node 2 : ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;

    int i=0,j=0,pos1=0,pos2=0;
    while (i<v1.size() && j<v2.size())
    {
        if(v1[i]==v2[j]){
            pos1=i;
            pos2=j;
        }
        i++;
        j++;
    }
    vector<int> v;
    for(i=v1.size()-1;i>=pos1;i--)
    v.push_back(v1[i]);
    for(i=pos2+1;i<v2.size();i++)
    v.push_back(v2[i]);

    cout<<"Nodes between node 1 and node 2(including both) : ";
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;
    cout<<"Distance between node 1 and node 2 : "<<v.size()-1<<endl;
  
    //======================================================The End===============================================================
    return 0;
}
