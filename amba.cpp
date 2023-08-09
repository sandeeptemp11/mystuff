// sorting the linked list in sorted order using doubly linked list
#include <bits/stdc++.h>
using namespace std;

struct node{
    node* prev;
    int data;
    node* next;
    node(int d){
        data = d;
        prev = NULL;
        next = NULL;
    }
};

void insert(struct node*& head, int data){

    node* curr = new node(data);
    if(head == NULL || head->data >= data){
        curr->next = head;
        if(head != NULL) head->prev = curr;
        head = curr;
    }else{
        node* trav = head;
        while(trav->next != NULL && trav->next->data < data) trav = trav->next;
        curr->next = trav->next;
        curr->prev = trav;
        trav->next = curr;
    }
}

void print(struct node* head){
    if(head == NULL) cout << "Empty!!\n";
    while(head != NULL){
        cout << head->data;
        head = head->next;
        if(head != NULL) cout << "->";
    }
    cout << "\n";
}

int main(){
    int n; // number of nodes
    cin >> n;

    int data;
    node* head = NULL;
    while(n--){
        cin >> data;
        insert(head, data);       
    }
    print(head);
}
