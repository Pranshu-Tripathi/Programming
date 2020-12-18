#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;


struct Node {
    int val;
    struct Node* right;
    struct Node* left;
};

struct NodeWithHeight{
    int val;
    int height;
    struct NodeWithHeight* left;
    struct NodeWithHeight* right;
};


int getSumOfAllNodesOfBT(Node* node)
{
    if(node == nullptr)
        return 0;
    
    int leftChild = getSumOfAllNodesOfBT(node->left);
    int rightChild = getSumOfAllNodesOfBT(node->right);

    return node->val + leftChild + rightChild;
}


int getDifferenceEvenOddValues(Node * node)
{
    if(node == nullptr)
        return 0;
    
    return node->val - getDifferenceEvenOddValues(node->left) - getDifferenceEvenOddValues(node->right);
}

int countNodesInBT(Node * node)
{
    if(node == nullptr)
        return 0;
     int leftCount = countNodesInBT(node->left);
     int rightCount = countNodesInBT(node->right);

     return 1 + leftCount + rightCount;
}

int getLeafNodesInBT(Node * node)
{
    if(node == nullptr)
        return 0;
    
    int leftLeaves = getLeafNodesInBT(node->left);
    int rightLeaves = getLeafNodesInBT(node->right);

    if(node->left == nullptr && node->right == nullptr)
        return leftLeaves + rightLeaves + 1;
    else
        return leftLeaves + rightLeaves;
}

int getHeightOfBT(Node* node)
{
    if (node == nullptr)
        return -1;

    int leftHeight = getHeightOfBT(node->left);
    int rightHeight = getHeightOfBT(node->right);

    return max(leftHeight,rightHeight) + 1;
    
}

void printNodeAtLevel(Node* node, int level)
{

    if(node == nullptr)
    {
        return ;
    }

    if(level == 1)
    {
        cout << node->val << " ";
        return;
    }

    printNodeAtLevel(node->left,level-1);
    printNodeAtLevel(node->right,level-1);
}

void levelOrderTraversalRecursion(Node * root)
{
    // first get height of the tree . We know how to print at a particular level
    // complexity of o(n^2)
    if(root == nullptr)
        return;

    int height = getHeightOfBT(root);
    for(int i = 0 ; i  <= height ; i++)
    {
        printNodeAtLevel(root,i+1);
        cout << endl;
    }
}

void levelOrderTraversalIterative(Node * root)
{

    if(root == nullptr)
        return;
     queue<Node*> qu;
     qu.push(root);
     while(!qu.empty())
     {
         Node * front = qu.front();
        qu.pop();

        cout << front->val <<" ";
        if(front->left != nullptr)
            qu.push(front->left);
        if(front->right != nullptr)
            qu.push(front->right);
        cout << endl;
     }
}

void reverseLevelOrderTraversalRecursion(Node * root)
{
    if(root == nullptr)
        return;
    
    int height = getHeightOfBT(root);

    for(int i = height; i >= 0 ; i--)
    {
        printNodeAtLevel(root,i+1);
        cout << endl;
    }
}

void reverseLevelOrderTraversalIterative(Node * root)
{
    if(root == nullptr)
        return;
    
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);

    while(!q.empty())
    {
        Node * front = q.front();
        s.push(front);
        if(front->right != nullptr)
            q.push(front->right);
        if(front->left != nullptr)
            q.push(front->left);
    }

    while(!s.empty())
    {
        Node * top = s.top();
        s.pop();
        cout << top->val << " ";
    }

    cout << endl;
}

void LevelOrderTraversalIterativeLineByLine(Node * root)
{
    if(root == nullptr)
        return;

    queue<Node* > q;
    q.push(root);
    int count;

    while(!q.empty())
    {
        count = q.size();
        while(count--)
        {
            Node * front = q.front();
            cout << front->val << " ";
            if(front->left != nullptr)
                q.push(front->left);
            if(front->right != nullptr)
                q.push(front->right);
        }
        cout << endl;
    }
    
}

int maxLevelLeft;
void printLeftViewTree(Node * node,int level)
{
    if(node == nullptr)
        return;
    if(level >= maxLevelLeft)
    {
        cout << node->val << " ";
        maxLevelLeft++;
    }
    printLeftViewTree(node->left,level+1);
    printLeftViewTree(node->right,level+1);
}

int maxLevelRight;
void printRightViewTree(Node* node, int level)
{
    if(node == nullptr)
        return;
    if(level >= maxLevelRight)
    {
        cout << node->val << " ";
        maxLevelRight++;
    }
    printRightViewTree(node->right,level+1);
    printRightViewTree(node->left,level+1);
}

