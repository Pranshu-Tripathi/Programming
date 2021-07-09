#include<iostream>
#include"Stackcpp.h"

using namespace std;

class Tree{
    private:
        Node* root;
    public:
        Tree()
        {
            this->root = nullptr;
        };
        ~Tree();
        void createTree();
        void preorder()
        {
            preorder(this->root);
        }
        void preorder(Node * x);
        void postorder()
        {
            postorder(this->root);
        }
        void postorder(Node * x);
        void inorder()
        {
            inorder(this->root);
        }
        void inorder(Node * x);
        void levelOrder()
        {
            levelOrder(this->root);
        };
        void levelOrder(Node * x);
        int height()
        {
            height(this->root);
        }
        int height(Node * x);
        Node * getRoot()
        {
            return this->root;
        }
        void preorderIterative()
        {
            preorderIterative(this->root);
        }
        void preorderIterative(Node* x);
        void InorderIterative()
        {
            InorderIterative(this->root);
        }
        void InorderIterative(Node* x);
        void postorderIterative()
        {
            postorderIterative(this->root);
        }
        void postorderIterative(Node* x);
};

void Tree::createTree()
{
    Node *parent;
    Node *temp;
    int x;
    Queue q(100);
    root = new Node;
    root->leftChild = nullptr;
    root->rightChild = nullptr;
    cout << "Enter The Root Value : " << flush ;
    cin >> x;
    root->data = x;
    q.enqueue(root);

    while(!q.isEmpty())
    {
            parent = q.dequeue();
            cout << "Enter the left child of " << parent->data << "  : " <<flush;
            cin >> x;
            if(x != -1)
            {
                temp = new Node;
                temp->leftChild = nullptr;
                temp->rightChild = nullptr;
                temp->data = x;
                parent->leftChild = temp;
                q.enqueue(temp);
            }
            cout << "Enter the right child of " << parent->data << " : " << flush;
            cin >> x;
            if(x != -1)
            {
                temp = new Node;
                temp->leftChild = nullptr;
                temp->rightChild = nullptr;
                temp->data = x;
                parent->rightChild = temp;
                q.enqueue(temp);
            }
    }
}

void Tree::preorder(Node * x)
{
    if(x != NULL)
    {
        cout << x->data << " ";
        preorder(x->leftChild);
        preorder(x->rightChild);
    }
}

void Tree::inorder(Node * x)
{
    if(x != NULL)
    {
        inorder(x->leftChild);
        cout << x->data << " ";
        inorder(x->rightChild);
    }
}

void Tree::postorder(Node * x)
{
    if(x != NULL)
    {
        postorder(x->leftChild);
        postorder(x->rightChild);
        cout << x->data << " ";
    }
}

Tree::~Tree()
{
    //TODO
}

int Tree::height(Node * p)
{
    int l,r =0 ;
    if(p == nullptr)
        return 0;
    l = height(p->leftChild);
    r = height(p->rightChild);
    return max(l,r)+1;
}
