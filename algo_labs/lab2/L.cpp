# include <iostream>
# include <algorithm>
# include <cassert>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
	int sum = head->val;
    int maxim = head->val;
    head = head->next;
    while(head != NULL){
        sum = max(head->val, sum+head->val);
        maxim = max(maxim, sum);
        head = head->next;
    }
    return maxim;
}
 
int main() {
    int n;
    cin >> n;
 
    Node *head, *tail;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        Node *cur = new Node();
        cur -> val = x;
 
    if (i == 1){
        head = tail = cur;
    }else{
        tail -> next = cur;
        tail = cur;
    }
  }
 
    cout << findMaxSum(n, head) << endl;
    return 0;
}