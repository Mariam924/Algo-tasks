#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class MyTree {

private:
    struct Node {
        T data;
        Node* left;
        Node* right;
    };
    Node* root;
public:

    MyTree() { root = NULL; }

    MyTree(vector<T> elements) {
        root = NULL;
        sort(elements.begin(), elements.end());
        root = insertforVector(elements, 0, elements.size() - 1);
    }
    Node* insertforVector(vector<T> vec, int start, int end)
    {
        if (start > end)
            return NULL;
        int mid = (start + end) / 2;
        Node* pr = newNode(vec[mid]);
        pr->left = insertforVector(vec, start, mid - 1);
        pr->right = insertforVector(vec, mid + 1, end);
        return pr;
    }
    bool search(T key) {
        Node* pr = root;
        while (pr != NULL) {
            if (key > pr->data)
                pr = pr->right;
            else if (key < pr->data)
                pr = pr->left;
            else
                return true;
        }
        return false;
    }

    void insert(T key) {
        Node* newnode = newNode(key);
        Node* x = root;
        Node* y = NULL;
        while (x != NULL) {
            y = x;
            if (key < x->data)
                x = x->left;
            else if (key > x->data)
                x = x->right;
            else {
                cout << endl;
                return;
            }
        }
        if (root == NULL) {
            root = newnode;
        }
        else if (key < y->data)
            y->left = newnode;
        else
            y->right = newnode;

    }
    Node* newNode(T data)
    {
        Node* temp = new Node;

        temp->data = data;

        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }

    void inorder_rec() {
        inorder(root);
    }
    void inorder(Node* node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void preorder_rec() {
        preorder(root);
    }
    void preorder(Node* node)
    {
        if (node == NULL)
            return;

        cout << node->data << " ";

        preorder(node->left);

        preorder(node->right);
    }
    void postorder_rec() {
        postorder(root);
    }
    void postorder(Node* node)
    {
        if (node == NULL)
            return;

        postorder(node->left);

        postorder(node->right);

        cout << node->data << " ";
    }

    void inorder_it() {
        stack<Node*> s;
        Node* curr = root;

        while (curr != NULL || s.empty() == false)
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            cout << curr->data << " ";
            curr = curr->right;

        }
    }

    void preorder_it() {
        if (root == NULL)
            return;
        stack<Node*> nodeStack;
        nodeStack.push(root);
        while (nodeStack.empty() == false) {
            struct  Node* node = nodeStack.top();
            printf("%d ", node->data);
            nodeStack.pop();
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
    }

    void postorder_it() {
        if (root == NULL)
            return;
        stack<Node*> s1, s2;
        s1.push(root);
        Node* temp = root;
        while (!s1.empty()) {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
            if (temp->left != NULL)
                s1.push(temp->left);
            if (temp->right != NULL)
                s1.push(temp->right);
        }
        while (!s2.empty()) {
            temp = s2.top();
            cout << temp->data << " ";
            s2.pop();

        }
    }

    void breadth_traversal() {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }
    void printCurrentLevel(Node* pr, int level)
    {
        if (pr == NULL)
            return;
        if (level == 1)
            cout << pr->data << " ";
        else if (level > 1) {
            printCurrentLevel(pr->left, level - 1);
            printCurrentLevel(pr->right, level - 1);
        }
    }
    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        else {

            int lHeight = height(node->left);
            int rHeight = height(node->right);

            if (lHeight > rHeight) {
                return (lHeight + 1);
            }
            else {
                return (rHeight + 1);
            }
        }
    }
    int size() {
        return size(root);
    }
    int size(Node* p) {
        if (p == NULL)
            return 0;
        else
            return (size(p->left) + 1 + size(p->right));
    }
};

#endif