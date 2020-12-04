#include<iostream>
#include"Queuecpp.h"
using namespace std;



class Stack{
    private :
        int size;
        int top;
        Node ** S;
    public:
        Stack(int size);
        ~Stack();
        bool isFull();
        bool isEmpty();
        void add(Node* x);
        void remove();
        Node* getTop();
};

Stack::Stack(int size)
{
    this->size = size;
    this->top = -1;
    this->S = new Node*[size];
}

Stack::~Stack()
{
    delete this->S;
}

bool Stack::isFull()
{
    return this->top == this->size+1;
}

bool Stack::isEmpty()
{
    return this->top == -1;
}

void Stack::add(Node * x)
{
    if(isFull())
        cout << "Stack OverFlow Error!" << endl;
    else
    {
        this->top++;
        this->S[this->top] = x;
    }
}

void Stack::remove()
{
    if(isEmpty())
        cout << "Stack Empty Error!" << endl;
    else
    {
        this->top--;   
    }
}



Node* Stack::getTop()
{

    Node * t = nullptr;
    if(isEmpty())
        cout << "StacK is Empty"  << endl;
    else 
    {
        t = this->S[this->top];
    }
    return t;
}

