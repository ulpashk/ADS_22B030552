#include <iostream>
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
    }else if(root->key > x){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}

void answer(Node *root){
    if(root == NULL){
        return;
    }else{
        cout << root->key << " ";
    }
    answer(root->left);
    answer(root->right);
}

void search(Node *root, int k){
    if(root->key == k){
        //cout << root->key << " ";
        answer(root);
        // return;
    }else if(root->key > k){
        search(root->left, k);
    }else{
        search(root->right, k);
    }
}

int main(){
    int n;
    cin >> n;
    Node* root = NULL;

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        insert(root, x);
    }

    int k;
    cin >> k;
    search(root, k);

    return 0;
}