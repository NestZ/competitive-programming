#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,x;
    cin >> n >> m;
    if(m <= 1)cout << 1;
    else{
        cout << min(n - m,m);
    }
    return 0;
}