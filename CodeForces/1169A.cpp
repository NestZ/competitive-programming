#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,x,b,y;
    string ans;
    cin >> n >> a >> x >> b >> y;
    while(true){
        if(a == b){
            ans = "YES";
            break;
        }
        else if(a == x || b == y){
            ans = "NO";
            break;
        }
        if(a < n)a++;
        else a = 1;
        if(b > 1)b--;
        else b = n;
    }
    cout << ans;
    return 0;
}