#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int newdata){
        this->data = newdata;
        this->next = NULL;
    }
};

void print(Node *head){
    Node* cur  = head;
    while(cur != NULL){
            cout << cur->data << " ";
    if(cur->next == NULL){
        return;
    }    
        cur = cur->next->next;
    }
    cout << endl;
}

int main(){
    Node *head;
    Node *cur;
    Node *a;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int k; cin >> k;
        if(i == 0){
            head = new Node(k);
            cur = head;
        }else{
            a = new Node(k);
            cur->next = a;
            cur = cur->next;
        }
    }
    
    print(head);

return 0;
}