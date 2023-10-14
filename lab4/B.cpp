#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int val){
        this->key = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void insert(Node* &root, int x){
    if(root == NULL){
        root = new Node(x);
        return;
    }
    if(root->key > x){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}

int size(Node *root){
    if(root == NULL) return 0;
    else return 1 + size(root->left) + size(root->right);
}

void search(Node *root, int t){
    if(root->key == t){
        cout << size(root);
    }else if(root->key > t){
        search(root->left, t);
    }else{
        search(root->right, t);
    }
}

int main(){
    int n;
    cin >> n;
    Node *root = NULL;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }

    int t;
    cin >> t;
    search(root, t);


}