#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
};

Node* head=NULL;
Node* tail=NULL;

void insert(int data){
    Node* n= new Node();
    n->value = data;
    n->next = NULL;

    if(head==NULL){
        head = n;
        tail = n;
    }else{
        tail->next = n;
        tail = n;
    }
}

void print(Node* node){
    cout<<endl;
    while(node!= NULL){
        cout<<node->value<<"->";
        node= node->next;
    }cout<<"NULL\n\n";
}

bool search(int value){
    Node* current=head;
    while(current!=NULL){
        if(current->value==value){
            return true;
        }   current=current->next;
    } return false;
}

void Remove(int value){
    Node* current = head;
    Node* prev = NULL;

    while(current!=NULL && current->value!=value){
        prev = current;
        current = current->next;
    }
    if(current!=NULL){
        if(prev!=NULL){
            prev->next=current->next;
        }else{
            head = current->next;
        }   delete current;
    }
}

void Append(int value1, int value2){
    Node* n = new Node();
    n->value = value1;
    n->next = NULL;

    Node* current = head;
    while(current!=NULL && current->value!=value2){
        current = current->next;
    }
    if(current!=NULL){
        n->next=current->next;
        current->next = n;
    }else{
        cout<<"Node "<<value2<<" not found!\n";
        delete n;
    }
}
int main(){
//inserting...
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    print(head);

//searching...
    int n1,n2;
    cout<<"Search Node: ";
    cin>>n1;

    bool n = search(n1);
    if(n != 0){
        cout<<"Found!\n";
    }else{
        cout<<"Not Found!\n";
    }

//removing...
    cout<<"Remove node: ";
    cin>>n2;
    Remove(n2);
    cout<<"After Removing node "<<n2<<"...\n";
    print(head);

//appending...
    int value1,value2;
    cout<<"New node value: ";
    cin>>value1;
    cout<<"Append "<<value1<<" after: ";
    cin>>value2;

    Append(value1,value2);
    cout<<"After appending...\n";
    print(head);

    return 0;
}