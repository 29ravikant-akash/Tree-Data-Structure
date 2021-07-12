#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void mirror(Node *node)
{
    if (node != NULL)
    {
        if (node->left != NULL && node->right != NULL)
        {
            Node *temp = node->left;
            node->left = node->right;
            node->right = temp;
        }
        else if (node->left == NULL && node->right != NULL)
        {
            node->left = node->right;
            node->right = NULL;
        }
        else if (node->left != NULL && node->right == NULL)
        {
            node->right = node->left;
            node->left = NULL;
        }
        mirror(node->left);
        mirror(node->right);
    }
}

//=================================================================================================================================
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};
    int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
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


    //-------------------------- mirror of tree ----------------------------
    mirror(root);
    cout << "mirror tree levelorder traversal: ";
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    cout << endl;
  
    //======================================================The End===============================================================
    return 0;
}
