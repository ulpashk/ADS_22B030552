#include <bits/stdc++.h>
using namespace std;
struct Deque{
    int r, l, a[100000];

    Deque(){
        r=50000;
        l=50000;
    }
    void push_back(int x){
        a[r]=x;
        r++;
    }
    void push_front(int x){
        l--;
        a[l]=x;
    }
    void pop_back(){
        if(r!=l){
            r--;
        } else {
            r=0;
            l=0;
        }
    }
    void pop_front(){
        if(l!=r){
            l++;
        } else {
            l=0;
            r=0;
        }
    }
    int back(){
        return a[r-1];
    }
    int front(){
        return a[l];
    }
    int size(){
        return r-l;
    }
    bool empty(){
        return r==l;
    }
};
int main(){
    Deque q;
    char s;
    int t;
    while(cin >> s){
        if(s=='+'){
            cin >> t;
            q.push_front(t);

        } else if(s=='-'){
            cin >> t;
            q.push_back(t);

        } else if(s=='*'){
            if(q.empty()==false){
                cout << q.back()+q.front() << endl;
                q.pop_front();
                q.pop_back();
            } else {
                cout << "error" << endl;
            }

        } else if(s=='!'){
            return 0;
        }
    }
    return 0;
}