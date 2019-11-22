#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int ans = 0;
    string s;
    cin >> n >> s;
    for(int i = 0;i < n;i++){
        if(s[i] == '-')ans--;
        else ans++;
        if(ans < 0)ans = 0;
    }
    cout << ans;
    return 0;
}