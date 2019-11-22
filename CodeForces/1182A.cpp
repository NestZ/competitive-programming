#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n % 2 == 0)cout << int(pow(2,n / 2));
    else cout << 0;
    return 0;
}