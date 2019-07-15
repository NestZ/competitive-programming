#include<bits/stdc++.h>
using namespace std;

int main(){
    int a[4];
    int i = 3;
    for(int i = 0;i < 4;i++)cin >> a[i];
    sort(&a[0],&a[4]);
    while(i--){
        cout << a[3] - a[i] << ' ';
    }
    return 0;
}