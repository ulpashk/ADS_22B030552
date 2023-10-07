#include <bits/stdc++.h>
using namespace std;

int BinSearch(int a[], int t, int n, bool boo) {
    int l = 0; int r = n - 1;
    int mid; 
    while (l <= r) {
        mid = l + (r - l)/ 2;
        if (t == a[mid]) {
            return mid;
        }
        else if(t > a[mid]) {
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    if(boo){
        return l;
    } 
    return r;
}

bool Check(int l1, int r1, int l2, int r2) {
    int l = max(l1, l2);
    int r = min(r1, r2);
    if(l <= r){
        return false;
    }
    return true;
}
 
int main () {
    int n, q; 
    cin >> n >> q;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int arr[q][4];
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int cnt = 0;   
        for (int j = 0; j < 4; j++) {
            int l1 = arr[i][0];
            int r1 = arr[i][1];
            int l2 = arr[i][2];
            int r2 = arr[i][3];
            if(Check(l1, r1, l2, r2) == false) {
                int l = min (l1, l2);
                int r = max (r1, r2); 
                cnt = BinSearch(a, r, n, false) - BinSearch(a, l, n, true) + 1;
            }
            else{         
                cnt = BinSearch(a, r1, n, false) - BinSearch(a, l1, n, true) + 1;
                cnt += BinSearch(a, r2, n, false) - BinSearch(a, l2, n, true) + 1;
                }
            }
        cout << cnt << endl;
        }

    }