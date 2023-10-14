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

map<int, int> m;
int mx = 0;

void FindLevel(Node* root, int level){
    if(root == NULL) return;
    m[level] += root->key;
    mx = max(mx, level);
    FindLevel(root->left, level+1);
    FindLevel(root->right, level+1);
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

    FindLevel(root, 1);
    cout << mx << endl;
    for(int i = 1; i <= mx; i++){
        cout << m[i] << " ";
    }

    return 0;
}