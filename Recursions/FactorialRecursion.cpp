#include <iostream>
using namespace std;

int factorialRecursion(int m){
    if(m>31){
        cout<<"memory exceeds limit\n";
        return 0;
    }
    if(m <= 0){
        return 1;
    }   return m * factorialRecursion(m-1);
}
int main(){
    int m = 0;
    cout<< "Factorial value of: ";
    cin>>m;

    cout<<"Result: "<<factorialRecursion(m);
    return 0;
}