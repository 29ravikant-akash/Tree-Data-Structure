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
    // int arr=[1,2,3,4,5,6,7,-1,-1,-1,-1,-1,-1,-1,-1];
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, 8, -1, 9, -1, -1, -1, -1};
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
    //---------------Top view------------------------
    cout << "top view: " << endl;
    int hd = 0;
    unordered_map<int, vector<int>> m;
    queue<pair<Node *, int>> que;
    que.push(make_pair(root, hd));
    while (!que.empty())
    {
        pair<Node *, int> temp = que.front();
        que.pop();
        hd = temp.second;
        Node *node = temp.first;
        m[hd].push_back(node->data);
        if (node->left != NULL)
            que.push(make_pair(node->left, hd - 1));
        if (node->right != NULL)
            que.push(make_pair(node->right, hd + 1));
    }
    unordered_map<int, vector<int>>::iterator it;
    int max=0;
    int min=INT_MAX;
    for (it = m.begin(); it != m.end(); it++) {
        if(it->first>max)
        max=it->first;
        if(it->first<min)
        min=it->first;
    }
    for(int i=min;i<=max;i++)
    cout << m[i][0] << " " ;
    cout<<endl;

    //=========================The End===========================
    return 0;
}
