#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;

    Node* convertLL(vector<int> &arr){
        Node* head = new Node{arr[0]};
        Node* mover = head;
        for(int i = 1;i<arr.size();i++){
            Node* temp = new Node(arr[i]);
            mover -> next = temp;
            mover = temp;
        }   
        return head;
    }

    void printLL(Node* temp){
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    int lengthofLL(Node* head){
        int count = 0;
        Node* temp = head;
        while(temp){
            temp = temp -> next;
            count++;
        }
        return count;
    }
    
    int checkLL(Node*head, int value){
        Node* temp = head;
        while(temp){
            if(temp->data == value) return 1;
            temp = temp -> next;
        }
        return 0;
    }
};

int main(){
    vector<int> arr={1,2,3,4,5};
    LinkedList l1;
    Node* head = l1.convertLL(arr);
    l1.printLL(head);
    cout<<endl;
    cout<<l1.lengthofLL(head)<<endl;
    cout<<l1.checkLL(head,5)<<endl;
}