#include <iostream>
#include <map>
using namespace std;
map <int, int> mp;
int cnt = 0;
void count(string t, string s){
    int n = t.size();
    int m = s.size();

    long long h[n];
    long long p[n];//power of 31

    long long q = 1e9 + 7;


    for(int i = 0; i < n; ++i){
        if(i == 0) p[i] = 1;
        else p[i] = (p[i - 1] * 31) % q;
    }

    for(int i = 0; i < n; ++i){
        h[i] = ((t[i] - int('a') + 1) * p[i]) % q;
        if(i > 0){
            h[i] = (h[i] + h[i - 1])  % q;
        }
    }


    long long h_s = 0;
    for(int i = 0; i < m; ++i){
        h_s = (h_s + ((s[i] - int('a') + 1) * p[i]) % q) % q;
    }


    for(int i = 0; i + m - 1 < n; i++){
        long long dif = h[i + m - 1];
        if(i > 0){
            dif = (dif - h[i-1] + q) % q;
        }
        if(dif == (h_s * p[i]) % q){
            mp[i]++;
            if(mp[i] > 1) cnt++;
        }
    }
}

int main(){
    string s1, s2, pattern;
    cin >> s1 >> s2 >> pattern;

    count(s1, pattern);
    count(s2, pattern);
    cout << cnt;
    return 0;
}