#include <iostream>
#include <vector>
using namespace std;

class node {
    public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = nullptr;
    }
};

class linkedlist {
    public:
    node* head;
    node* tail;

    linkedlist() {
        head = nullptr;
        tail = nullptr;
    }

    void insertion(int value) {
        node* newnode = new node(value);
        if (head == nullptr) { 
            head = newnode;
            tail = newnode;
        } else { 
            tail->next = newnode;
            tail = newnode;
        }
    }

    void deletion(int value){
    if (head == nullptr) return;
    if (head->data == value) {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == value) {
            node* del = temp->next;
            temp->next = temp->next->next;
            delete del;
            return;
        }
        temp = temp->next;
    }
}

    void traversal(node* head) {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            temp = temp->next; 
        }
    }

    node* convertLL(vector<int> &arr){
        node* head = new node{arr[0]};
        node* mover = head;
        for(int i = 1;i<arr.size();i++){
            node* temp = new node(arr[i]);
            mover -> next = temp;
            mover = temp;
        }   
        return head;
    }

    node* deletehead(node* head){
        if(head==nullptr) return head;
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

};

int main() {
    cout<<"Through Arr to LL"<<endl;
    vector<int> arr={1,2,3,4,5,6};
    linkedlist l1;
    node* head = l1.convertLL(arr);
    head = l1.deletehead(head);
    l1.traversal(head);

    cout<<endl;

    cout<<"Through Creating a New LL"<<endl;
    linkedlist l2;
    l2.insertion(1);
    l2.insertion(2);
    l2.insertion(3);
    l2.insertion(4);
    l2.insertion(5);
    l2.insertion(6);
    l2.deletion(4);
    l2.traversal(l2.head);

    return 0;
}
