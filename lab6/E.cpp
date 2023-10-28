#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int left, int right){
    int pivot = a[right];
    int i = left-1;

    for(int j = left; j <= right-1; j++){
        if (a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return (i + 1);
}

void quickSort(int a[], int left, int right){
    if(left < right){
        int pivot = partition(a, left, right);
        quickSort(a, left, pivot-1);
        quickSort(a, pivot+1, right);
    }
}

int main(){
    int n; 
    cin >> n;
    int m; 
    cin >> m;
    int k[m][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> k[j][i];
        }
    }
    
    for(int i = 0; i < m; i++){
        quickSort(k[i], 0, n-1);
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            cout << k[j][i] << " ";
        }
        cout << endl;
    }

    return 0;
}
