#include <cmath>
#include <iostream>
using namespace std;

int partition(int a[], int left, int right){
    int pivot = a[right];
    int i = left - 1;

    for(int j = left; j <= right - 1; j++){
        if(a[j] < pivot){
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
        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

int main(){
    int n, m; 
    cin >> n >> m;
    int a[n], b[m];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    quickSort(a, 0, n - 1);
    quickSort(b, 0, m - 1);

    int i = 0;
    int j = 0;

    while(i != n && j != m){
        if(a[i] == b[j]){
            cout << b[j] << " ";
            i++;
            j++;
        }
        else if(a[i] < b[j]){
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
    }

    return 0;
}
