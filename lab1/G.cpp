#include <bits/stdc++.h>
using namespace std;

bool isPrime[1000000];

void f(int n){
    for(int i=2; i<=n*n*n; i++){
        isPrime[i] = true;
    }
    if(n==1){
        cout << 3 << " ";
    }
    if(n==2){
        cout << 5 << " ";
    }
    isPrime[0] = isPrime[1] == false;
    

    for(int i=2; i<=n*n*n; i++){
        if(isPrime[i] == true){
            int j=i+i;
            while(j<=n*n*n){
                isPrime[j]=false;
                j+=i;
            }
        }
    }
}
int main(){
    int n; 
    cin >> n;
    // string s="", t="";
    deque<int> q1, q2;
    f(n);
    for(int i=2; i<=n*n*n; i++){
        if(isPrime[i]){
            q1.push_back(i);
            // cout << i << " ";
        }
    }
    // cout << endl;
    for(int i=1; i<q1.size(); i++){
        if(isPrime[i+1]){
            q2.push_back(q1[i]);
            // cout << q1[i] << " ";
        }
    }
    for(int i=0; i<q2.size(); i++){
        if(i==n){
            cout << q2[i-1] << endl;
        }
    }
    
    return 0;
}