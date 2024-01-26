#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v;
    vector<int> v1;

    for(int i = 0; i < n; i++){
        int val; cin >> val;
        v.push_back(val);
    }

    v[0] = -1;
    for(int i = 1; i < v.size(); i++){
        for(int j = 1; j <= i; j++){
            if(v[i] > v[i-j]){;
                v1.push_back(v[i-j]);
            }
        }
        v1.push_back(-1);
    }

    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << " ";
    }

    return 0;
}