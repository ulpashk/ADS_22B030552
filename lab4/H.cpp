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
    }else if(root->key > x){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}

void sum_node(Node* root, int &summ){
    if(root == NULL) return;
    sum_node(root->right, summ);
    root->key += summ;
    summ = root->key;

    cout << summ << " ";

    sum_node(root->left, summ);
}


int main(){
    int n;
    cin >> n;
    Node* root = NULL;
    int summ = 0;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }

    sum_node(root, summ);
}