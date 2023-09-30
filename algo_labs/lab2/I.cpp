#include <bits/stdc++.h>
using namespace std;

struct Node{
	string val;
	Node * prev;
	Node * next;
	Node(string newval){
		this->prev = NULL;
		this->next = NULL;
		this->val = newval;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
	Node *cur = head;
	Node *newNode = new Node(s);
	if(head==NULL){
		head = newNode;
	}else{
		while(cur != NULL){
			if(cur->next == NULL){
				cur->next = newNode;
				return;
			}
			cur = cur->next;
		}
	}
}
void add_front(string s){
    Node *cur = head;
    Node *newNode = new Node(s);
        if(head == NULL){
            newNode->next = head;
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
}
bool empty(){
	if(head == NULL){
		return true;
	}else{
		return false;
	}
}
void erase_front(){
	head = head->next;
}
void erase_back(){
	if(head->next == NULL){
		head = NULL;
	}else if(head != NULL && head->next != NULL){
		Node *cur = head;
		Node *prev = head;
		while(cur!= NULL){
			if(cur->next == NULL){
				prev->next = NULL;
				return;
			}
			prev = cur;
			cur = cur->next;
		}
	}
}
string front(){
	return head->val;
}

string back(){
	Node *cur = head;
	while(cur != NULL){
		if(cur->next == NULL){
			return cur->val;
		}
		cur = cur->next;
	}
}

void clear(){
	head = NULL;
}
  
int main()
{
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// cout << "hi" << endl;
   	}
    return 0;
}