void inorderWithStack(Node* root)
{
    if(root == nullptr)
    return ;
    stack<Node * > s;
    while (root != nullptr)
    {
        s.push(root);
        root = root->left;
    }
    while(!s.empty())
    {
        Node * tem = s.top();
        s.pop();
        cout << tem->val << " ";
        if(tem->right != nullptr)
        {
            Node * t = tem->right;
            while(t!= nullptr)
            {
                s.push(t);
                t = t->left;
            }
        }
    }
}

void preorderIterative(Node* root)
{
    stack<Node*> s;
    s.push(root);

    while(!s.empty())
    {
        Node* top = s.top();
        s.pop();
        cout << top->val << " ";
        if(top->right != nullptr)
            s.push(top->right);
        if(top->left != nullptr)
            s.push(top->left);
    }
}

void postorderIterative(Node* root)
{
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty())
    {
        Node* top1 = s1.top();
        s2.push(top1);
        if(top1->left != nullptr)
            s1.push(top1->left);
        if(top1->right != nullptr)
            s1.push(top1->right);
    }

    while(!s2.empty())
    {
        Node* top2 = s2.top();
        cout << top2->val << ' ';
    }
}

Node* mirrorTree(Node * node)
{
    if(node == nullptr)
        return nullptr;
    
    Node* tem = node->left;
    node->left = node->right;
    node->right = tem;

    mirrorTree(node->left);
    mirrorTree(node->right);

    return node;
}

Node* deletingBinaryTree(Node* node)
{
    if(node == nullptr)
        return nullptr;
    
    deletingBinaryTree(node->left);
    deletingBinaryTree(node->right);

    cout << "deleting node :  " << node->val << endl;
    node = nullptr;
    return node;
}

bool checkIdenticalTree(Node* node1, Node* node2)
{
    if(node1 == nullptr && node2 == nullptr)
        return true;
    if(node1 == nullptr || node2 == nullptr)
        return false;
    
    return node1->val == node2->val && checkIdenticalTree(node1->left,node2->left) && checkIdenticalTree(node1->right,node2->right);
}

int getLevelOfNode(Node* node, int key, int level)
{
    if(node == nullptr)
        return 0;
    
    if(node->val == key)
        return level;

    int l = 0;
    
    l = getLevelOfNode(node->left,key,level+1);
    if(l != 0)
        return l;
    
    l = getLevelOfNode(node->right,key,level+1);
    return l;
}

void printTopViewOfBT(NodeWithHeight* node)
{
    if(node == nullptr)
        return;

    queue<NodeWithHeight*> q;
    map<int,NodeWithHeight*> m;
    
    node->height = 0;
    q.push(node);

    while(!q.empty())
    {
        NodeWithHeight* front = q.front();
        q.pop();

        int height = front->height;
        if(m.find(height) == m.end())
            m[height] = front;
        
        if(front->left != nullptr)
        {
            front->left->height = height - 1;
            q.push(front->left);
        }

        if(front->right != nullptr)
        {
            front->right->height = height + 1;
            q.push(front->right);
        }
    }

    for(auto e : m)
    {
        cout << e.second->val << " ";
    }
}

void printBottomViewOfBT(NodeWithHeight* node)
{
    if(node == nullptr)
        return;
    
    queue<NodeWithHeight*> q;
    map<int,NodeWithHeight*> m;

    node->height = 0;
    q.push(node);

    while(!q.empty())
    {
        NodeWithHeight* front = q.front();
        
        int height = front->height;
        m[height] = front;

        if(front->left != nullptr)
        {
            front->left->height = height-1;
            q.push(front->left);
        }
            
        if(front->right != nullptr)
        {
            front->right->height = height + 1;
            q.push(front->right);
        }
    }

    for(auto e : m)
    {
        cout << e.second->val << " ";
    }
}

void verticalOrderOfBT(NodeWithHeight* node)
{
    if(node == nullptr)
        return;
    
    queue<NodeWithHeight*> q;
    map<int,vector<NodeWithHeight*>>m;

    node->height = 0;
    q.push(node);

    while(!q.empty())
    {
        NodeWithHeight* front = q.front();
        int height = front->height;
        m[height].push_back(front);
        if(front->left != nullptr)
        {
            front->left->height = height - 1;
            q.push(front->left);
        }
        if(front->right != nullptr)
        {
            front->right->height = height + 1;
            q.push(front->right);
        }
    }

    for(auto e : m)
    {
        cout << "Height " <<e.first << ": ";
        for(auto x : e.second)
        {
            cout << x->val << " ";
        }
        cout << endl;
    }
}