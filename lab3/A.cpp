#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    queue<int> q;

    for(int i = 0; i < t; i++){
        int val; cin >> val;
        q.push(val);
    }
    
    int n, m;
    cin >> n >> m;
    vector<int> v[n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int val; cin >> val;
            v[i].push_back(val);
        }
    }


    while(!q.empty()){
        int c = q.front();
        q.pop();

        int row;
        vector <int> v1;
        for(int i = 0; i < n; i++){
            if(v[i][0] >= c && c >= v[i].back() || v[i][0] <= c && c <= v[i].back()){;
                row = i+1;
                v1 = v[i];
                break;
            }
        }

        bool boo = false;
        int l = 0; 
        int r = v1.size() - 1;
        int mid;
        int first, second;

        if(row % 2 != 0){
            while(l <= r){
                mid = l + (r-l)/2;
                if(c < v1[mid]){
                    l = mid + 1;
                }else if(c == v1[mid]){
                    boo = true;
                    second = mid;
                    first = row-1;
                    break;
                }else{
                    r = mid - 1;
                }
            }
        }
        else{
            while(l <= r){
                mid = l + (r-l)/2;
                if(c < v1[mid]){
                    r = mid - 1;
                }else if(c == v1[mid]){
                    boo = true;
                    second = mid;
                    first = row-1;
                    break;
                }else{
                    l = mid + 1;
                }
            }
        }
        if(boo){
            cout << first << " " << second << endl;
        }else{
            cout << -1 << endl;
        }
    }

    return 0;
}