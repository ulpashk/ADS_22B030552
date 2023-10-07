#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, q;
    cin >> n >> q;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int j = 0; j < q; j++){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(l1 <= a[i] && a[i] <= r1 || l2 <= a[i] && a[i] <= r2){
                cnt++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}
