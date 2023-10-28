#include <bits/stdc++.h>
using namespace std;

int partition(string &str, int left, int right){
    int pivot = right;
    int i = left - 1;

    for(int j = left; j <= right-1; j++){
        if(str[j] < str[pivot]){
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[i + 1], str[pivot]);
    return (i + 1);
}

void quickSort(string &str, int left, int right){
    if(left < right){
        int pivot = partition(str, left, right);
        quickSort(str, left, pivot-1);
        quickSort(str, pivot+1, right);
    }
}

int main(){
    string a;
    cin >> a;
    quickSort(a, 0, a.length()-1);
    cout << a;
    return 0;
}
