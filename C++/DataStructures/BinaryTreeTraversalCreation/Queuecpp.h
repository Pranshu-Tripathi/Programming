/*
Here we will implement the queue data structure used in creating the Binary Tree using linked structure.
*/

#include<iostream>
using namespace std;

class Node
{
public:
    Node * rightChild;
    int data;
    Node * leftChild;
};


class Queue
{
    private:
        int size;
        int front;
        int rear;
        Node ** Q;

    public:
        Queue(int size);
        ~Queue();
        bool isFull();
        bool isEmpty();
        void enqueue(Node * x);
        Node * dequeue();
};


Queue::Queue(int size)
{
    this->size = size;
    this->front = -1;
    this->rear = -1;
    this->Q = new Node* [size];
}

Queue::~Queue()
{
    delete this->Q;
}

bool Queue::isFull()
{
    return (this->rear == this->size-1);
}

bool Queue::isEmpty()
{
    return this->front == this->rear;
}

void Queue::enqueue(Node * x)
{
    if(isFull())
        cout << "Queue Overflow Error!" << endl;
    else
    {
        this->rear++;
        Q[this->rear] = x; 
    }
}

Node* Queue::dequeue()
{
    Node * x = nullptr;
    if(isEmpty())
        cout << "Queue is Empty!" << endl;
    else
    {
        this->front++;
        x = Q[this->front];   
    }
    return x;
}
