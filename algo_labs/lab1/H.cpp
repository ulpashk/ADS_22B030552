#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i<=sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    if(isPrime(n)){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 0;
}