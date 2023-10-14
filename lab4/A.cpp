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
    }else if(root->key > x){
        insert(root->left, x);
    }else{
        insert(root->right, x);
    }
}


bool valid(Node *root, string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            root = root->right;
            if(root == NULL) return false;
        }else{
            root = root->left;
            if(root == NULL) return false;
        }
    }
    return true;
}

int main(){
    int n, m;
    cin >> n >> m;

    Node *root = NULL;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        insert(root, x);
    }

    for(int i = 0; i < m; i++){
        string s; 
        cin >> s;
        if(valid(root, s) == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}