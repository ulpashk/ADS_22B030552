#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;

    Node (int newData){
        this->data = newData;
        this->next = NULL;
    }

};

void print(Node* head){
    Node* cur = head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void nearestNum(Node* head, int k){
    Node* cur = head;
    int ans = 0;
    int offset = 0;

    int min = abs(k - cur->data);
    while(cur != NULL){
        if(min > abs(k - cur->data)){
            min = abs(k - cur->data);
            ans = offset;
        }
        cur = cur->next;
        offset++;
    }
    cout << ans << endl;
}

int main(){
    Node *head;
    Node *cur;
    Node *a;
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        int data;
        cin >> data;
        if(i == 0){
            head = new Node(data);
            cur = head;
        }else{
            a = new Node(data);
            cur->next = a;
            cur = cur->next;
        }
        
    }

    int k; cin >> k;
    nearestNum(head, k);

return 0;
}