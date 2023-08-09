// xor doubly linked list
#include <iostream>
using namespace std;

struct node{
    int expo;
    int coeff;
    node* xptr;

    node(int e, int c, node* prev, node* next){
        expo = e;
        coeff = c;
        xptr = reinterpret_cast <node*> (reinterpret_cast<int>(prev) ^ reinterpret_cast<int>(next));
    }
};

// inserting in decreasing order of exponents
void insert(struct node*& head, int expo, int coeff){
    if(head == NULL) head = new node(expo, coeff, NULL, NULL);
    else if(head->expo < expo){
        node* curr = new node(expo, coeff, NULL, head);
        head->xptr = reinterpret_cast <node*> (reinterpret_cast<int>(curr) ^ reinterpret_cast<int>(head->xptr));
        head = curr;
    }else{
        node* trav  = head;
        node* prev = NULL;
        node* pprev = NULL;
        while(trav != NULL && trav->expo > expo){
            struct node* temp = trav;
            trav = reinterpret_cast <node*> (reinterpret_cast<int>(prev) ^ reinterpret_cast<int>(trav->xptr));
            pprev = prev;
            prev = temp;
        }
        if(trav->expo == expo) trav->coeff += coeff;
        else{
            node* curr = new node(expo, coeff, prev, trav);
            prev->xptr = reinterpret_cast <node*> (reinterpret_cast<int>(pprev) ^ reinterpret_cast<int>(curr));
            if(trav != NULL) trav->xptr = reinterpret_cast <node*> (reinterpret_cast<int>(prev) ^ reinterpret_cast<int>(trav) ^ reinterpret_cast<int>(curr));
        }
    }
}

void print(node* head){
    if(head == NULL) cout << "Empty!!\n";
    node* prev = NULL;
    while(head != NULL){
        cout << "(" << head->coeff << "x^(" << head->expo << "))";
        struct node* temp = head;
        head = reinterpret_cast <node*> (reinterpret_cast<int>(prev) ^ reinterpret_cast<int>(head->xptr));
        prev = temp;
        if(head != NULL) cout << " + ";
        else cout << "\n";
    }
}

struct node* take(){
    int n; // number of elements;
    cin >> n;

    node* head = NULL;
    while(n--){
        int expo, coeff;
        cin >> coeff >> expo;
        insert(head, expo, coeff);
    }
    return head;
}

int main(){
    struct node* poly1 = take();
    //struct node* poly2 = take();
    //struct node* poly = add(poly1, poly2);
    print(poly1);
}
