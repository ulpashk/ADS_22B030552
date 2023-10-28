#include <bits/stdc++.h>
using namespace std;

int partition(vector<char> &str, int left, int right){
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

void quickSort(vector<char> &str, int left, int right){
    if (left < right){
        int pivot = partition(str, left, right);
        quickSort(str, left, pivot - 1);
        quickSort(str, pivot + 1, right);
    }
}

int main(){
    int n; 
    cin >> n;
    vector<char> v;

    for(int i = 0; i < n; i++){
        char a;
        cin >> a;
        v.push_back(a);
    }

    char b;
    cin >> b;
    v.push_back(b);
    quickSort(v, 0, v.size()-1);


    for(int i = 0; i < v.size(); i++){
        if(v[i] > b){
            cout << v[i];
            return 0;
        }
    }
    // for(auto i : v){
    //     if(i>b){
    //         cout<<i;
    //         return 0;
    //     }
    // }
    cout << v[0];
    return 0;
}
