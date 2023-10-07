#include <bits/stdc++.h> 
using namespace std;
int BinarySearch(int blocks[], int t, int size) {
    int l = 0;
    int r = size - 1;
    int result;
    while (l <= r) {
        int mid = l + (r-l) / 2;
        if(t <= blocks[mid]) {
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    return l;
}


int main () {
    int n, m, sum = 0;
    cin >> n >> m;
    int blocks[n];
    for(int i = 0; i < n; i++) {
        int a; 
        cin >> a;
        sum += a;
        blocks[i] = sum;
    }

    while(m--){
        int t;
        cin >> t;
        cout << BinarySearch(blocks, t, n) + 1 << endl;
    }

}