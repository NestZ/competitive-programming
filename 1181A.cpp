#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int S;
    long long int M;
    long long int price;
    long long int n;
    long long int mini;
    cin >> S >> M >> price;
    n = S / price + M / price;
    S = S % price;
    M = M % price;
    if(S + M >= price)mini = price - (S >= M ? S:M);
    else mini = 0;
    n += (S + M) / price;
    cout << n << " " << mini;
    return 0;
}