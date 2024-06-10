#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n<=1){
        return n;
    }   return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n=0;
    cout<<"Fibonacci for the number: ";
    cin>>n;
    cout<<"Result: "<<fibonacci(n)<<endl;

    return 0;
}