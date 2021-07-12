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
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1};
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

    //-------------------------- Diagonal sum ----------------------------
    unordered_map<int, vector<int>> m;
    queue<pair<Node *, int>> qu;
    if (root != NULL)
        qu.push(make_pair(root, 0));
    while (qu.size())
    {
        pair<Node *, int> temp = qu.front();
        qu.pop();
        Node *node = temp.first;
        int diagonal = temp.second;
        m[diagonal].push_back(node->data);
        if (node->left != NULL)
            qu.push(make_pair(node->left, diagonal + 1));
        if (node->right != NULL)
            qu.push(make_pair(node->right, diagonal));
    }
    unordered_map<int, vector<int>>::iterator it;
    int max = 0;
    int min = INT_MAX;
    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->first > max)
            max = it->first;
        if (it->first < min)
            min = it->first;
    }
    cout<<"Diagonal sum: "<<endl;
    for (int i = min; i <= max; i++)
    {
        cout << i << " -> ";
        int sum = 0;
        for (int j = 0; j < m[i].size(); j++)
            sum += m[i][j];
        cout << sum << endl;
    }

    //======================================================The End===============================================================
    return 0;
}
