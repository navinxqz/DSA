#include <iostream>
using namespace std;

int arr[3];
int top = 0;
int maxSize = 3;

void push(int value) {
    if(top==maxSize){
        cout<<"Stack overflow\n";
        return;
    }
    arr[top] = value;
    top++;
}

void pop() {
    if(top==0){
        cout<<"No element to pop\n";
        return;
    }
    cout << "Poped Item: \n";
    top--;
    cout << arr[top] << endl;
}

void show() {
    cout << "Displaying all the stack items: " << endl;
    for (int i = top - 1; i >= 0; i--) {
        cout << arr[i] << endl;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    
    show(); 
    pop();
    show();
    return 0;
}