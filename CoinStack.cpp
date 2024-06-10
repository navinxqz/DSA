#include<iostream>
using namespace std;

struct coin{
    int id;
    float weight;
};

coin arr[3];
int top=0;
int maxsize=3;


void push(coin value) {
    if(top==maxsize){
        cout<<"Limit is exceeded\n";
        return;
    }
    arr[top] = value;
    top++;
}

void pop() {
    if(top>0){
    cout << "Poped Item: \n";
    top--;
    cout <<"ID: "<<arr[top].id<<"\tWeight: "<<arr[top].weight<< endl;
    }else{
        cout<<"Empty Stack! Nothing to pop.\n";
        return;
    }
}

void show() {
    if(top==0){
        cout<<"Empty Stack!\n";
        return;
    }
    cout << "Displaying all the stack items: \n";
    for (int i= top-1; i>=0;i--) {
        cout << "ID: " <<arr[i].id<<"\tWeight: "<<arr[i].weight<< endl;
    }
}

float TotalWeight(){
    float weight = 0;
    for(int i=0;i<top;i++){
        weight=weight+arr[i].weight;
    }return weight;
}

int main(){
    coin c1={1,2.5};
    coin c2={2,5.5};
    coin c3={3,0.5};

    push(c1);
    push(c2);
    push(c3);

    show();

   cout<<"Total weight now: "<<TotalWeight()<<endl<<endl;
   pop();
   cout<<endl;
   show();
   cout<<"Total weight after the pop: "<<TotalWeight()<<endl<<endl;

   coin c4={4,3};
   push(c4);
   cout<<"New coin pushed!\n";
   show();
   cout<<"Total weight after a new coin push: "<<TotalWeight()<<endl<<endl;

    return 0;
}