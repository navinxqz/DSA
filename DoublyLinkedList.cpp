#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};
Node* head = NULL;
Node* tail = NULL;

void insert(int data) {
    Node* n = new Node();
    n->value = data;
    n->next = NULL;
    n->prev = NULL;

    if(head == NULL) {
        head = n;
        tail = n;
    }else{
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
}

void print(Node* node){
    cout<<endl;
    while(node != NULL){
        cout << node->value<<"->";
        node = node->next;
    } cout<<"NULL\n\n";
}

bool search(int value){
    Node* current = head;
    while(current != NULL){
        if(current->value == value){
            return true;
        }
        current = current->next;
    }
    return false;
}

void Remove(int value){
    Node* current = head;
    Node* prev = NULL;

    while(current != NULL && current->value != value){
        prev = current;
        current = current->next;
    }
    if(current != NULL){
        if(prev != NULL){
            prev->next = current->next;

            if(current->next != NULL){
                current->next->prev = prev;
            }else{
                tail = prev;
            }
        }else{
            head = current->next;
            if(current->next != NULL){
                current->next->prev = NULL;
            }else{
                tail = NULL;
            }
        } delete current;
    }
}
void AppendB(int value1, int value2, int pos) {
    Node* n = new Node();
    n->value = value1;
    n->next = NULL;
    n->prev = NULL;

    Node* current = head;
    while (current != NULL && current->value != value2) {
        current = current->next;
    }
    if (current != NULL) {
        //before
        if(pos == 1) {
            n->next = current;
            n->prev = current->prev;

            if(current->prev != NULL){
                current->prev->next = n;
            }else{
                head = n;
            }
            current->prev = n;
        }//after
        else if (pos == 0){
            n->next = current->next;
            n->prev = current;

            if(current->next != NULL){
                current->next->prev = n;
            }else{
                tail = n;
            }
            current->next = n;
        }
    }else{
        cout << "Node " << value2 << " not found!\n";
        delete n;
    }
}
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);

    print(head);

//searching...
    int n1, n2;
    cout<<"Search Node: ";
    cin>>n1;

    bool n=search(n1);
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
    int value1,value2,value3,value4;
    cout<<"New node value: ";
    cin>>value1;
    cout<<"\nIn the code i by default pass 1 to do the 'before'.//to do 'after' pass 0 in the code :)\n";
    cout<<"Append "<< value1<<" before (1): ";
    cin>>value2;

    AppendB(value1,value2,1);
    cout<<"After appending...\n";
    print(head);

    cout<<"New node value: ";
    cin>>value3;
    cout<<"Append "<< value3<<" After (1): ";
    cin>>value4;

    AppendB(value3,value4,0);
    cout<<"After appending...\n";
    print(head);

    return 0;
}

