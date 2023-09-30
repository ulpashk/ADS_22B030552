#include <bits/stdc++.h>
using namespace std;

struct Node{
    string data;
    Node *next;

    Node(string newdata){
        this->data = newdata;
        this->next = NULL;
    }
};

Node* shift(Node *head, int k){
    Node *cur = head;
    Node *tail;
    while(cur->next != NULL){
        cur = cur->next;
        tail = cur;
    }

    while(k--){
        Node *newone = head->next;
        tail->next = head;
        head->next = NULL;
        head = newone;
        tail = tail->next;
    }
    return head;
}


void print(Node *head){
    Node* cur = head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

int main(){
    Node *head;
    Node *cur;
    Node *a;

    int n, k;
    cin >> n >> k;
    string s;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(i == 0){
            head = new Node(s);
            cur = head;
        }else{
            a = new Node(s);
            cur->next = a;
            cur = cur->next;
        }
    }

    head = shift(head, k);
    print(head);

return 0;
}