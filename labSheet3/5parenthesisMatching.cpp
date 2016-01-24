#include <iostream>
#include <cstring>

using namespace std;

class MyStack {
    char arr[200];
    int top, size;
public:
    MyStack() :top(-1), size(200){
    }
    
    void push(char x) {
        if(top >= size)
            cout << "Stack Overflow" << endl;
        else
            arr[++top] = x;
    }
    
    char pop() {
        if(top == -1) {
            cout << "Stack Underflow" << endl;
        }
        else
            return arr[top--];
    }
    
    bool isEmpty() {
        if(top == -1)
            return 1;
        return 0;
    }
    
    int topIs() {
        return top;
    }
    
    int getMin() {
        int min = arr[0];
        for(int i = 1;i < top; ++i)
            if(arr[i] < min)
                min = arr[i];
            return min;
    }
};

void printISEmpty(bool b) {
    if(b)
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
}

bool checkBalanced(char exp[]) {
    n = strlen(exp);
    MyStack S;
    for(int i=0; i < n;++i) {
        if(exp[i]=='('||'['||'{') 
            S.push(exp[i]);
        else 
            if(exp[i]==')'||'}'||']')
                char temp = S.pop()
                if(S.topIs() == -1 || !pair(exp[i], temp)
                    return false;
    }
    return S.topIs()==-1?true:false;
}

int main() {
    MyStack S;
    char arr[100], length;
    cout << "Enter expression" << endl;
    cin >> arr;
    if(checkBalanced())
        cout << "Expersion is balanced" << endl;
    else
        cout << "Expression is not balanced" << endl;
    return 0;
}
