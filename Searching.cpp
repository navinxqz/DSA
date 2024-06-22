#include <iostream>
using namespace std;

int binarySearch(const string arr[], const string& target, int n){
    int low= 0;
    int high=n - 1;

    while(low <= high){
        int mid= low+(high-low) / 2; // Avoid integer overflow

        if(arr[mid] == target){
            // Handle duplicates
            while (mid > 0 && arr[mid - 1] == target){
                mid--;
            }   return mid;
        }else if (arr[mid]<target) {
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }   return -1; // If the target is not found
}

int main(){
    string arr[]={"apple", "banana", "cherry", "date", "date", "fig", "grape"};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<"Given array: ";

    for(int i = 0; i<n; i++){
        cout<<arr[i];
        if(i<n-1) {
            cout<< ", ";
        }
    }   cout<< endl<<endl;

    string targets[]={"apple", "cherry", "date", "grape", "Coconut"};
    int m=sizeof(targets)/sizeof(targets[0]);

    for (int i=0;i<m; i++) {
        string temp= targets[i];
        int index= binarySearch(arr, temp, n);
        if(index != -1) {
            cout<<temp<<" Found at index: "<< index+1 << endl;
        }else{
            cout<<temp<< " not found!" << endl;
        }
    }   return 0;
}
