#include <bits/stdc++.h>
using namespace std;

int partition(vector<char> &v, int left, int right){
    int pivot = right; //index of the last element
    int i = left-1;

    for(int j = left; j <= right-1; j++){
        if(v[j] < v[pivot]){
            i++;
            swap(v[i], v[j]);
        }
    } 
    swap(v[i+1], v[pivot]);
    return (i+1);
}

void quickSort(vector<char> &v, int left, int right){
    if(left < right){
        int pivot = partition(v, left, right);
        quickSort(v, left, pivot-1);
        quickSort(v, pivot+1, right);
    }
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> vowel;
    vector<char> consonant;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u'){
            vowel.push_back(s[i]);
        }else{
            consonant.push_back(s[i]);
        }
    }

    quickSort(vowel, 0, vowel.size()-1);
    quickSort(consonant, 0, consonant.size()-1);

    for(int i = 0; i < vowel.size(); i++){
        cout << vowel[i];
    }

    for(int i = 0; i < consonant.size(); i++){
        cout << consonant[i];
    }
}
