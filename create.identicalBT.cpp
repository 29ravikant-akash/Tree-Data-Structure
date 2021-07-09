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

    //------------Check if two binary trees are identical or not------------------
    Node *root1 = root;
    Node *root2 = root->left;
    queue<Node *> q1;
    queue<Node *> q2;
    int flag = -1;
    if (root1 != NULL)
        q1.push(root1);
    if (root2 != NULL)
        q2.push(root2);
    while (q1.size() && q2.size())
    {
        Node *temp1 = q1.front();
        q1.pop();
        Node *temp2 = q2.front();
        q2.pop();
        if (temp1->data == temp2->data)
        {
            if (temp1->left != NULL)
                q1.push(temp1->left);
            if (temp1->right != NULL)
                q1.push(temp1->right);

            if (temp2->left != NULL)
                q2.push(temp2->left);
            if (temp2->right != NULL)
                q2.push(temp2->right);
        }
        else
            flag = 0;
    }
    if (flag != 0)
    {
        if (q1.size() != 0 || q2.size() != 0)
            cout << "Tree are not identical";
        else
            cout << "Tree are identical";
    }
    else
        cout << "Tree are identical";
    cout << endl;
    //=========================The End===========================
    return 0;
}
