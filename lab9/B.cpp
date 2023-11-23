#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix_function(string s){  //massive lps
    vector<int> pr(s.length());
    for(int i = 1; i < s.length(); i++){ //skip 1st element because it's = 0;
        int j = pr[i - 1]; //1st element 
        while(j > 0 && s[i] != s[j]){ 
            j = pr[j - 1];
        } 
        if(s[i] == s[j]){ 
            j++;
            pr[i] = j;
        }
    }
    return pr;
}

bool kmp(string text, string pattern, int k){ //find pattern in text
    vector<int> solve;
    string concat = pattern + '%' + text;
    vector<int> pr = prefix_function(concat);
    for(int i = pattern.size() + 1; i < concat.size(); i++){ //begin from the beginning of the text
        if(pr[i] == pattern.size()){
            solve.push_back(i - 2 * pattern.size()); //find the index of the word which matches the pattern;
        }
    }

    if(solve.size() >= k){
        return true;
    }else{
        return false;
    }

}

int main(){
    string a;
    int k;
    cin >> a >> k;
    string b;
    cin >> b;

    if(kmp(b, a, k)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}