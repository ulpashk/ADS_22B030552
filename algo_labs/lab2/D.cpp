#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

int main(){
    Node *head;
    Node *cur;
    Node *a;
    int n; 
    cin >> n;
    map<int, int> m;
    map<int, int>::iterator it;
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

    Node *i;
    i = head;
    int mx = -1;
    while(i!=NULL){
        int num = i->data;
        m[num]++;
        mx = max(mx, m[num]);
        i = i->next;
    }
    m[0] = 0;
    for(it = m.end(); it !=m.begin(); --it){
        if(it->second == mx){ 
            cout << it->first << " "; 
        }
    }

    return 0;
}