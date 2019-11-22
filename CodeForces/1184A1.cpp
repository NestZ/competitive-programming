#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int r;
    long long int y = 1;
    cin >> r;
    long long int x = 1;
    while(y >= 1){
        y = (double((r - 1) / x) - x - 1) / 2.0;
        if(pow(x,2) + 2 * x * y + x + 1 == r && y >= 1){
            cout << x << ' ' << y;
            break;
        }
        x++;
    }
    if(y < 1)cout << "NO";
    return 0;
}