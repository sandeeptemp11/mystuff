#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Duplicates are not supported
class bst{
    private:
    node* root = NULL;

    public:
    void insert(int data);
    void remove(int data);
    bool search(int data);
    void inorder();
};

bool bst::search(int data){
    node* trav = root;
    while(trav != NULL){
        if(trav->data > data) trav = trav->left;
        else if(trav->data < data) trav = trav->right;
        else return true;
    }
    return false;
}

void bst::insert(int data){
    node* trav = root;
    while(trav != NULL){
        if(trav->data == data) return;
        else if(trav->data > data){
            if(trav->left == NULL){
                trav->left = new node(data);
                return;
            }else trav = trav->left;
        }else{
            if(trav->right == NULL){
                trav->right = new node(data);
                return;
            }else trav = trav->right;
        }
    }
    root = new node(data);
}

void bst::remove(int data){
    node* trav = root;
    node* parent = NULL;
    bool left_parent = false;
    while(trav != NULL){
        if(trav->data == data){
            if(trav->right == NULL){
                if(parent == NULL) root = root->left;
                else if(left_parent) parent->left = trav->left;
                else parent->right = trav->left;
                delete trav;
                trav = NULL;
            }else{
                node* store = trav;
                parent = trav;
                trav = trav->right;
                left_parent = false;
                while(trav->left != NULL){
                    parent = trav;
                    trav = trav->left;
                    left_parent = true;
                }
                store->data = trav->data;
                trav->data = data;
            }
        }else{
            parent = trav;
            if(trav->data > data){
                trav = trav->left;
                left_parent = true;
            }else{
                left_parent = false;
                trav = trav->right;
            }
        }
    }
}

void inorder_helper(node* root){
    if(root == NULL) return;
    inorder_helper(root->left);
    cout << root->data << " ";
    inorder_helper(root->right);
}

void bst::inorder(){
    if(root == NULL) cout << "Empty BST!!\n";
    else{
        inorder_helper(root);
        cout << "\n";
    }
}


int main(){
    int n;
    cin >> n;

    bst obj;
    while(n--){
        int num;
        cin >> num;
        obj.insert(num);
    }

    obj.remove(20);
    obj.inorder();
    return 0;
}
