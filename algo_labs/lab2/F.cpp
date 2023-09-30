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

void print(Node *head, int value, int pos){
    Node *cur = head;
    int i = 0;
    Node* a = new Node(value);
    while(cur != NULL){
        if(i == pos){
            a->next = cur;
            cur = a;
        }
        cout << cur->data << " ";
        cur = cur->next;
        i++;
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
        int k;
        cin >> k;
        if(i == 0){
            head = new Node(k);
            cur = head;
        }else{
            a = new Node(k);
            cur->next = a;
            cur = cur->next;
        }
    }
    int value, pos;
    cin >> value >> pos;
    print(head, value, pos);
    return 0;
}