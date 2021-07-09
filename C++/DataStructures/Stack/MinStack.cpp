#include<bits/stdc++.h>
using namespace std;

class MinStack {

    private:
    int minElement;
    stack<int> s;
    public:
    void minstack(){
        while(s.size())
            s.pop();
        minElement = -1;
    }
    int getMinElement(){
        if(!s.empty())
            return minElement;
        else 
            return -1;
    }
    void push(int val){
        if(s.empty()){
            minElement = val;
            s.push(val);
        }else if(val > minElement){
            s.push(val);
        }else{
            s.push(2*val - minElement);
            minElement = val;
        }
    }
    int top(){
        if(!s.empty()){
            if(s.top() > minElement){
                return s.top();
            }else{
                return minElement;
            }
        }else{
            return -1;
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }else if(s.top() > minElement){
            int x = s.top();
            s.pop();
            return x;
        }else{
            int x = s.top();
            int y = minElement;
            minElement = 2*minElement - x;
            s.pop();
            return y;
        }
    }
};


int main()
{
    MinStack minStack = MinStack();
    cout << minStack.getMinElement() << endl;
    minStack.push(5);
    cout << minStack.pop() << endl;
    minStack.push(5);
    minStack.push(3);
    minStack.push(2);
    minStack.push(1);
    minStack.push(4);
    cout << minStack.getMinElement() << endl;
    cout << "pop : " << minStack.pop() << endl;
    cout << minStack.getMinElement() << endl;
    cout << "pop : " << minStack.pop() << endl;
    cout << minStack.getMinElement() << endl;
    cout << "pop : " << minStack.pop() << endl;
    cout << minStack.getMinElement() << endl;
    cout << "pop : " << minStack.pop() << endl;
    cout << minStack.getMinElement() << endl;
    cout << "pop : " << minStack.pop() << endl;
}