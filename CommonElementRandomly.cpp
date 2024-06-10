#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
    int a1,a2;
    cout<<"Size of Array 1: ";
    cin>>a1;
    cout<<"Size of Array 2: ";
    cin>>a2;

    int arr1[a1],arr2[a2];
    srand(time(0));

    for(int i=0; i<a1; i++){
        arr1[i]=1+rand()%12;
    }for(int i=0; i<a2;i++){
        arr2[i]=1+rand()%12;
    }

    cout<<"Array 1:\t";
    for(int i=0; i<a1; i++){
        cout<<arr1[i]<<" ";
    }cout<<endl;

    cout<<"Array 2:\t";
    for(int i=0; i<a2; i++){
        cout<<arr2[i]<<" ";
    }cout<<endl;

    int n=0, temp[max(a1,a2)];
    for(int i=0; i<a1; i++){
        for(int j=0; j<a2; j++){
            if(arr1[i]==arr2[j]){
                temp[n] = arr2[j];
                n++;
            }
        }
    }if(n==0){
        cout<<"No match found!\n";
    }else{
        cout<<"Matching items: ";
        for(int i=0;i<n; i++){
            cout<<temp[i]<<" ";
        }
    }cout<<endl;

    return 0;
}