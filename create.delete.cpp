#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

//=================================================================================================================================
int main()
{
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1};
    int arr[] = {1, 2, 3, 4, 5, -1, -1, -1, -1, -1, -1};
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, 8, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1};
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

    //-------------------------- Delete ----------------------------
    // replacing deleting node with bottom most rightmost node
    int bottommostrightmostnode;
    int deletenode;
    int ch = 1;
    while (ch)
    {

        cout << "Enter node to be deleted: ";
        cin >> deletenode;
        if (root == NULL)
            cout << "Tree is empty" << endl;
        else if (root->data == deletenode && root->left == NULL && root->right == NULL)
        {
            root = NULL;
        }
        else
        {

            // finding bottommost rightmost node
            if (root != NULL)
                q.push(root);
            while (q.size())
            {
                Node *temp = q.front();
                q.pop();
                bottommostrightmostnode = temp->data;
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
            cout<<"bottom most right node: "<<bottommostrightmostnode<<endl;
            // deleting node
            q.push(root);
            while (q.size())
            {
                Node *temp = q.front();
                q.pop();
                if (temp->data == deletenode)
                    temp->data = bottommostrightmostnode;
                if (temp->left != NULL)
                {
                    if (temp->left->data == bottommostrightmostnode)
                        temp->left = NULL;
                }

                if (temp->right != NULL)
                {
                    if (temp->right->data == bottommostrightmostnode)
                        temp->right = NULL;
                }

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
        // end of deletion
        cout << "levelorder traversal: ";
        if (root != NULL)
            q.push(root);
        else
            cout << "Tree empty";
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
        cout << "continue(1/0) :  ";
        cin >> ch;
    }

    //======================================================The End===============================================================
    return 0;
}
