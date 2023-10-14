#include <iostream>
#include <map>
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

void insert(Node* &root, int y, int z){
    if(z == 0){
        root->left = new Node(y);
    }else if(z == 1){
        root->right = new Node(y);
    }
}

void search(Node* root, int x, int y, int z){
    if(root == NULL) return;
    if(root->key == x){
        insert(root, y, z);
    }else{
        search(root->left, x, y, z);
        search(root->right, x, y, z);
    }
}

map<int,int> m;
int mx = 0;

void width(Node* root, int level){
    if(root == NULL) return;
    m[level]++;
    mx = max(mx, m[level]);
    width(root -> left, level+1);
    width(root -> right, level+1);
}

int main(){
    int n;
    cin >> n;
    Node *root = new Node(1);

    for(int i = 0; i < n-1; i++){
        int x, y, z;
        cin >> x >> y >> z;
        search(root, x, y, z);
    }

    width(root, 1);
    cout << mx << endl;

    return 0;
}