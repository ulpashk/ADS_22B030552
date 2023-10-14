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


int cnt = 0;
void answer(Node *root){
    if(root == NULL){
        return;
    }else{
        if(root->left != NULL && root->right != NULL){
            cnt++;
        }
    }
    answer(root->left);
    answer(root->right);
    
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

    answer(root);
    cout << cnt;

    return 0;
}