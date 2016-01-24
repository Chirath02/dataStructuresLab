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
    
    char getTop() {
        return arr[top];
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

bool isPair(char a, char b) {
    if(b=='(' && a == ')')
        return true;
    if(b=='{' && a == '}')
        return true;
    if(b=='[' && a == ']')
        return true;
    return false;
}

bool checkBalanced(char exp[]) {
    int n = strlen(exp);
    char temp;
    MyStack S;
    for(int i=0; i < n;++i) {
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{') 
            S.push(exp[i]);
        else 
            if(exp[i]==')'||exp[i]=='}'||exp[i]==']')
                if(S.topIs() == -1 || !isPair(exp[i], S.getTop()))
                    return false;
                else 
                    S.pop();
    }
    return S.topIs()==-1?true:false;
}

int main() {
    MyStack S;
    char arr[100], length;
    cout << "Enter expression" << endl;
    cin >> arr;
    if(checkBalanced(arr))
        cout << "Expersion is balanced" << endl;
    else
        cout << "Expression is not balanced" << endl;
    return 0;
}
