#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x,y;
    int ans = 0;
    string s;
    cin >> n >> x >> y >> s;
    for(int i = n - x;i < n;i++){
        if(s[i] == '1' && i != n - y - 1)ans++;
        else if(i == n - y - 1 && s[i] == '0')ans++;
    }
    cout << ans;
    return 0;
}