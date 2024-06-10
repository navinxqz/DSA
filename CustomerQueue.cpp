#include<iostream>
using namespace std;

struct customer{
    int id;
    string name;
    string pname;
    float price;
};

customer arr[3];
int front=-1,rear=-1;
int maxsize=3;


void enqueue(customer value) {
    if(rear==maxsize-1){
        cout<<"Limit is exceeded\n";
        return;
    }
    rear++;
    arr[rear] = value;
}

void dequeue() {
    if(front==rear){
        cout<<"Empty Space! Nothing for dequeue.\n";

        return;
    }
    cout << "Dequeued: \n";
    front++;
    cout <<"ID: "<<arr[front].id<<"\tName: "<<arr[front].name<<"\tPrice: "<<arr[front].price<< endl<<endl;
    }

float TotalSell(){
    float sell = 0;
    for(int i=0;i<=front;i++){
        sell=sell+arr[i].price;
    }return sell;
}

void show() {
    if(front==rear){
        cout<<"Empty space!\n";
        return;
    }
    cout << "Displaying queues: \n";
    for (int i=front+1;i<=rear;i++) {
        cout << "ID: " <<arr[i].id<<"\tName: "<<arr[i].name<<"\tproduct: "<<arr[i].pname<<"\tprice: "<<arr[i].price<< endl;
    }
}

int main(){
    customer c1={1,"Rahim","Chips",50.70};
    customer c2={2,"Karim","Coke",50};
    customer c3={3,"Samim","KitKat",100};

    enqueue(c1);
    enqueue(c2);
    enqueue(c3);

    show();
    dequeue();
    cout<<"Total sell: "<<TotalSell()<<" taka\n\n";
    show();
    dequeue();
    cout<<"Total sell: "<<TotalSell()<<" taka\n\n";
    show();
    dequeue();
    cout<<"Total sell: "<<TotalSell()<<" taka\n\n";
    show();
    cout<<"\n\n";
    return 0;
}
