#include <bits/stdc++.h>
using namespace std;

bool check(int x, int a[][4], int n, int k){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(x >= a[i][2] && x >= a[i][3])
            cnt++;
    }
    return cnt < k;
}

int main(){
    int n, k;
    cin >> n >> k;
    int a[n][4], l = 0, r = 1e9;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            cin >> a[i][j];
        }
    }
        
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        if(check(mid, a, n, k)){
            l = mid;
        }else{ 
            r = mid;
        }
    } 
    cout << l + 1 << endl;
      
    return 0;
}