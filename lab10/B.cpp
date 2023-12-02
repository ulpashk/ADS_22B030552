#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    queue<int> q;
    vector<int> v[n]; //vector of vectors
    unordered_map <int, int> m, k; //2 maps called "m" and "k" //m-distance && k-did we visit the vertex before.
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < n; j++){
            cin >> arr[i][j]; 
            if(arr[i][j] == 1){
                v[i].push_back(j); //to know the neighbours of the i vertex (i and j are edges)
            }
        }
    }

    int x, y;
    cin >> x >> y;
    x -= 1;
    y -= 1;
    q.push(x);
    m[x] = 0;

    while(!q.empty()){
            int cur = q.front();
            k[cur] = 1; //we visited the vertex
            q.pop();
            for(auto i: v[cur]){ //kuda by nam poiti
                    if(k[i] != 1){
                        q.push(i); 
                        m[i] = m[cur] + 1; //distance
                        if(i == y){
                            cout << m[i]; //short path from x to y;
                            return 0;
                        }
                    }
                }
    }

    cout << -1;

    return 0;
}
