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

map<int, int> m;

Node* search(Node* root, int val) {
    if(root == NULL || root->key == val) {
        return root;
    }
    if(val < root->key){
        return search(root->left, val);
    }else{
        return search(root->right, val);
    }
}

Node* insert(Node* root, int x){
	if(root == NULL){
		return new Node(x);
	}else if(root->key > x){
		if(root->left == NULL){
			root->left = new Node(x);
		}else{
			root->left = insert(root->left, x);
		}
	}else if (root->key < x){
		if(root->right == NULL){
			root->right = new Node(x);
		}else{
			root->right = insert(root->right, x);
		}
	}
	return root;
}

Node* getMin(Node* root) {
	while(root->left != NULL) {
		root = root->left;
	}
	return root;
}

Node* deleteNode(Node* root, int val){
	if(root == NULL){
		return NULL;
	}else if(root->key > val) {
		root->left = deleteNode(root->left, val);
		return root;
	}else if(root->key < val) {
		root->right = deleteNode(root->right, val);
		return root;
	}else{
		if(root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}else if(root->right == NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}else if(root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}else{
			Node* temp = getMin(root->right);
			root->key = temp->key;
			root->right = deleteNode(root->right, temp->key);
			return root;
		}
	}
}


int main(){
    int n;
    cin >> n;
    Node *root = NULL;

    for(int i = 0; i < n; i++){
        string s; int x;
        cin >> s;
        if(s == "insert"){
            cin >> x;
            if(search(root, x) == NULL){
                insert(root, x);
                m[x]++;
            }else{
                m[x]++;
            }
        }
        if(s == "delete"){
            cin >> x;
            if(m[x] > 1){
                m[x]--;
            }else if(m[x] == 1){
                deleteNode(root, x);
                m[x]--;
            }else{
                cout << "error";
            }
        }
        if(s == "cnt"){
            cin >> x;
            cout << m[x] << endl;
        }
    }

    return 0;
}