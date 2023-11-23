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

bool kmp(string text, string pattern){ //find pattern in text
    vector<int> solve;
    string concat = pattern + '%' + text;
    vector<int> pr = prefix_function(concat);
    for(int i = pattern.size() + 1; i < concat.size(); i++){ //begin from the beginning of the text
        if(pr[i] == pattern.size()){
            solve.push_back(i - 2 * pattern.size()); //find the index of the word which matches the pattern
            return true;
        }
    }
        return false; //povtorenii ne bylo
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    string text = "";
    int cnt = 0;

    if(a.size() < b.size()){ 
        while(text.size() < b.size()){
            text += a;
            cnt++;
        }
        if(kmp(text, b)){
            cout << cnt << endl;
            return 0;
        }else{
            cnt++;
            text += a;
            if(kmp(text, b)){
                cout << cnt << endl;
                return 0;
            }
            else cout << -1 << endl; 
            return 0;
        }
    }else{
        if(kmp(a, b)){
            cout << 1;
            return 0;
        }else{
            cout << -1 << endl; 
            return 0;
        }
    }

    return 0;
}